// Find occurence

const arr = [1, 1, 2, 2, 3, 3, 4, 4, 5, 5, 5, 5];
const count = {};

for (const item of arr) {
    if (count[item]) {
        count[item] += 1;
    } else {
        count[item] = 1;
    }
}

console.log(count);