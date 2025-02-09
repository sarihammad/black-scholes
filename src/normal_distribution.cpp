#include "normal_distribution.h"
#include <cmath>

const double PI = 3.141592653589793238463;

double normalPDF(double x) {
    return (1.0 / std::sqrt(2.0 * PI)) * std::exp(-0.5 * x * x);
}

double normalCDF(double x) {
    // Using the approximation method by Abramowitz and Stegun
    const double b1 = 0.31938153;
    const double b2 = -0.356563782;
    const double b3 = 1.781477937;
    const double b4 = -1.821255978;
    const double b5 = 1.330274429;
    const double p = 0.2316419;
    
    double t = 1.0 / (1.0 + p * std::abs(x));
    double z = normalPDF(x);
    
    double result = 1.0 - z * (b1 * t + b2 * t * t + b3 * std::pow(t, 3) + 
                              b4 * std::pow(t, 4) + b5 * std::pow(t, 5));
    
    return x > 0 ? result : 1.0 - result;
} 