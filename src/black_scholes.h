#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

struct OptionParameters {
    double stockPrice;     // Current stock price (S_0)
    double strikePrice;    // Strike price (K)
    double timeToMaturity; // Time to expiration in years (T)
    double riskFreeRate;   // Risk-free interest rate (r)
    double volatility;     // Volatility of the stock (sigma)
};

// Calculate d1 and d2 parameters
double calculateD1(const OptionParameters& params);
double calculateD2(const OptionParameters& params);

// Calculate option prices
double calculateCallPrice(const OptionParameters& params);
double calculatePutPrice(const OptionParameters& params);

// Validate input parameters
bool validateParameters(const OptionParameters& params);

#endif // BLACK_SCHOLES_H 