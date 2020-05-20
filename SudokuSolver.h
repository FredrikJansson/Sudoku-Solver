//
// Created by Fredrik on 2020-05-20.
//

#ifndef SUDOKU_SUDOKUSOLVER_H
#define SUDOKU_SUDOKUSOLVER_H

#include <vector>
#include <iostream>
#include <math.h>

class SudokuSolver {
private:
    int gridSize = 9;
    int defaultValue = 0;
    bool gridValid = false;
    std::vector<std::vector<int>> grid;

    bool isPossible(int, int, int);

public:
    SudokuSolver(std::vector<std::vector<int>>&, int);
    void printGrid();
    void solve(bool);
};

SudokuSolver::SudokuSolver(std::vector<std::vector<int>>& inGrid, int optGridSize = 9) {
    try {
        this->gridSize = optGridSize;
        for(int i = 0; i < this->gridSize; i++) {
            if(inGrid[i].size() != this->gridSize)
                throw std::invalid_argument("In grid is not valid.");
        }
        this->grid = inGrid;
        this->gridValid = true;
    } catch (...) {
        std::cout << "In grid is not valid." << std::endl;
        exit(1);
    }
}

void SudokuSolver::printGrid() {
    if(this->gridValid) {
        for(int i = 0; i < this->gridSize; i++) {
            for(int j = 0; j < this->gridSize; j++) {
                std::cout << "[" << this->grid[i][j] << "]";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}

bool SudokuSolver::isPossible(int x, int y, int n) {
    /* Check Y-axis. */
    for(int i = 0; i < this->gridSize; i++)
        if(this->grid[i][x] == n)
            return false;
    /* Check X-axis. */
    for(int i = 0; i < this->gridSize; i++)
        if(this->grid[y][i] == n)
            return false;
    /* Check 3x3 grid. */
    int x0 = floor(x / 3) * 3;
    int y0 = floor(y / 3) * 3;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(this->grid[y0 + i][x0 + j] == n)
                return false;
    return true;
}

void SudokuSolver::solve(bool printAfter = false) {
    for(int y = 0; y < this->gridSize; y++) {
        for(int x = 0; x < this->gridSize; x++) {
            if(this->grid[y][x] == this->defaultValue) {
                for(int i = 1; i < 10; i++) {
                    if(isPossible(x, y, i)) {
                        this->grid[y][x] = i;
                        solve();
                        this->grid[y][x] = this->defaultValue;
                    }
                }
                return;
            }
        }
    }
    printGrid();
}

#endif //SUDOKU_SUDOKUSOLVER_H
