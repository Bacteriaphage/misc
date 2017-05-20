#include "enemyfactory.h"
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

void enemyTest(Enemy* e){
   cout << "hp: " << e->hp << endl << "mp: " << e->mp << endl << "dps: " << e->dps << endl;
}

int main(){
   vector<unique_ptr<Enemy>> enemies;
   EnemyFac factory;
   while(1){
      cout << "S or M?" << endl;
      char enemyType;
      cin >> enemyType;
      enemies.push_back(unique_ptr<Enemy>(factory.generate(enemyType)));
      for(auto& e : enemies){
         enemyTest(e.get());
         e->roar();
      }
      cout << endl;
   }
}

