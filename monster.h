#ifndef monster_h
#define monster_h

#include <iostream>
#include <string>

using namespace std;

class monster {
private:
  string name;
  int hp;
  int potion;

public:
  monster(string, int = 0, int = 0);
  monster();
  ~monster(); // Alt+126

  void operator-=(int x){hp+=x;}; // Subtract hp
  void operator+=(int x){hp-=x;}; // Add hp
  void operator--(){hp-=1;}; 
  
  void print();
  void Attack(monster &);
  void kill(); // hp=0
  void revive(); // hp=20
  bool alive();
};

monster::monster() {
  // Initialize member variables with default values
  name = "Goblin";
  hp = 10;
  potion = 10;
  cout << name << " is summonned" << endl;
}

monster::monster(string n, int h, int p) {
  name = n;
  hp = h;
  potion = p;
  cout << name << " is summonned" << endl;
}

monster::~monster() { 
  cout << "Monster " << name << " is gone." << endl; }

void monster::print() {
  cout << "Monster " << name;
  cout << " --> Hp:" << hp << " Potion:" << potion << endl;
}

void monster::Attack(monster &target) {
  if (!alive()) {
    cout << name << " is already dead" << endl;
    return; // Breaks out of function
  }
  
  if (!target.alive()) {
    cout << target.name << " is already dead" << endl;
    return; // Breaks out of function
  }

  cout << name << " attacks " << target.name << "!" << endl;
  
  // if A attack B  A.hp-- B.hp-=10
  if (hp>target.hp) {
    hp--;
    target.hp-=10; 
    cout << "The attack was succussful" << endl;
  }
  cout << "The attack failed" << endl;
}

void monster::kill() {
  hp = 0;
  cout << "Monster " << name << " has been killed." << endl;
}

void monster::revive() {
  hp = 20;
  cout << name << " is revived" << endl;
}

bool monster::alive(){
  return hp>0;
}

#endif
