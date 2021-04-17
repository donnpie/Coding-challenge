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

//Insertion sort algo - Original
let iterCount = 0
// for (let i = 1; i < arr.length; i++) {
//     for (let j = i; j > 0; j--) {
//         if (arr[j] < arr[j-1]) {
//             //Do swap
//             swap(arr, j, j-1);
//             iterCount++;
//         } else { 
//             iterCount++;
//             break; 
//         }
//     }
// }

//Insertion sort algo - For loops converted to while loops
// let i = 1;
// while (i < arr.length) {
//     let j = i; 
//     while (j > 0) {
//         if (arr[j] < arr[j-1]) {
//             //Do swap
//             swap(arr, j, j-1);
//             iterCount++;
//         } else { 
//             iterCount++;
//             break; 
//         }
//         j--;
//     }
//     i++;
// }

//Insertion sort algo - while loops converted to ifs
let i = 1;
let j;
if (i < arr.length) {
    j = i; 
    if (j > 0) {
        if (arr[j] < arr[j-1]) {
            //Do swap
            swap(arr, j, j-1);
            iterCount++;
        } else { 
            iterCount++;
            break; 
        }
        j--;
    }
    i++;
}


//After
console.log(arr);
console.log('iterations:', iterCount);

//Functions to sort the array
function swap(arr, idx1, idx2){
    const temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}
