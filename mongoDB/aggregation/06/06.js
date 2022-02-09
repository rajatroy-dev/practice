/**
 * Using aggregation project transactions with amount greater than 9500.
 * 
 * Refer to 06.json for data.
 */

`use sample_analytics;`

db.transactions.aggregate([
    {
        "transactions": {
            $filter: {
                input: "$transactions",
                as: "txn",
                cond: {
                    $gt: ["$$txn.amount", 9500]
                }
            }
        }
    }
]);