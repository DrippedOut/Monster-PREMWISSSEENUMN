#include "monster.h"

class Thanos {
private:
  int stones;
  int hp; // extra hp;
public:
  Thanos(int a = 0, int b = 1000);
  ~Thanos() { cout << " Bye-bye! Thanny" << endl; };

  void snap_finger(monster[], int);
  void operator++(){stones++;};
};

Thanos::Thanos(int a, int b) {
  stones = a;
  hp = b;
}

/*
  -show all hps
  -clear half of monster
  -set hp = 0, if stone = 6 
  
   snap_finger(monsters array, no# monsters)
*/
void Thanos::snap_finger(monster m[], int n) {
  if (stones < 6)
    cout << "Not enough stones" << endl;
  else {
    int i;
    for (i = 0; i < n; i += 2) {
      m[i].kill();
    }
  }
}