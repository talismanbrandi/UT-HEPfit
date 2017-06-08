/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#include "PtauPol.h"
#include "StandardModel.h"

double PtauPol::computeThValue()
{
    return SM.A_f(SM.getLeptons(SM.TAU));
}

