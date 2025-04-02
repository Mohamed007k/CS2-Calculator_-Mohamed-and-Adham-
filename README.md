# Calculator Program

## Introduction
This is a simple command-line calculator that allows users to input mathematical expressions and receive the computed result. The program supports basic arithmetic operations such as addition, subtraction, multiplication, and division. It also includes additional functionalities such as factorial, greatest common divisor (GCD), least common multiple (LCM), and random number generation.

## Features
- Supports addition (+), subtraction (-), multiplication (*), and division (/).
- Handles expressions with parentheses.
- Uses an infix to postfix conversion algorithm for evaluation.
- Prevents division by zero errors.
- Includes additional mathematical functions like factorial, GCD, and LCM.

## Files in the Project
### 1. `test.cpp`
This is the main entry point of the program. It:
- Welcomes the user and provides instructions.
- Continuously reads user input and evaluates expressions.
- Calls `evaluateExpression()` from `calculator.cpp` to compute results.
- Handles exceptions, such as division by zero.

### 2. `calculator.h`
This is the header file that declares all the functions used in the program. It contains:
- Arithmetic functions: `add()`, `subtract()`, `multiply()`, `divide()`.
- Additional functions: `factorial()`, `gcd()`, `lcm()`, `randomInRange()`.
- `evaluateExpression()` to process input expressions.

### 3. `calculator.cpp`
This file contains the implementation of the functions declared in `calculator.h`. It:
- Defines arithmetic functions.
- Implements an infix to postfix conversion for mathematical expressions.
- Evaluates postfix expressions using a stack.
- Initializes operator precedence for parsing expressions correctly.

### 4. `CMakeLists.txt`
This is a CMake configuration file that:
- Specifies the minimum required CMake version.
- Defines the project name (`CS2_Calculator`).
- Lists the source files (`calculator.cpp`, `test.cpp`).
- Creates an executable named `trial`.

## How to Run the Code for the First Time
If you're running the code for the first time, follow these steps:

### Using CMake (Recommended)
1. Ensure you have CMake installed.
2. Open a terminal in the project directory and run:
   ```sh
   mkdir build
   cd build
   cmake ..
   make
   ```
3. Run the program:
   ```sh
   ./trial
   ```

### Using g++
Alternatively, you can compile manually using g++:
```sh
g++ test.cpp calculator.cpp -o calculator
./calculator
```

## Step-by-Step Code Development
1. **Define the problem**:
   - The goal was to create a calculator that can evaluate user-entered mathematical expressions.
   - The calculator should handle different operators and follow correct mathematical precedence.
   
2. **Design the header file (`calculator.h`)**:
   - Declared function prototypes for arithmetic operations (`add()`, `subtract()`, `multiply()`, `divide()`).
   - Added function prototypes for additional mathematical operations like factorial, GCD, and LCM.
   - Declared `evaluateExpression()` for parsing and computing user expressions.
   - Defined a precedence system for handling order of operations.
   
3. **Implement the functions in `calculator.cpp`**:
   - **Basic Arithmetic Functions**:
     - Implemented `add()`, `subtract()`, `multiply()`, and `divide()`, ensuring proper return values.
     - Included error handling for division by zero in `divide()`.
   - **Factorial, GCD, and LCM Functions**:
     - Implemented `factorial()` using a recursive approach.
     - Implemented `gcd()` using the Euclidean algorithm.
     - Implemented `lcm()` using the relationship `lcm(a, b) = (a * b) / gcd(a, b)`.
   - **Expression Evaluation**:
     - Implemented an infix-to-postfix conversion using the Shunting Yard algorithm.
     - Used a stack-based approach to evaluate the postfix expressions.
     - Managed operator precedence and parentheses correctly.
     
4. **Write the main program (`test.cpp`)**:
   - Displayed a welcome message and user instructions.
   - Created a loop to continuously prompt the user for expressions.
   - Captured user input using `getline()`.
   - Checked for the keyword `"exit"` to allow users to quit the program.
   - Passed valid expressions to `evaluateExpression()`.
   - Used `try-catch` blocks to handle errors like invalid expressions or division by zero.
   
5. **Configure CMake (`CMakeLists.txt`)**:
   - Specified the minimum required CMake version.
   - Defined the project name (`CS2_Calculator`).
   - Listed the required source files (`calculator.cpp`, `test.cpp`).
   - Created an executable target named `trial`.
   
6. **Test the program**:
   - Ran test cases with various mathematical expressions.
   - Checked operations with different precedence levels (e.g., `3 + 4 * 2`, `(5 + 6) / 2`).
   - Tested edge cases such as division by zero and negative factorials.
   - Debugged and optimized calculations for efficiency.

## Usage
1. Run the program.
2. Enter mathematical expressions like:
   ```
   (3 + 4.5) * 2 / 5
   ```
3. View the computed result.
4. Type `exit` to quit.

## Error Handling
- Division by zero is detected and prevented.
- Invalid input expressions generate error messages.

## Future Enhancements
- Support for exponentiation.
- More advanced mathematical functions.
- Improved user interface.

Enjoy your calculator!
