# SUPA C++ Assignment 2: Finite Functions & Metropolis Sampling

**Date:** 12th December 2025

## Project Overview

The project consists of three main parts:
1.  **Fitting**: Implementing various probability distribution classes (`Normal`, `Cauchy-Lorentz`, and `Crystal Ball`) inheriting from a base `FiniteFunction` class to fit the provided data.
2.  **Sampling**: Implementing the **Metropolis algorithm** within the base class to generate pseudo-data based on the fitted distribution.
3.  **Bonus**: A Monte Carlo simulation to estimate the value of $\pi$.


## File Structure

* **`FiniteFunctions.h/.cxx`**: The base class. Handles numerical integration, plotting, and the implementation of the **Metropolis sampling algorithm**.
* **`AdvancedFunctions.h/.cxx`**: Contains derived classes for specific distributions:
    * `NormalDistribution`
    * `CauchyDistribution`
    * `CrystalDistribution` (Used for the final best fit).
* **`TestFiniteFunctions.cxx`**: The main executable script. It loads the data, instantiates the Crystal Ball distribution, runs the Metropolis sampler, and generates comparison plots.
* **`CalculatePi.cxx`**: (Bonus) A script using Monte Carlo methods to estimate $\pi$.
* **`Makefile`**: The build script configuration.

## Compilation

A `Makefile` is provided to automate the build process.

### 1. Build Everything (Main + Bonus)
To compile both the main assignment (`TestFiniteFunctions`) and the bonus task (`CalculatePi`) at once, simply run:

```bash
make
```

### 2. Clean Build Files
To remove intermediate object files (`.o`) but keep the executables (automatically called after `make`):

```bash
make clean
```

### 3. Full Reset
To remove all object files and the executables:

```bash
make cleantarget
```

## Running the Code

### Part 1: Distribution Fitting & Sampling
After compiling, run the main executable:

```bash
./TestFiniteFunctions
```

**What it does:**
1.  Loads the mystery data from `../../Data/MysteryData22212.txt` (path may vary based on your local setup).
2.  Fits a **Crystal Ball distribution** with optimized parameters ($\mu=0.0, \sigma=1.92, \alpha=1.5, n=2.0$).
3.  Runs the **Metropolis algorithm** to generate 100,000 pseudo-data points.
4.  Generates a plot comparing the analytical function, original data (black dots), and sampled pseudo-data (blue crosses).

**Output:**
* The resulting plot will be saved to: `Plots/CrystalBall.png`

### Part 2: Bonus - Calculating Pi
To run the Monte Carlo Pi estimation:

```bash
./CalculatePi <radius> <n_samples>
```

**Example (High Precision):**
```bash
./CalculatePi 1.0 100000000
```
* `radius`: The radius of the circle/half-width of the square (e.g., 1.0).
* `n_samples`: The number of random points to generate (use a large number like `100000000` for better precision).


---
**Note:** Ensure that the `Plots/` directories exist before running the code to avoid file I/O errors.