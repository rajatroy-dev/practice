/**
 * Find a place that intersects with a given polygon.
 * 
 * Refer to 03.json for data.
 */

`use sample_geospatial`;

db.shipwrecks.findOne({
    "coordinates": {
        $geoIntersects: {
            $geometry: {
                type: "Polygon",
                coordinates: [[
                    [-134.649574, 56.253975],
                    [-134.649542, 56.253367],
                    [-134.650894, 56.253414],
                    [-134.650840, 56.254124],
                    [-134.649574, 56.253975]
                ]]
            }
        }
    }
});