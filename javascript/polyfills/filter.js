/**
 * filter is a function of array.
 * It takes a callback function as input.
 * It then processes each element of the array using the provided function.
 * And returns a new array with the filtered elements.
 */

let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0];

// filter - callback(element, index, array), thisArgs
Array.prototype.filterPolyfill = function (callback, thisArgs) {
    thisArgs = thisArgs ?? this;
    let result = [];

    for (let i = 0; i < thisArgs.length; i++) {
        if (callback(thisArgs[i], i, thisArgs)) {
            result.push(thisArgs[i]);
        }
    }

    return result;
}

console.log(arr.filter(e => e % 2 == 0));
console.log(arr.filterPolyfill(e => e % 2 == 0));