#include "avl.h"
#include <iostream>

using namespace std;
int main() {
  AVLtree<int> *t = new AVLtree<int>();
  for (int i = 0; i < 1e6; ++i) {
    t->Add(i);
  }
  cout << t->height() << endl;
  delete t;
  return 0;
}