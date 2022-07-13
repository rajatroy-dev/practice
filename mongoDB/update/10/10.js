/**
 * Increment / Decrement minimum_nights value.
 * 
 * Refer to 10.json for data.
 */


`use sample_airbnb;`

// Increment
db.listingsAndReviews.updateOne({ "_id": "10006546" }, {
    $inc: {
        minimum_nights: -1
    }
});

// Decrement
db.listingsAndReviews.updateOne({ "_id": "10006546" }, {
    $inc: {
        minimum_nights: -1
    }
});