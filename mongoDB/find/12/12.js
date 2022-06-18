/**
 * Two ways to find documents with $and operator.
 * 
 * Refer to 12.json for data.
 */

`use sample_training;`

db.posts.find({
    $and: [
        { "author": "machine" },
        { "title": "Bill of Rights" }
    ]
});

db.posts.find({
    "author": "machine",
    "title": "Bill of Rights"
});