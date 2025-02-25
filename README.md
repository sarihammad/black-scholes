# Black-Scholes Option Pricing Calculator

This C++ implementation calculates European-style option prices using the Black-Scholes model, a fundamental framework in financial economics.

## The Black-Scholes Model

The Black-Scholes formula for a European call option is:

$$
C = S_0 N(d_1) - K e^{-rT} N(d_2)
$$

For a European put option:

$$
P = K e^{-rT} N(-d_2) - S_0 N(-d_1)
$$

Where:

$$
d_1 = \frac{\ln\left(\frac{S_0}{K}\right) + \left(r + \frac{\sigma^2}{2}\right)T}{\sigma\sqrt{T}}, \quad d_2 = d_1 - \sigma\sqrt{T}
$$

### Parameters

- \( C \) = Call option price
- \( P \) = Put option price
- \( S_0 \) = Current stock price
- \( K \) = Strike price
- \( r \) = Risk-free interest rate
- \( T \) = Time to expiration (in years)
- \( \sigma \) = Volatility of the underlying asset
- \( N(\cdot) \) = Cumulative distribution function of the standard normal distribution

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

The program prompts for the following parameters:

- Stock price (\( S_0 \))
- Strike price (\( K \))
- Time to maturity (in years, \( T \))
- Risk-free interest rate (as decimal, \( r \))
- Volatility (as decimal, \( \sigma \))

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

The project includes:

- `main.cpp`: User interface and program entry point
- `src/black_scholes.h`: Core calculations and parameter definitions
- `src/black_scholes.cpp`: Implementation of the Black-Scholes formulas
- `Makefile`: Build configuration


## References

1. Black, F., & Scholes, M. (1973). The Pricing of Options and Corporate Liabilities. Journal of Political Economy, 81(3), 637-654.
2. Hull, J. C. Options, Futures, and Other Derivatives.
