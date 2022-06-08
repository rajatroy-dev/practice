for (let i = 0; i < 5; i++) {
    setTimeout(() => console.log(i), i * 100); // 0 1 2 3 4
}

for (var i = 0; i < 5; i++) {
    setTimeout(() => console.log(i), i * 100); // 5 5 5 5 5
}

// https://stackoverflow.com/a/31286220