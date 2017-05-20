#include "ob.h"
#include "sub.h"

ObserverIns::ObserverIns(shared_ptr<StockGrabber> sg){
    _sg = sg;
    OBID = ++Incremental;
    cout << "new observer " << OBID << endl;
}
void ObserverIns::update(double googPri, double IBMPri){
    _goog = googPri;
    _IBM = IBMPri;
    cout << OBID << " " << _goog << " " << _IBM << endl;
}
