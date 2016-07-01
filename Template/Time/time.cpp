#include "time.hpp"

using namespace std;

double Time::GetTime()
{
  time_t diffsec = difftime(endTime.tv_sec, startTime.tv_sec);    // 秒数の差分を計算
  suseconds_t diffsub = endTime.tv_usec - startTime.tv_usec;      // マイクロ秒部分の差分を計算
  if (diffsub < 0) {                                              // マイクロ秒が負になったとき
    diffsec -= 1;                                                 // 秒部分を繰り下げ
    diffsub = 1000000 + diffsub;                                  // 1秒との差
  }
  double realsec = diffsec+diffsub*1e-6;

  return realsec;
}
