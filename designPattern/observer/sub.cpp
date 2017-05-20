#include "sub.h"
#include "ob.h"

void StockGrabber::setIBM(double price){
    _IBM = price;
    for(auto ob : observers){
        ob->update(_goog, _IBM);
    }
}
void StockGrabber::setGoog(double price){
    _goog = price;
    for(auto ob : observers){
        ob->update(_goog, _IBM);
    }
}
