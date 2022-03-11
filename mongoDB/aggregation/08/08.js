/**
 * Find the first sale date of each payment method.
 * 
 * Refer to 08.json for data.
 */

`use sample_supplies;`

db.sales.aggregate([
    { $sort: { purchaseMethod: 1, saleDate: 1 } },
    {
        $group: {
            _id: "$purchaseMethod",
            "firstSaleOfPurchaseMethod": {
                $first: "$saleDate"
            }
        }
    }
]);