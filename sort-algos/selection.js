//Make an array with random variables
let numOfElems = 20;
let maxVal = 600;
let arr = [];

let isRandom = false;
if (isRandom) {
    for (let i = 0; i < numOfElems; i++) {
        const num = Math.floor(Math.random() * maxVal);
        arr.push(num); 
    }
}
else {
    arr = [64, 531, 316, 599,  73,  49,
        329, 521, 324, 509, 276, 519,
         99, 235, 256, 142, 206, 268,
        597, 474];
}

//Before
console.log(arr);

//Selection sort algo - Original
// let idxOfSmallest;
// for (let i = 0; i < arr.length - 1 ; i++) {
//     idxOfSmallest = i;
//     for (let j = i + 1; j < arr.length ; j++) {
//         if (arr[j] < arr[idxOfSmallest]) {
//             idxOfSmallest = j;
//         }
//     }
//     swap(arr, i, idxOfSmallest);
// }

//Selection sort algo - For loops converted to while loops
// let idxOfSmallest;
// let i = 0; 
// while (i < arr.length - 1) {
//     idxOfSmallest = i;
//     let j = i + 1; 
//     while (j < arr.length) {
//         if (arr[j] < arr[idxOfSmallest]) {
//             idxOfSmallest = j;
//         }
//         j++;
//     }
//     swap(arr, i, idxOfSmallest);
//     i++;
// }

//Selection sort algo - while loops converted to ifs
let idxOfSmallest;
let i = 0; 
let j = i + 1; 
if (i < arr.length - 1) {
    idxOfSmallest = i;
    if (j < arr.length) {
        if (arr[j] < arr[idxOfSmallest]) {
            idxOfSmallest = j;
        }
        j++;
    } else {
        i++;
        j = i + 1;
    }
    swap(arr, i, idxOfSmallest);
}

//After
console.log(arr);
//console.log('iterations:', iterCount);

//Functions to sort the array
function swap(arr, idx1, idx2){
    const temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}