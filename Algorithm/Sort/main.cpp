#include "main.hpp"

int main(int argc, char* argv[])
{
  Sort sort;

  sort.Bubble();
  sort.ShowData(RAW);
  sort.ShowData(SORTED);

  return 0;
}
