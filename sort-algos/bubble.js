//Make an array with random variables
let numOfElems = 100;
let maxVal = 600;
let arr = [];

for (let i = 0; i < numOfElems; i++) {
    const num = Math.floor(Math.random() * maxVal);
    arr.push(num); 
}