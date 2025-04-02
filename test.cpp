#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    cout << "Welcome to the Calculator!" << endl;
    cout << "You can enter expressions like: (3 + 4.5) * 2 / 5" << endl;
    cout << "Type 'exit' to quit." << endl;

    string input;
    while (true) {
        cout << "\nEnter an expression: ";
        getline(cin, input);

        if (input == "exit") {
            cout << "Goodbye!" << endl;
            break;
        }

        try {
            double result = evaluateExpression(input);
            cout << "Result: " << result << endl;
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}

