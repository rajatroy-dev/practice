/**
 * map is a function of array.
 * It takes a callback function as input.
 * It then processes each element of the array using the provided function.
 * And returns a new array with the new elements.
 */

let a = [1, 2, 3, 4, 5, 6, 7, 8, 9];

let b = a.map(e => e * 2);
console.log(b);

Array.prototype.mapPolyfill = function (callback) {
    thisArgs = thisArgs ?? this;
    let result = [];

    for (let i = 0; i < thisArgs.length; i++) {
        result.push(callback(thisArgs[i], i, thisArgs));
    }

    return result;
}

let c = a.mapPolyfill(e => e * 2);
console.log(c);