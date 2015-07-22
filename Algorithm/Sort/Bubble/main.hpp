#ifndef __MAIN__
#define __MAIN__

#define SORTED true
#define RAW false

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <sys/time.h>

using namespace std;

class Data{
public :

  int n;     // number of datas
  int* data;

  Data(){ Init(); }
  ~Data(){ delete [] data; }

private :

  int max;  // maximum data
  int min;  // minimum data

  inline void InitRand(){ srand((int)time(NULL)); }
  inline int GetRand(int max, int min){ return (rand() % (max-min+1) + min); }
  inline void Init(){
    InitRand(); 

    cout << "How many datas ? : ";
    cin >> n;
    cout << "Max ? : ";
    cin >> max;
    cout << "Min ? : ";
    cin >> min;

    data = new int [n];

    for(int i=0; i<n; i++)
      data[i] = GetRand(max, min);
  }
};


class Time{
public :

  inline void TimerStart(){ gettimeofday(&startTime, NULL); }
  inline void TimerStop(){ gettimeofday(&endTime, NULL); }
  double GetTime();

private :
  struct timeval startTime, endTime;    
};

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

class Sort : private Data, private Time{
public :

  Sort(){ 
    data_raw = new int [n]; 
    for(int i=0; i<n; i++)
      data_raw[i] = data[i];
  }
  ~Sort(){ delete [] data_raw; }

  void Bubble();
  void ShowData(bool flg);

private :

  int* data_raw;

  void swap(int i, int j);
  
};

void Sort::swap(int i, int j)
{
  int tmp = data[i];
  data[i] = data[j];
  data[j] = tmp;
}

void Sort::Bubble()
{
  cout << "Start Bubble Sort" << endl;
  TimerStart();
  for(int i=0; i<n-1; i++){
    for(int j=n-1; j>i; j--){
      if(data[j-1] > data[j])
	swap(j-1, j);
    }
  }
  TimerStop();
  cout << "Finish Bubble Sort" << endl;
  cout << "It takes ... " << GetTime() << " [sec] ." << endl;
}

void Sort::ShowData(bool flg)
{
  if(flg){
    cout << "Sorted data ..." << endl;
    for(int i=0; i<n; i++)
      cout << data[i] << " ";
    cout << endl;
  }
  else{
    cout << "Raw Data ..." << endl;
    for(int i=0; i<n; i++)
      cout << data_raw[i] << " ";
    cout << endl;
  }
}

#endif
