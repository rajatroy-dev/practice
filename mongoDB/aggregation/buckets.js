/**
 * Group data into range and display output.
 * Refer to buckets.json for data.
 */

`use sample_mflix;`

// $bucket
db.movies.aggregate([
    {
        groupBy: "$year",
        boundaries: [1880, 1890, 1900, 1910, 1920],
        default: "Other",
        output: {
            "count": { $sum: 1 },
            "runtime": { $avg: "$runtime" },
            /**
             * Doing the below will only produce one bucket
             * "movie": {
             *      $push: {
             *          title: "$title"
             *      }
             * }
             */
        }
    }
]);

// $bucketAuto
db.movies.aggregate([
    {
        groupBy: "$year",
        buckets: 10,
        output: {
            "count": { $sum: 1 },
            "runtime": { $avg: "$runtime" }
        }
    }
]);