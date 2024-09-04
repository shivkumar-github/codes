use('sigmaDatabase');

// Insert a few documents into the sales collection.
db.getCollection('sales').insertMany([
    {
        "name": "Python",
        "Price": 15000,
        "Instructor": "Lisa"
    },
    {
        "name": "Web Development",
        "Price": 25000,
        "Instructor": "Chris"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    },
    {
        "name": "Data Science",
        "Price": 30000,
        "Instructor": "Amelia"
    }
]
);

// Print a message to the output window.
console.log(`done inserting data`);