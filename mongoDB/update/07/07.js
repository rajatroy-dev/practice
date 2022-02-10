/**
 * Remove 2 elements from an array.
 * 
 * Refer to 07.json for data.
 */

 `use sample_mflix;`

 db.movies.updateOne({ _id: ObjectId('573a1390f29313caabcd4803') }, {
     $pull: {
         "genres": {
             $in: ["Short", "Comedy"]
         }
     }
 });