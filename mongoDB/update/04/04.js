/**
 * How do we change "InvestmentStock" to "Stock" in the products array in all documents?
 * 
 * Refer to 04.json for data.
 */

`use sample_analytics`;

db.accounts.updateMany({}, {
    $pull: { "products.$[el]": "Stock" }
}, {
    multi: true,
    arrayFilters: [
        { el: "InvestmentStock" }
    ]
});