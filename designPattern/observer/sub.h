#pragma once
#include <memory>
#include <iostream>
#include <unordered_set>
using namespace std;

class Observer;
class ObserverIns;

class StockGrabber{
private:
    unordered_set<Observer*> observers;
    double _goog, _IBM;
public:
    StockGrabber(){
        _goog = 100.0;
        _IBM = 120.0;
    }
    void ObRegister(weak_ptr<Observer> _ob){
        observers.insert(_ob.lock().get());
    }
    void ObUnregister(weak_ptr<Observer> _ob){
        observers.erase(_ob.lock().get());
    }
    void setIBM(double);
    void setGoog(double);
};
