#include "main.hpp"

int main(int argc, char* argv[])
{
  Sort sort1;
  sort1.Bubble();
  sort1.ShowData(RAW);
  sort1.ShowData(SORTED);

  Sort sort2;
  sort2.Quick();
  sort2.ShowData(RAW);
  sort2.ShowData(SORTED);

  return 0;
}
