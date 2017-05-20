#include "enemy.h"
#include <iostream>
#include <string>
using namespace std;

Enemy::Enemy(double _h, double _m, double _d) : hp(_h), mp(_m), dps(_d){}

Slug::Slug(double _h, double _m, double _d) : Enemy(_h, _m, _d){}
void Slug::roar(){
   cout << string((int)hp, 'r') << endl;
}
MagicSpear::MagicSpear(double _h, double _m, double _d) : Enemy(_h, _m, _d){}
void MagicSpear::roar(){
   cout << string((int)mp, 'w') << endl;
}
