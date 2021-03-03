#include "nqueensproblem.h"
#include <math.h> //abs
#include <iostream>
#include <string>

std::string space(int num)
//Returns the number of tabs indicated by num
{
    std::string s = "";
    for (int i =0; i < num; i++)
    {
        s = s + "\t";
    }
    return s;
}

nQueensProblem::nQueensProblem(int columns, nQueensSolution *sol) :
    _columnCount(columns), _rowCount(columns), _sol(sol), _watchDog(0)
{

}

//version 1
//void nQueensProblem::placeQueen(int column)
//{
////    std::cout << space(column) << "calling placeQueen with column " << column << "\n";
////    if (_watchDog < 113)
////    {
////        _watchDog++;
////    }
////    else {
////        std::cout << space(column) << "Watch dog has timed out\n";
////        _sol->printSolution();
////        exit(-2);
////    }
////    if (column == _columnCount)
////    {
////        std::cout << space(column)  << "column is" << column << "\n";
////        exit(-1);
////    }
//    for (int r = 0; r < _rowCount; r++)
//    {
//        std::cout << space(column)  << "Checking row " << r << "\n";
//        if (isSafe(r, column))
//        {
//            std::cout << space(column)  << "Queen placed in (" << r << ", " << column << ")\n";
//            _sol->setValue(r, column); //Place queen in cell (r, column)
//            if (column >= _columnCount - 1) //Last column done
//            {
//                std::cout << space(column)  << "All Done""\n";
//                _sol->printSolution();
//                exit(-3);
//            }
//            else {
//                placeQueen(column + 1); //move on to the next column
//            }
//        }
//        else {
//            //std::cout << " is not safe" << "\n";
//        }
//    }
//}

//version 2
bool nQueensProblem::placeQueen(int column)
{
    bool next = false;
    for (int r = 0; r < _rowCount; r++)
    {
        std::cout << space(column)  << "Checking row " << r << "\n";
        if (isSafe(r, column))
        {
            std::cout << space(column)  << "Queen placed in (" << r << ", " << column << ")\n";
            _sol->setValue(r, column); //Place queen in cell (r, column)
            if (column == _columnCount - 1) //Last column done
            {
                std::cout << space(column)  << "All Done""\n";
                _sol->printSolution();
                return true;
                //exit(-3);
            }
            else {
                next = placeQueen(column + 1); //move on to the next column
            }
            if (next)
                return true;
        }
    }
    return false;
}


bool nQueensProblem::inSameDiagonal(int r, int c)
{
    std::cout << space(c)  << "calling inSameDiagonal with row " << r << " and column " << c << "\n";
    //int colCount = _sol->getColumnCount();
    //for (int col = 0; col < colCount; col++)
    for (int col = 0; col < c; col++)
    {
        //std::cout << space(c)  << "Checking col " << col << "\n";
        if (col != c)
        {
            int rowDiff = abs(_sol->getValue(col) - r);
            int colDiff = abs(col - c);
            //std::cout << space(c)  << "Row diff: " << rowDiff << " Col diff: " << colDiff << "\n";
            if (rowDiff == colDiff)
            {
                std::cout << space(c) << "...not safe\n";
                return true;
            }
        }
    }
    std::cout << space(c) << "...safe\n";
    return false;
}

//Version 1
//bool nQueensProblem::inSameRow(int r, int c)
//{
//    std::cout << space(c)  << "calling inSameRow with column " << c;
//    int colCount = _sol->getColumnCount();
//    for (int col = 0; col < colCount; col++)
//    //for (int col = 0; col < c; col++)
//    {
//        if (col != c)
//        {
//            if (_sol->getValue(col) == r)
//            {
//                std::cout << "...not safe\n";
//                return true;
//            }
//        }
//    }
//    std::cout << "...safe\n";
//    return false;
//}

//Version 2
bool nQueensProblem::inSameRow(int r, int c)
{
    std::cout << space(c)  << "calling inSameRow with column " << c;
    if (c == 0)
    {
        _sol->setValue(-100, c); //if in the first column, reset the row value
    }
    //int colCount = _sol->getColumnCount();
    //for (int col = 0; col < colCount; col++)
    for (int col = 0; col < c; col++)
    {
        if (_sol->getValue(col) == r)
        {
            std::cout << "...not safe\n";
            return true;
        }

    }
    std::cout << "...safe\n";
    return false;
}

//bool nQueensProblem::inSameColumn(int c)
//{
//    std::cout << "calling inSameColumn with column " << c;
//    if (_sol->getValue(c) != -100)
//    {
//        //if the column is empty the value will be -1
//        std::cout << "...not safe\n";
//        return true;
//    }
//    std::cout << "...safe\n";
//    return false;
//}

bool nQueensProblem::isSafe(int r, int c)
{
    //std::cout << space(c)  << "calling isSafe with column " << c << "\n";
    //bool test = (!inSameDiagonal(r, c) && !inSameRow(r, c) && !inSameColumn(c));
    bool test = (!inSameDiagonal(r, c) && !inSameRow(r, c));
    if (test)
    {
        std::cout << space(c)  << "...safe\n";
    }
    else std::cout << space(c)  << "...not safe\n";
    return test;
}
