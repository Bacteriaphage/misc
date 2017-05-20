#pragma once

class Enemy{
public:
   double hp;
   double mp;
   double dps;
   Enemy(double, double, double);
   virtual void roar()=0;
};
class Slug : public Enemy{
   public:
   Slug(double, double, double);
   void roar();
};
class MagicSpear : public Enemy{
   public:
   MagicSpear(double, double, double);
   void roar();
};
