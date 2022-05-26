/**
 * In the collection of students, use `$push` to:
 * 
 * - to add multiple documents to the quizzes array of id `5`.
 * - sort all the elements of the modified quizzes array by the score field in descending order.
 * - keep only the first three sorted elements of the quizzes.
 */

db.students.updateOne({ "_id": 5 }, {
    $push: {
        "quizzes": {
            $each: [
                {
                    "wk": 5,
                    "score": 19
                },
                {
                    "wk": 6,
                    "score": 20
                }
            ],
            $sort: {
                "score": -1,
            },
            $slice: 3,
        }
    }
});