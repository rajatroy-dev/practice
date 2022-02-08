/**
 * Remove an element from transactions whose amount is 7514 and symbol is "adbe".
 * 
 * Refer to 08.json for data.
 */

`use sample_analytics`;

db.transactions.updateOne({}, {
    $pull: {
        "transactions": {
            "amount": 7514,
            "symbol": "adbe"
        }
    }
}, { multi: true });