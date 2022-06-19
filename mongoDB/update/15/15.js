/**
 * While tryig to update a document, create a new
 * document if it is not found.
 * 
 * Refer to 15.json for data.
 */

`use sample_trainings;`

db.zips.updateOne(
    {
        "city": "El Paso",
        "zip": "79930",
        "loc": {
            "y": 31.784331,
            "x": -106.464916
        },
        "pop": 2224,
        "state": "TX"
    },
    { upsert: true }
);