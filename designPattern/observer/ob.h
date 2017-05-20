#pragma once
#include <memory>
#include <iostream>
#include <unordered_set>
using namespace std;
class StockGrabber;
class Observer{
public:
    virtual void update(double googPri, double IBMPri) = 0;
};
class ObserverIns : public Observer{
    double _goog;
    double _IBM;
    unsigned int OBID;
    static unsigned int Incremental;
    shared_ptr<StockGrabber> _sg;
 public:
    ObserverIns(shared_ptr<StockGrabber> sg);
    void update(double googPri, double IBMPri);     
};

