let a = 4;

let promise = new Promise((resolve, reject) => {
    if (a < 5) {
        resolve('Valid!');
    } else {
        reject('Error!');
    }
});

promise.then(res => console.log(res)).catch(err => console.log(err));