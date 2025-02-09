#include "black_scholes.h"
#include "normal_distribution.h"
#include <cmath>

double calculateD1(const OptionParameters& params) {
    return (std::log(params.stockPrice / params.strikePrice) + 
            (params.riskFreeRate + 0.5 * params.volatility * params.volatility) * 
            params.timeToMaturity) / 
           (params.volatility * std::sqrt(params.timeToMaturity));
}

double calculateD2(const OptionParameters& params) {
    return calculateD1(params) - params.volatility * std::sqrt(params.timeToMaturity);
}

double calculateCallPrice(const OptionParameters& params) {
    if (!validateParameters(params)) {
        return -1.0; // Invalid parameters
    }
    
    double d1 = calculateD1(params);
    double d2 = calculateD2(params);
    
    return params.stockPrice * normalCDF(d1) - 
           params.strikePrice * std::exp(-params.riskFreeRate * params.timeToMaturity) * 
           normalCDF(d2);
}

double calculatePutPrice(const OptionParameters& params) {
    if (!validateParameters(params)) {
        return -1.0; // Invalid parameters
    }
    
    double d1 = calculateD1(params);
    double d2 = calculateD2(params);
    
    return params.strikePrice * std::exp(-params.riskFreeRate * params.timeToMaturity) * 
           normalCDF(-d2) - params.stockPrice * normalCDF(-d1);
}

bool validateParameters(const OptionParameters& params) {
    return params.stockPrice > 0 &&
           params.strikePrice > 0 &&
           params.timeToMaturity > 0 &&
           params.volatility > 0;
} 