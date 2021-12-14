/**
 * Update the 'minimum_nights' field to a new value only if it is less than the current value.
 * Update the 'maximum_nights' field to a new value only if it is more than the current value.
 * 
 * Refer to 03.json for data.
 */

`use sample_airbnb`;

db.listingsAndReviews.updateOne({ "_id": "10006546" },
    {
        $min: { minimum_nights: 1 }
    });

db.listingsAndReviews.updateOne({ "_id": "10006546" },
    {
        $max: { maximum_nights: 31 }
    });