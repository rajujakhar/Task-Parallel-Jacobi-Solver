/**
    header file: util.hpp
    Purpose: to declare class variables and member functions of Utility namespace


    @author Raju Ram
    @version 1.0 04/07/18
*/


#ifndef UTIL_H
#define UTIL_H

#include <utility>
#include <cstddef>  // std::size_t
#include <cmath>
#include <mutex>
#include <vector>
#include <random>  // normal distribution
#include "Timer.hpp"
#include "Timing.hpp"

namespace Utility{

   // Handles std::cout resource among threads.
    extern std::mutex mu;

    extern std::mutex mu_task;

    extern const double PI;

    extern const double K;

    extern size_t maxIter;

    extern size_t numTasks;

    extern const size_t numRows;

    extern const size_t numCols;

    extern size_t numThreads;

    extern const double tol;

    extern std::vector<TP::Timer> threadLocTimer;
    extern std::vector<double> compute_time;

    extern double gtime_count;
    extern TP::Timer gtime;
    extern ace::Timing gtiming;

    /*normal distribution generator
    extern std::default_random_engine generator;
    extern std::normal_distribution<double> distribution;*/

    // flag to enable debugging
    extern const bool debug;

    void setParams(const size_t iters, const size_t threads, const size_t tasks);
    				//const size_t cycles,const double std_dev);

    void setGridParams(std::size_t totRows, std::size_t totCols, std::size_t numTasks);

    void displayUtilGrid();

    size_t getGlobalRow(size_t task_id, size_t localRow);

    std::pair<double, double> getXY(std::size_t global_row, std::size_t global_col);
}


#endif // UTIL_H
