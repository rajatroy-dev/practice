/**
 * How to convert DateTime to ISODateTime or string to double
 * or DateTime to double, etc?
 * 
 * Refer to 11.json for data.
 */

`use sample_airbnb;`

db.listingsAndReviews.aggregate([
    {
        $project: {
            "review": {
                $toDouble: "$first_review"
            }
        }
    }
]);

// OR

db.listingsAndReviews.aggregate([
    {
        $project: {
            "review": {
                $convert: {
                    input: "$first_review",
                    to: "double"
                }
            }
        }
    }
]);