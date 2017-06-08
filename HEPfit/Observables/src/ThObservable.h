/* 
 * Copyright (C) 2012 HEPfit Collaboration
 *
 *
 * For the licensing terms see doc/COPYING.
 */

#ifndef THOBSERVABLE_H
#define	THOBSERVABLE_H

class StandardModel;

#include <vector>
#include <string>

/**
 * @class ThObservable
 * @ingroup Observable
 * @brief A class for a model prediction of an observable. 
 * @author HEPfit Collaboration
 * @copyright GNU General Public License
 * @details This class provides a base for the computation of the values
 * of different theory observables.
 */
class ThObservable {
public:

    /**
     * @brief Constructor.
     * @param[in] SM_i a reference to an object of type StandardModel
     */
    ThObservable(const StandardModel& SM_i) 
    : SM(SM_i)
    {
        min = 0;
        max = 0;
    };

    /**
     * @brief The copy constructor.
     */
    ThObservable(const ThObservable& orig)
    : SM(orig.SM)
    {
    };

    /**
     * @brief The default destructor.
     */
    virtual ~ThObservable()
    {
    };

    /**
     * @brief A member to be overloaded by the respective theory observable.
     * class that calculates the value of the observable
     */
    virtual double computeThValue() = 0;

    /**
     * @brief A set method to set the minimum value of the bin.
     * @param[in] the minimum values of the bin
     */
    void setBinMin(double min)
    {
        this->min = min;
    };

    /**
     * @brief A set method to set the maximum value of the bin.
     * @param[in] the maximum values of the bin
     */
    void setBinMax(double max)
    {
        this->max = max;
    };

    /**
     * @brief A get method to get the minimum value of the bin.
     * @return the minimum values of the bin
     */
    double getBinMin()
    {
        return min;
    };

    /**
     * @brief A get method to get the maximum value of the bin.
     * @return the maximum values of the bin
     */
    double getBinMax()
    {
        return max;
    };
    
    /**
     * @brief A get method to get the model
     * @return a reference to the model
     */
    const StandardModel& getModel()
    {
      return SM;  
    };
    
    /**
     * @brief A set method to get the parameters for the specific observable
     * @param a vector of parameter names
     */
    void setParametersForObservable(std::vector<std::string> parametersForObservable_i)
    {
        this->parametersForObservable = parametersForObservable_i;
    }
    
    /**
     * @brief A get method to get the parameters for the specific observable
     * @return a vector of parameter names
     */
    const std::vector<std::string> getParametersForObservable()
    {
        return parametersForObservable;
    };

protected:
    const StandardModel& SM; ///< A reference to an object of StandardMode class.
    double min;///< The bin minimum.
    double max;///< the bin maximum.
    std::vector<std::string> parametersForObservable;///< a vector of parameter namesfor the specific observable
};

#endif	/* THOBSERVABLE_H */
