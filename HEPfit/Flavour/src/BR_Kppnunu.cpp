/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "BR_Kppnunu.h"
#include "StandardModel.h"
#include "std_make_vector.h"

BR_Kppnunu::BR_Kppnunu(StandardModel& SM_i)
: ThObservable(SM_i), mySM(SM_i), CKpnunu(SM)
{
    setParametersForObservable(make_vector<std::string>() << "Br_Kp_P0enu" << "DeltaP_cu" << "IB_Kp");
}

double BR_Kppnunu::computeThValue()
{
    double theta= asin(sqrt( (M_PI * SM.getAle() )/( sqrt(2) * SM.getGF() * 
                   SM.Mw_tree() * SM.Mw_tree()) ));
    
    return( SM.getOptionalParameter("IB_Kp") * 3.*SM.getAle()*SM.getAle()/(2.*M_PI*M_PI*pow(sin(theta),4.))
           * SM.getOptionalParameter("Br_Kp_P0enu") * BRKppnunu(NLO, NLO_ew).real());
}

gslpp::complex BR_Kppnunu::BRKppnunu(orders order, orders_ew order_ew)
{
    if (mySM.getFlavour().getHDS1().getCoeffDS1pnunu().getOrder() < order){
        std::stringstream out;
        out << order;
        throw std::runtime_error("BRKppnunu::computeThValue(): requires cofficient of "
                                 "order" + out.str() + "not computed");
    }
    
    gslpp::vector<gslpp::complex> ** allcoeff = mySM.getFlavour().ComputeCoeffDS1pnunu();
    
    switch(order_ew) {
        case NLO_ew:
            return((*(allcoeff[LO]) + *(allcoeff[NLO]) + *(allcoeff[NLO_ew])) *
                   (*(allcoeff[LO]) + *(allcoeff[NLO]) + *(allcoeff[NLO_ew])) +
                   CKpnunu.C_TOT(NNLO,NLO_ew)*CKpnunu.C_TOT(NNLO,NLO_ew));
        case LO_ew:
            switch(order) {
                case NLO:
                    return((*(allcoeff[LO]) + *(allcoeff[NLO])) *
                           (*(allcoeff[LO]) + *(allcoeff[NLO])) +
                           CKpnunu.C_TOT(NLO,LO_ew)*CKpnunu.C_TOT(NLO,LO_ew));
                case LO:
                    return((*(allcoeff[LO])) * (*(allcoeff[LO]) ) +
                           CKpnunu.C_TOT(LO,LO_ew)*CKpnunu.C_TOT(LO,LO_ew));
                default:
                    std::stringstream out;
                    out << order;
                    throw std::runtime_error("BRKppnunu::BRKppnunu(): order " + out.str() + "not implemented");
            }
        default:
            std::stringstream out;
            out << order_ew;
            throw std::runtime_error("BRKppnunu::BRKppnunu(): order_ew " + out.str() + "not implemented");
    }
}


