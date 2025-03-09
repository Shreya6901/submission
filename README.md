# Numerical Methods Assignment 1

This repository contains C++ implementations of various **numerical methods** used for solving mathematical problems related to **differentiation, integration, and equation solving**. Each method is implemented in a separate C++ file with clear user inputs and outputs.

## 📌 **Contents of the Repository**

### **1. Forward Difference Method** (`forward_diff.cpp`)
- Computes forward differences from a given set of data points.
- Useful for numerical differentiation and polynomial interpolation.
- Takes input values of `x` and `y` and outputs forward difference tables.

### **2. Backward Difference Method** (`backward_diff.cpp`)
- Computes backward differences from data points.
- Helps in interpolation and solving difference equations.

### **3. Central Difference Method** (`central_diff.cpp`)
- Calculates central differences, providing more accurate approximations of derivatives.
- Used in **numerical differentiation** and **finite difference methods**.

### **4. Numerical Integration Methods** (`numerical_integration.cpp`)
- Implements the following numerical integration techniques:
  - **Trapezoidal Rule**: Approximates integrals using trapezoids.
  - **Simpson’s 1/3 Rule**: Uses parabolic interpolation for higher accuracy.
  - **Simpson’s 3/8 Rule**: Another Simpson variant for special cases.
- Allows user-defined functions and integration limits.

### **5. Double Integration Methods** (`double_int.cpp`)
- Evaluates double integrals using:
  - **Trapezoidal Rule**
  - **Simpson’s 1/3 Rule**
- Uses iterative integration over both `x` and `y` domains.

### **6. Romberg’s Method for Integration** (`romberg_trapezoidal.cpp`)
- Enhances the accuracy of **Trapezoidal Rule** by applying **Richardson’s Extrapolation**.
- Provides better integral approximations using successive refinements.

### **7. Solving Algebraic and Transcendental Equations** (`root_finding.cpp`)
- Implements methods for solving equations of the form `f(x) = 0`:
  - **Bisection Method**: Finds roots using interval halving.
  - **Newton-Raphson Method**: Uses derivatives for rapid convergence.
  - **Fixed-Point Iteration**: Converts equations into recursive forms.

## 🛠 **How to Compile and Run**
1. Clone this repository:
   ```sh
   git clone https://github.com/Shreya6901/submission-numerical-methods-assignment-1.git
   cd submission-numerical-methods-assignment-1
   ```
2. Compile any C++ file using **g++**:
   ```sh
   g++ -o output forward_diff.cpp
   ```
3. Run the compiled file:
   ```sh
   ./output
   ```

## 📌 **Requirements**
- A C++ compiler (g++, clang, or MSVC).
- Basic knowledge of numerical methods.

## 📜 **License**
This repository is licensed under the **MIT License**. You are free to modify and use the code for educational and research purposes.

## 📧 **Contact**
For any issues or contributions, feel free to open an **Issue** or create a **Pull Request**. Happy coding! 🚀

