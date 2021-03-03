#include <iostream>
#include "sudokusolver.h"


int main()
{
    //std::cout << "Hello World!" << endl;

    SudokuSolver sudoku;
//    sudoku.setValueFixed(1, 1, 1);
//    sudoku.setValueFixed(1, 7, 4);
//    sudoku.setValueFixed(4, 1, 2);
//    sudoku.setValueFixed(7, 1, 3);

//    sudoku.setValueFixed(0, 0, 1);
//    sudoku.setValueFixed(0, 1, 4);
//    sudoku.setValueFixed(0, 2, 3);
//    sudoku.setValueFixed(0, 3, 2);
//    sudoku.setValueFixed(0, 4, 9);

    sudoku.setValueFixed(0, 0, 1);
    sudoku.setValueFixed(1, 1, 3);
    sudoku.setValueFixed(2, 2, 5);
    sudoku.setValueFixed(3, 3, 7);
    //sudoku.setValueFixed(4, 4, 9);


    sudoku.findSolution(0, 0);
    sudoku.print();


    return 0;
}
