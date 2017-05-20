#include "ob.h"
#include "sub.h"

unsigned int ObserverIns::Incremental = 0;
int main(){
    shared_ptr<StockGrabber> stg(new StockGrabber);
    shared_ptr<ObserverIns> ob1(new ObserverIns(stg));
    weak_ptr<ObserverIns> wob1(ob1);
    stg->ObRegister(wob1);
    stg->setIBM(10.0);
    stg->setGoog(20.0);
    shared_ptr<ObserverIns> ob2(new ObserverIns(stg));
    weak_ptr<ObserverIns> wob2(ob2);
    stg->ObRegister(wob2);
    stg->setIBM(5.0);
    stg->ObUnregister(ob2);
    cout << stg.use_count() << ob1.use_count() << ob2.use_count();
    return 0;
}
