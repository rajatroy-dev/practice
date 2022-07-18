/**
 * Aggregate transactions to find the total buy/sell count and sort the count in ascensding order.
 * 
 * Refer to 12.json for data.
 */

`use sample_analytics`;

db.transactions.aggregate([
    {
        $unwind: {
            path: "$transactions"
        }
    },
    {
        $group: {
            _id: "$transactions.transaction_code",
            "transaction_code_count": {
                "$sum": 1
            }
        }
    },
    {
        $sort: {
            "transaction_code_count": 1
        }
    }
]);