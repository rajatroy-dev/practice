/**
 * Project the elements of an array in a document by skipping first 2 elements and limit the query to 3.
 * 
 * Refer to 13.json for data.
 */

`use sample_supplies`;

db.sales.find(
    { _id: ObjectId("5bd761dcae323e45a93ccfe8") },
    { items: { $slice: [2, 3] } },
);