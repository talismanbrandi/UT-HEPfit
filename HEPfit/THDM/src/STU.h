/* 
 * Copyright (C) 2015 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef STU_H
#define	STU_H

#include <stdexcept>
#include "ThObservable.h"
#include "THDM.h"
#include "THDMcache.h"

/**
 * @class STU
 * @ingroup THDM 
 * @brief An observable class for the electroweak Peskin-Takeuchi pseudo-observables.
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details This class is used to compute the observables @f$S@f$, @f$T@f$ and @f$U@f$. Formulae from equations (21), (22) and (23) in @cite Baak:2011ze.
 */
class STU : public ThObservable {
public:
    /**
     * @brief Constructor.
     * @param[in] ?
     */
   STU(const StandardModel& SM_i);
     
    /**
     * @brief Empty constructor.
     */
    double computeThValue();

    const THDM * myTHDM;

    /**
     * @brief Function @f$F(m02,m12)@f$ used for %THDM. Remember that this function is
     * defined for %THDM while for SUSY we have a multiplicative factor 2.
     * @param[in] m02 mass square @f$m_0^2@f$
     * @param[in] m12 mass square @f$m_1^2@f$
     * @return @f$F(m02,m12)@f$
     */
    double F(const double m02, const double m12) const;

protected:
    THDMcache * mycache;
          
};

/**
 * @class DeltaS
 * @ingroup THDM
 * @brief An observable class for the %THDM contribution to the electroweak Peskin-Takeuchi pseudo-observable @f$S@f$.
 */
class DeltaS: public STU {
public:

    /**
     * @brief Constructor for DeltaS.
     */
    DeltaS(const StandardModel& SM_i);

    /**
     * @brief THDM contribution to @f$S@f$.
     * @return @f$\Delta S@f$
     */
    double computeThValue ();
};

/**
 * @class DeltaT
 * @ingroup THDM
 * @brief An observable class for the %THDM contribution to the electroweak Peskin-Takeuchi pseudo-observable @f$T@f$.
 */
class DeltaT: public STU {
public:

    /**
     * @brief Constructor for DeltaT.
     */
    DeltaT(const StandardModel& SM_i);

    /**
     * @brief THDM contribution to @f$T@f$.
     * @return @f$\Delta T@f$
     */
    double computeThValue ();
};

/**
 * @class DeltaU
 * @ingroup THDM
 * @brief An observable class for the THDM contribution to the electroweak Peskin-Takeuchi pseudo-observable @f$U@f$.
 */
class DeltaU: public STU {
public:

    /**
     * @brief THDM contribution to @f$U@f$.
     * @brief Constructor for DeltaU.
     */
    DeltaU(const StandardModel& SM_i);

    /**
     * @return @f$\Delta U@f$
     */
    double computeThValue ();

protected:
    DeltaS * myDeltaS;
};

#endif	/* STU_H */
