#include "enemyfactory.h"

Enemy* EnemyFac::generate(char enemyType){
   if(enemyType == 'S'){
      return new Slug(5.0, 0.0, 1.0);
   }
   else if(enemyType == 'M'){
      return new MagicSpear(1.0, 4.0, 2.0);
   }
   else return nullptr;
}
