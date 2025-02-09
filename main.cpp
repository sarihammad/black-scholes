#include "src/black_scholes.h"
#include <iostream>
#include <iomanip>

void printOptionPrices(const OptionParameters& params) {
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "\nOption Prices:\n";
    std::cout << "Call Option: $" << calculateCallPrice(params) << "\n";
    std::cout << "Put Option:  $" << calculatePutPrice(params) << "\n";
}

OptionParameters getInputParameters() {
    OptionParameters params;
    
    std::cout << "Enter stock price: $";
    std::cin >> params.stockPrice;
    
    std::cout << "Enter strike price: $";
    std::cin >> params.strikePrice;
    
    std::cout << "Enter time to maturity (in years): ";
    std::cin >> params.timeToMaturity;
    
    std::cout << "Enter risk-free rate (as decimal): ";
    std::cin >> params.riskFreeRate;
    
    std::cout << "Enter volatility (as decimal): ";
    std::cin >> params.volatility;
    
    return params;
}

int main() {
    std::cout << "Black-Scholes Option Pricing Calculator\n";
    std::cout << "======================================\n\n";
    
    OptionParameters params = getInputParameters();
    
    if (!validateParameters(params)) {
        std::cout << "Error: Invalid parameters provided.\n";
        return 1;
    }
    
    printOptionPrices(params);
    return 0;
} 