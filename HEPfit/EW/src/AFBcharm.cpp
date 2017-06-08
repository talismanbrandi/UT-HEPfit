/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "AFBcharm.h"
#include "StandardModel.h"

double AFBcharm::computeThValue()
{
    return SM.AFB(SM.getQuarks(SM.CHARM));
}

