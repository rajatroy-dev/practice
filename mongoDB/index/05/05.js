/**
 * While searching for text in multiple fields, 
 * how do I prioritize one field over others?
 * 
 * Refer to 05.json for data.
 */

`use sample_airbnb;`

db.listingAndReviews.createIndex({
    "name": "text",
    "summary": "text"
}, { weights: { "name": 2, "summary": 1 } });
