/*
 * Copyright (C) 2013 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef LEPTONFLAVOUR_H
#define	LEPTONFLAVOUR_H

#include "HeffDLij.h"
#include "HeffDLi3j.h"
#include "Heffmueconv.h"
#include "Heffgminus2.h"

class StandardModel;

/**
 * @addtogroup LeptonFlavour
 * @brief A module for calculating Lepton Flavor Violating observables.
 * @{
 */

/**
 * @class LeptonFlavour
 * @ingroup LeptonFlavour
 * @brief The parent class in LeptonFlavour for calculating all the Wilson coefficients for various Lepton Flavor Violating (LFV) processes. 
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details The LeptonFlavour class aggregates the Wilson coefficients for each of the LFV the processes generated by the model by calling the Hamiltonians.
 */
class LeptonFlavour {
public:

    /**
     * @brief The constructor.
     * @param[in] SM_i a reference to an object of the class StandardModel
     */ 
    LeptonFlavour(const StandardModel& SM_i) :
            HDLij(SM_i),HDLi3j(SM_i),Hmueconv(SM_i),Hgminus2(SM_i)
    {};

    /**
     * @brief The member that returns an object of the class HeffDLij.
     * @return returns the Hamiltonian for the process \f$ \ell_j \to \ell_i \gamma \f$
     * 
     */
    const HeffDLij& getHDLij() const {
        return HDLij;
    }

    /**
     * @brief Computes the Wilson coefficient for the process \f$ \ell_j \to \ell_i \gamma \f$.
     * @param[in] li_lj determines the process, e.g., 1 = \f$ \mu \to e \gamma \f$, 2 = \f$ \tau \to \mu \gamma \f$, 3 = \f$ \tau \to e \gamma \f$
     * @return returns the Wilson coefficients for the process \f$ \ell_j \to \ell_i \gamma \f$
     * 
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffli_lj_gamma(int li_lj) {
        return HDLij.ComputeCoeffDLij(li_lj);
    }

    /**
     * @brief The member that returns an object of the class HeffDLi3j.
     * @return returns the Hamiltonian for the process \f$ \ell_j \to \ell_i \ell_i \ell_i \f$
     * 
     */
    const HeffDLi3j& getHDLi3j() const {
        return HDLi3j;
    }

    /**
     * @brief Computes the Wilson coefficient for the process \f$ \ell_j \to \ell_i \ell_i \ell_i \f$.
     * @param[in] li_lj determines the process, e.g., 1 = \f$ \mu \to eee \f$, 2 = \f$ \tau \to \mu \mu \mu \f$, 3 = \f$ \tau \to eee \f$
     * @return returns the Wilson coefficients for the process \f$ \ell_j \to \ell_i \ell_i \ell_i \f$
     * 
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffli_3lj(int li_lj) {
        return HDLi3j.ComputeCoeffDLi3j(li_lj);
    }

    /**
     * @brief The member that returns an object of the class Heffmueconv.
     * @return returns the Hamiltonian for the process \f$ \mu \to \e \f$ conversion in Nuclei
     * 
     */
    const Heffmueconv& getHmueconv() const {
        return Hmueconv;
    }

    /**
     * @brief Computes the Wilson coefficient for the process \f$ \mu \to \e \f$ conversion in Nuclei.
     * @return returns the Wilson coefficients for the process \f$ \mu \to \e \f$ conversion in Nuclei
     * 
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffmueconversion() {
        return Hmueconv.ComputeCoeffmueconv();
    }

    /**
     * @brief The member that returns an object of the class Heffgminus2.
     * @return returns the Hamiltonian for the process \f$ (g-2)_{\mu} \f$ at one-loop
     * 
     */
    const Heffgminus2& getHgminus2() const {
        return Hgminus2;
    }

    /**
     * @brief Computes the Wilson coefficient for the process \f$ (g-2)_{\mu} \f$ at one-loop.
     * @return returns the Wilson coefficients for the process \f$ (g-2)_{\mu} \f$ at one-loop
     * 
     */
    gslpp::vector<gslpp::complex>** ComputeCoeffgminus2mu() {
        return Hgminus2.ComputeCoeffgm2mu();
    }

private:
    /**
     *@brief Object for the Hamiltonian for the process \f$ \ell_j \to \ell_i \gamma \f$.
     */
    HeffDLij HDLij;
    /**
     *@brief Object for the Hamiltonian for the process \f$ \ell_j \to \ell_i \ell_i \ell_i \f$.
     */
    HeffDLi3j HDLi3j;
    /**
     *@brief Object for the Hamiltonian for the process \f$ \mu \to \e \f$ conversion in Nuclei.
     */
    Heffmueconv Hmueconv;
    /**
     *@brief Object for the Hamiltonian for the process \f$ (g-2)_{\mu} \f$ at one-loop.
     */
    Heffgminus2 Hgminus2;
};

/**
 * @}
 */

#endif	/* LEPTONFLAVOUR_H */