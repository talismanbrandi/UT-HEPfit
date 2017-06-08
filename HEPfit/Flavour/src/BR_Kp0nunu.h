/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef BR_KP0NUNU_H
#define	BR_KP0NUNU_H

class StandardModel;
#include "ThObservable.h"
#include "OrderScheme.h"
#include "gslpp.h"


class BR_Kp0nunu : public ThObservable {
public:   
    /**
     * constructor
     * @param Flavour
     */
    BR_Kp0nunu(StandardModel& SM_i);
    
    /**
     * 
     * @return theoretical value of \f$ BR(K_L \rightarrow \pi^{0} \nu \bar{\nu}) \f$, 
     * for example see hep-ph/0603079 section 2.3
     */
    double computeThValue();
    
    
protected:
    
    /**
     * 
     * @param order
     * @param order_ew
     * @return the short distance contribution to the 
     * \f$ BR(K_{L} \rightarrow \pi^{0} \nu \bar{\nu}) \f$, for example
     * see hep-ph/0603079 section 2.3
     */
    gslpp::complex BRKp0nunu(orders order, orders_ew order_ew);
    
private:
    
    StandardModel& mySM;
};

#endif	/* BR_KP0NUNU_H */
