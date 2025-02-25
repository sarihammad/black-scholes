# Black-Scholes Option Pricing Calculator

This C++ implementation of the Black-Scholes option pricing model provides a command-line interface for calculating European-style option prices. The project implements the fundamental mathematical framework used in financial economics for options pricing.

## The Black-Scholes Model

The Black-Scholes model, also known as the Black-Scholes-Merton (BSM) model, was developed by Fischer Black, Myron Scholes, and Robert Merton in 1973. It revolutionized the field of option pricing and derivatives trading.

### The Formula

The Black-Scholes formula for a European call option is:

\[ C = S_0N(d_1) - Ke^{-rT}N(d_2) \]

For a European put option:

\[ P = Ke^{-rT}N(-d_2) - S_0N(-d_1) \]

Where:

\[ d_1 = \frac{\ln(S_0/K) + (r + \sigma^2/2)T}{\sigma\sqrt{T}} \]

\[ d_2 = d_1 - \sigma\sqrt{T} \]

Parameters:

- \( C \) = Call option price
- \( P \) = Put option price
- \( S_0 \) = Current stock price
- \( K \) = Strike price
- \( r \) = Risk-free interest rate
- \( T \) = Time to expiration (in years)
- \( \sigma \) = Volatility of the underlying asset
- \( N(\cdot) \) = Cumulative distribution function of the standard normal distribution

### Key Assumptions

1. The stock price follows a geometric Brownian motion with constant volatility
2. No arbitrage opportunities
3. Risk-free interest rate is constant
4. No transaction costs or taxes
5. Stock pays no dividends
6. Options are European style (can only be exercised at expiration)
7. Markets are efficient (prices reflect all available information)

## Project Overview

This C++ calculator provides a command-line interface to:

- Calculate European call and put option prices using the Black-Scholes model
- Input and validate option parameters
- Get immediate pricing results with precise decimal output

## Getting Started

### Prerequisites

- C++ compiler with C++11 support or later
- Make build system

### Building the Project

1. Clone the repository:

```bash
git clone [your-repository-url]
cd black-scholes
```

2. Build the project using make:

```bash
make
```

3. Run the calculator:

```bash
./black-scholes
```

## Usage

The program will prompt you to enter the following parameters:

- Stock price (S₀)
- Strike price (K)
- Time to maturity (in years)
- Risk-free interest rate (as decimal)
- Volatility (as decimal)

Example interaction:

```
Black-Scholes Option Pricing Calculator
======================================

Enter stock price: $100
Enter strike price: $100
Enter time to maturity (in years): 1
Enter risk-free rate (as decimal): 0.05
Enter volatility (as decimal): 0.2

Option Prices:
Call Option: $10.4506
Put Option:  $5.4506
```

## Implementation Details

The project is structured as follows:

- `main.cpp`: User interface and program entry point
- `src/black_scholes.h`: Core Black-Scholes calculations and parameter definitions
- `src/black_scholes.cpp`: Implementation of the Black-Scholes formulas
- `Makefile`: Build configuration

The implementation uses the following key components:

```cpp
struct OptionParameters {
    double stockPrice;     // Current stock price (S_0)
    double strikePrice;    // Strike price (K)
    double timeToMaturity; // Time to expiration in years (T)
    double riskFreeRate;   // Risk-free interest rate (r)
    double volatility;     // Volatility of the stock (sigma)
};
```

Key functions:

- `calculateCallPrice()`: Computes European call option price
- `calculatePutPrice()`: Computes European put option price
- `validateParameters()`: Ensures input parameters are within valid ranges

## Features

- Real-time option price calculations
- Interactive input parameters
- Visualization of pricing scenarios
- Support for both call and put options
- Greek calculations for risk analysis

## Mathematical Implementation

The project implements the Black-Scholes equations using numerical methods and approximations for the normal cumulative distribution function. Key calculations include:

1. Option Price Calculation
2. Greeks Calculation:
   - Delta (∂V/∂S) - Rate of change in option value with respect to underlying price
   - Gamma (∂²V/∂S²) - Rate of change in Delta
   - Theta (∂V/∂t) - Time decay of option value
   - Vega (∂V/∂σ) - Sensitivity to volatility changes
   - Rho (∂V/∂r) - Sensitivity to interest rate changes

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

[License information will be added based on your project's requirements]

## References

1. Black, F., & Scholes, M. (1973). The Pricing of Options and Corporate Liabilities. Journal of Political Economy, 81(3), 637-654.
2. Hull, J. C. Options, Futures, and Other Derivatives.
