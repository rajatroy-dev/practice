/**
 * Find documents in a collection that contains a specified array element.
 * 
 * Refer to 10.json for data.
 */

`use sample_training;`

db.posts.findMany({
    "tags": {
        $in: ["office"]
    }
});