/**
 * Aggregate and find the maximum transaction amount.
 * 
 * Refer to 07.json for data.
 */

`use sample_analytics`;

db.transactions.aggregate([
    { $unwind: { path: "$transactions", includeArrayIndex: 'string', preserveNullAndEmptyArrays: false } },
    { $project: { "amount": "$transactions.amount" } },
    { $sort: { "amount": -1 } },
    { $group: { _id: "$_id", maxAmount: { $max: "$amount" } } },
    { $sort: { maxAmount: -1 } }
]);