use("CrudDb")

db.createCollection("courses")
db.courses.insertOne({
        name: "harrys web dev free course",
        price: 0,
        assignments: 12,
        projects :45
})

db.courses.insertMany