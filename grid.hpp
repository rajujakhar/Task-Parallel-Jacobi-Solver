#ifndef GRID_H
#define GRID_H

#include <vector>
#include <cstddef>
#include <iostream>
#include <string>
#include <mutex>
#include "util.h"

class Grid
{

public:

    size_t numRows_;
    size_t numlocRows_;
    size_t numCols_;

    double x_max_;
    double y_max_;
    double hx_;
    double hy_;

    std::vector<double> u1_;
    std::vector<double> u2_;
    std::vector<double> f_;

    Grid(size_t numRows, size_t numCols, size_t numTasks);
    const std::vector<double> & getSrcVec(size_t curIter);
    std::vector<double> & getDestVec(size_t curIter);

    //Grid(size_t numRows, size_t numCols, std::string);

    void displayGrid();
    void displayGrid(const std::vector<double> &vec);

    ~Grid();
};

#endif // GRID_H
