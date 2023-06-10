#include <iostream>
using namespace std;
#include "Thanos.h"

int main() {

  // ---------------Event 1-----------------

  //call constructors
  monster x("Apple", 10, 20), y("Boba", 5, 5);

  x.print();
  y.print();

  int i;
  x.Attack(y);
  x.print();
  y.print();

  monster *tussy = &x;
  tussy->Attack(y); // x.Attack(y);

  x.print();
  y.print();

  // ---------------Event 2-----------------

  monster *ptr, s("Big", 10, 10); // constructor 1(big)
  ptr = &s; // pointer P points to s
  s+= 30; // increase hp by 30
  --s;     // decrease hp by 1

  ptr = new monster("Boat", 5, 20); // constructor 2(boat)
  
  ptr->print();
  s.print();
  
  delete ptr; // destructor 1(boat)

  ptr = new monster[3]; // constructor 3, 4, 5(not, bond, top)
  delete[] ptr;         // destructor (top, bond,not)

  // destructor big

  // x.hp decrease by 1 y.hp decrese by half
  monster xx[5] = {{"Bright", 30}, {"Big"}, {"Boat"}};
  monster *pa = new monster("Mike");
  delete pa;

  /* Assignment*/

  Thanos T;
  int n;
  cout << "How many monster?";
  cin >> n;

  monster *m = new monster[n];

  // 2. making sure they have hp
  for (int i = 0; i < n; i++)
    m[i].print();
  
  ++T; // stones = 1
  ++T; // stones = 2
  T.snap_finger(m, n); // "Not enough stones"
  // finish the snap finger function
  ++T; // 3
  ++T; // 4
  T.snap_finger(m, n); // "Not enough stones"
  ++T; // 5
  ++T; // 6
  T.snap_finger(m, n);

  for (int i = 0; i < n; i++)
    m[i].print();

  delete[] m;
}