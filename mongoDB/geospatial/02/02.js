/**
 * Find a point within a max and min distance of a point.
 * 
 * Refer to 02.json for data.
 */

`use sample_geospatial`;

db.shipwrecks.find({
    "coordinates": {
        $near: {
            $geometry: {
                type: "Point",
                coordinates: [-79.0000000, 9.0000000]
            },
            $maxDistance: 100000,
            $minDistance: 1
        }
    }
});