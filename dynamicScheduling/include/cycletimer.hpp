/**
    header file: cycletimer.hpp
    Purpose: interface to measure the cpu cycles.

    @author Daniel
    @version 1.0 04/07/18
*/



#ifndef CYCLETIMER_H
#define CYCLETIMER_H

#include <x86intrin.h>  // __rdtsc()


class CycleTimer {

  public:

    CycleTimer()
    : _tag()
    , _is_running(false)
    , _elapsed_cycles(0.)
    {}

    CycleTimer(std::string const & tag)
    : _tag(tag)
    , _is_running(false)
    , _elapsed_cycles(0.)
    {}

    inline void
    start() {

//      if(_is_running)
//        throw std::logic_error("CycleTimer is already running. Cannot start CycleTimer.");
//
//      _is_running = true;
//      clock_gettime(CLOCK_MONOTONIC, &_start);
//      _elapsed_cycles -= static_cast<double>(__rdtsc());
      _elapsed_cycles -= __rdtsc();
    }

    inline void
    stop() {
//      if(!_is_running)
//        throw std::logic_error("CycleTimer is not running. Cannot stop CycleTimer.");
//
//      _is_running = false;
//      clock_gettime(CLOCK_MONOTONIC, &_end);
//
//      _elapsed_sec += timeDiff(_end,_start);
//      _elapsed_cycles += static_cast<double>(__rdtsc());
      _elapsed_cycles += __rdtsc();
    }

    double elapsedCycles () {
      return _elapsed_cycles;
    }

//    double elapsedTime () {
//      return _elapsed
//    }

    void print() {

      std::cout << _tag << " CycleTimer: "
                 << _elapsed_cycles
                 << " s"
                 << std::endl;
    }


  private:

    std::string const _tag;
    bool _is_running;
//    double _elapsed_sec;
    long _elapsed_cycles;

    struct timespec _start;
    struct timespec _end;

    static double
    timeDiff(struct timespec &end, struct timespec &start) {

      double dt (0.0);
      struct timespec tmp;

      if(end.tv_nsec - start.tv_nsec < 0)
      {
        tmp.tv_sec  = end.tv_sec - start.tv_sec - 1;
        tmp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
      }
      else
      {
        tmp.tv_sec  = end.tv_sec - start.tv_sec;
        tmp.tv_nsec = end.tv_nsec - start.tv_nsec;
      }
      dt = double(tmp.tv_sec);
      dt += 1.0e-9*double(tmp.tv_nsec);

      return dt;
    }

  };




#endif // CYCLETIMER_H
