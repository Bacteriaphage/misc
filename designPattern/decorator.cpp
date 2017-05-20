#include <iostream>
#include <string>
using namespace std;

class Pizza{
public:
    virtual string getComponent() = 0;
    virtual double getCost() = 0;
};

class PlainPizza : public Pizza{
public:
    string getComponent(){
        return "Plain Pizza;";
    }
    double getCost(){
        return 3.0;
    }
};

class TopDecorator : public Pizza{
public:
    Pizza *_p;
    TopDecorator(Pizza* _p) : _p(_p){
        
    }
};

class TomatoSauce : public TopDecorator{
public:
    TomatoSauce(Pizza* _p) : TopDecorator(_p){
    
    }
    string getComponent(){
       return _p->getComponent() + "Tomato Sauce";
    }
    double getCost(){
       return _p->getCost() + 1.0;
    }
};
class Cheese : public TopDecorator{
public:
    Cheese(Pizza* _p) : TopDecorator(_p){
    
    }
    string getComponent(){
        return _p->getComponent() + "Cheese";
    }
    double getCost(){
        return _p->getCost() + 0.5;
    }
};

int main(){
    Pizza* myOrder = new TomatoSauce(new Cheese(new PlainPizza()));
    cout << myOrder->getComponent();
    cout << myOrder->getCost();
    return 0;
}
