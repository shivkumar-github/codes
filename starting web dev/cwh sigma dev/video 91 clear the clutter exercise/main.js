const express = require('express')
const app = express()
const port = 3000;
const fs = require('fs');
const path = require('path')

const dirpath = "C:\\Users\\shivk\\OneDrive\\Documents\\code with harry backend folder\\video 91 clear the clutter exercise\\directory"

// Reading the contents of the directory
let files = fs.readdirSync(dirpath)

for (const item of files) {
        let lastIndex = item.lastIndexOf(".")
        if (lastIndex == -1) continue;
        let extentionName = item.toString().slice(lastIndex + 1);
        let fileName = item.toString();
        let extfolderpath = dirpath + "\\" + extentionName;
        let destinationPath = path.join(extfolderpath, fileName)

        if (!fs.existsSync(extfolderpath)) {
                fs.mkdirSync(extfolderpath);
        }
        // why not to concatenate instead of path.join()// Advantages of path.join:
        // Cross-Platform Compatibility: path.join automatically uses the appropriate directory separator (/ for Unix-based systems, \ for Windows) based on the operating system, ensuring the code works correctly on different platforms.
        // Handles Trailing/Leading Slashes: It takes care of any extra slashes in the paths, preventing issues caused by incorrect concatenation.
        // Readability and Maintainability: It makes the code more readable and explicit about its intention to create a valid file path.
        let sourcePath = path.join(dirpath, fileName)
        fs.rename(sourcePath, destinationPath, (err) => {
                if (err) {
                        console.error('Error while moving the file: ', err);
                }
                else {
                        console.log("file moved successfully.")
                }
        })
}

app.listen(port, () => {
        console.log(`Example app listening on port ${port}`)
})