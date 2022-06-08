// Remove duplicates

const arr = [1, 1, 2, 2, 3, 4, 5, 6, 6, 6, 6, 6, 6];
const result = [];

for (const item of arr) {
    if (result.indexOf(item) == -1) {
        result.push(item);
    }
}

console.log(result);