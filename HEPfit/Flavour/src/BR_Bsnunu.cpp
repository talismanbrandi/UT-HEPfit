/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "BR_Bsnunu.h"
#include "StandardModel.h"
#include "std_make_vector.h"

BR_Bsnunu::BR_Bsnunu(StandardModel& SM_i)
: ThObservable(SM_i), mySM(SM_i)
{
    setParametersForObservable(make_vector<std::string>() << "Br_B_Xcenu");
}

double BR_Bsnunu::computeThValue()
{
    double theta= asin(sqrt( (M_PI * mySM.getAle() )/( sqrt(2) *
                  mySM.getGF() * mySM.Mw_tree() * 
                  mySM.Mw_tree()) ));
    
    double z = mySM.getQuarks(QCD::CHARM).getMass()/
               mySM.getQuarks(QCD::BOTTOM).getMass();
    
    
    return(3.*mySM.getAle()*mySM.getAle()/(4.*M_PI*M_PI*pow(sin(theta),4.)) * 
           mySM.getOptionalParameter("Br_B_Xcenu") *
           BRBsnunu(NLO).real() * (1.+2.*mySM.Als(mySM.getMub())/3./M_PI)*(25./4.-M_PI*M_PI)
           /(1. - 8.*z*z + 8.*z*z*z*z*z*z - z*z*z*z*z*z*z*z - 24.*z*z*z*z*log(z))
           /(1. - 2.*mySM.Als(mySM.getMub())/3./M_PI*((M_PI*M_PI-31./4.)*(1.-z*z)+1.5)));
}

gslpp::complex BR_Bsnunu::BRBsnunu(orders order)
{
    if (mySM.getFlavour().getHDB1().getCoeffsnunu().getOrder() < order){
        std::stringstream out;
        out << order;
        throw std::runtime_error("BRBsnunu::computeThValue(): requires cofficient of "
                                 "order" + out.str() + "not computed");
    }
    
    gslpp::vector<gslpp::complex> ** allcoeff = mySM.getFlavour().ComputeCoeffsnunu();
    
    switch(order) {
        case NLO:
                return((*(allcoeff[LO]) + *(allcoeff[NLO])) *
                       (*(allcoeff[LO]) + *(allcoeff[NLO])));
        case LO:
                return((*(allcoeff[LO])) *
                       (*(allcoeff[LO])));
        default:
            std::stringstream out;
            out << order;
            throw std::runtime_error("BRBsnunu::BRBsnunu(): order " + out.str() + "not implemented");;
    }
}

