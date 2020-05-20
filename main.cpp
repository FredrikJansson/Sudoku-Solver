#include <iostream>
#include "SudokuSolver.h"

int main() {
    /* Medium grid from sudoku.com */
    std::vector<std::vector<int>> medGrid = {{0, 0, 0, 0, 6, 4, 0, 0, 3},
                                             {0, 3, 0, 0, 0, 0, 1, 0, 0},
                                             {0, 8, 5, 0, 0, 0, 0, 0, 7},
                                             {0, 5, 1, 3, 0, 9, 7, 0, 2},
                                             {0, 7, 0, 2, 0, 0, 8, 0, 0},
                                             {9, 2, 0, 0, 7, 0, 3, 5, 0},
                                             {0, 0, 0, 4, 2, 0, 0, 0, 1},
                                             {3, 0, 0, 0, 1, 0, 0, 0, 0},
                                             {0, 9, 0, 6, 8, 0, 0, 0, 0}};

    SudokuSolver ss(medGrid);
    ss.printGrid();
    ss.solve();
}
