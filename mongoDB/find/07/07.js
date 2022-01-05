/**
 * What is the difference between finding documents in a collection
 * with a specified element in the criteria and the exact array with
 * the given elements?
 */

`use sample_analytics`;

db.customers.find({
    "accounts": 371138
});

db.customers.find({
    "accounts": [116508]
});