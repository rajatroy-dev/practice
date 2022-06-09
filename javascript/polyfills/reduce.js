/**
 * reduce is a function of array.
 * It takes a callback function as input.
 * It then processes each element of the array and combining the vales using the provided function.
 * It returns the final value after combining all the elements of the array.
 */

let a = [1, 2, 3, 4, 5, 6, 7, 8, 9];
let b = a.reduce((previousValue, currentValue, currentIndex, array) => {
    return previousValue + currentValue
}, 1);
console.log(b);

Array.prototype.reducePolyfill = function (callback, initialValue, thisArg) {
    let accumulator = initialValue;
    thisArg = thisArg ?? this;

    for (let i = 0; i < thisArg.length; i++) {
        accumulator = accumulator ? callback(accumulator, thisArg[i], i, thisArg) : thisArg[i];
    }

    return accumulator;
};

let c = a.reducePolyfill((previousValue, currentValue) => previousValue + currentValue, 1);
console.log(c);
