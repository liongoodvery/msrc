#include <deque>
#include "utils.hpp"

using namespace std;
int main(int argc, char *argv[]) {
  const int COUNT = 2;
  deque<int> dints;
  for (int i = 0; i < COUNT; ++i)
  {
    dints.push_front(i);
  }

  for (int i = 0; i < COUNT; ++i)
  {
    dints.push_back(i);
  }

  printElements(dints);
  return 0;
}