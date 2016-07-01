#ifndef __TIME_LOCAL__
#define __TIME_LOCAL__

#include <time.h>
#include <sys/time.h>

class Time{
public :
  virtual double GetTime();
  void TimerStart(){ gettimeofday(&startTime, NULL); }
  void TimerStop(){ gettimeofday(&endTime, NULL); }

private :
  struct timeval startTime, endTime;    
};

#endif
