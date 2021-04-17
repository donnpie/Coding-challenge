//Make an array with random variables
let numOfElems = 100;
let maxVal = 600;
let arr = [];

//console.log(arr);
//Add event listener to button
const btn = document.getElementById('btn');
btn.addEventListener('click', () => {
    //console.log('Test');
    document.getElementById('viz-area').innerHTML = '';
    arr =[];
    for (let i = 0; i < numOfElems; i++) {
        const num = Math.floor(Math.random() * maxVal);
        arr.push(num); 
    }
    //console.log(arr);
    let getAlgo = document.getElementById('algo-option').selectedOptions[0].value;
    //console.log(getAlgo); // This will output the value selected.
    ///Call select algo with correct 
    selectAlgo(getAlgo);

});

//Function to create bar-group elements and add to viz-group
function displayBarChart(arr, numOfElems, maxVal) {
    const vizArea = document.getElementById('viz-area');

    for (let i = 0; i < numOfElems; i++) {
        const barGroup = document.createElement('div');
        barGroup.classList.add('bar-group');

        const blank = document.createElement('div');
        blank.style.height = maxVal+"px";
        blank.classList.add('blank');
        barGroup.appendChild(blank);

        const bar = document.createElement('div');
        bar.classList.add('bar');
        bar.style.height = arr[i]+"px";
        barGroup.appendChild(bar);

        vizArea.appendChild(barGroup);
    }
}


let outerIdx = 0;
let innerIdx = 0;
let i;
let j;
let idxOfSmallest;

function selectAlgo(option){
    outerIdx = 0;
    innerIdx = 0;
    if (option === 'bubble'){
        console.log('Bubble sort');
        window.requestAnimationFrame(bubbleSort);
    }
    i = 1;
    j = i;
    if (option === 'insert'){
        console.log('Insertion sort');
        window.requestAnimationFrame(insertionSort);
    }
    i = 0; 
    j = i + 1; 
    idxOfSmallest = i;
    if (option === 'select'){
        console.log('Selection sort');
        window.requestAnimationFrame(selectionSort);
    }
    //other options go here
}

//-----------------Sort algos--------------------------------

//bubble sort
function bubbleSort(){
    if (outerIdx < numOfElems - 1) {
        if (innerIdx < numOfElems - 1) {
            if (arr[innerIdx] > arr[innerIdx+1]) {
                swap(arr, innerIdx, innerIdx+1);
                //console.log("Made swop");
            } else {
                //console.log("No swop");
            }
            //console.log("Inner: " + innerIdx);
            innerIdx+=1;
        } else {
            //console.log("Outer: " +outerIdx);
            innerIdx = 0;
            outerIdx+=1;
        }

        redraw(arr, numOfElems, maxVal)
        window.requestAnimationFrame(bubbleSort);
    }
}

//Insertion sort
function insertionSort(){
    if (i < arr.length) {
        //console.log('i:', i);
        //console.log('arr.length:', arr.length);
        //console.log('j:', j);
        if (j > 0) {
            if (arr[j] < arr[j-1]) {
                //Do swap
                //console.log('Swapping...')
                swap(arr, j, j-1);
            } 
            j--;
        } else {
            i++;
            j = i; 
        }
        
        redraw(arr, numOfElems, maxVal)
        window.requestAnimationFrame(insertionSort);
    }
}

//Selection sort
function selectionSort(){

    if (i < arr.length - 1) {
        console.log('i:', i);
        console.log('idxOfSmallest:', idxOfSmallest);
        console.log('j:', j);
        if (j < arr.length) {
            if (arr[j] < arr[idxOfSmallest]) {
                idxOfSmallest = j;
                console.log('idxOfSmallest:', idxOfSmallest);
            }
            j++;
        } else {
            swap(arr, i, idxOfSmallest);
            i++;
            idxOfSmallest = i;
            j = i + 1;
        }
        redraw(arr, numOfElems, maxVal)
        window.requestAnimationFrame(selectionSort);
    }
}






//---------------------Helper methods----------------------
function swap(arr, idx1, idx2){
    const temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

function redraw(arr, numOfElems, maxVal){
    //Clear child elements and redraw
    document.getElementById('viz-area').innerHTML = '';
    displayBarChart(arr, numOfElems, maxVal);
}