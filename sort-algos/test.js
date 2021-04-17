//Make an array with random variables
let numOfElems = 100;
let maxVal = 600;
let arr = [];

//Variables for bubble sort
//Functions to sort the array
function swap(arr, idx1, idx2){
    const temp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = temp;
}

let outerIdx = 0;
let innerIdx = 0;


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

//displayBarChart(arr, numOfElems, maxVal);


function selectAlgo(option){
    if (option === 'bubble'){
        outerIdx = 0;
        innerIdx = 0;
        window.requestAnimationFrame(bubble);
    }
    //other options go here
}

//function sort(arr, numOfElems, outerIdx, innerIdx){ //Doesn't work
function bubble(){
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

        //Clear child elements and redraw
        document.getElementById('viz-area').innerHTML = '';
        displayBarChart(arr, numOfElems, maxVal);

        window.requestAnimationFrame(bubble);
    }
}
