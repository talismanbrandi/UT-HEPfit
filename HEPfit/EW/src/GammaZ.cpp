/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "GammaZ.h"
#include "StandardModel.h"

double GammaZ::computeThValue()
{
    return SM.Gamma_Z();
}

