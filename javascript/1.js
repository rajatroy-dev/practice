function mul(a) {
    return function (b) {
        return function (c) {
            return a * b * c;
        }
    }
}

console.log(mul(2)(4)(6)); // 48

const arrowMul = a => {
    return b => {
        return c => {
            return a * b * c;
        }
    }
}

console.log(mul(2)(4)(6)); // 48