/**
 * Find all the documents in which the grades array contain atleast 1 element which is
 * greater than 85. Then, project the first element of that array which is greater
 * than 85.
 * 
 * Refer to the data in 01.json
 */

`use practice;`

db.sem_grades_arr.find(
    { "grades": { $gt: 85 } },
    { "grades.$": 1 }
);