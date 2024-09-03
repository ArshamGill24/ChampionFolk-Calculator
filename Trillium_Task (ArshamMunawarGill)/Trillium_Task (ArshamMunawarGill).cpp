#include <iostream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

// Function to perform the calculation
void calculator(int num1, int num2) {
    cout << "Calculator operations:" << endl;
    cout << "1. Addition (" << num1 << " + " << num2 << "): " << num1 + num2 << endl;
    cout << "2. Subtraction (" << num1 << " - " << num2 << "): " << num1 - num2 << endl;
    cout << "3. Multiplication (" << num1 << " * " << num2 << "): " << num1 * num2 << endl;
    if (num2 != 0) {
        cout << "4. Division (" << num1 << " / " << num2 << "): " << num1 / num2 << endl;
    }
    else {
        cout << "4. Division: Error (Division by zero is not allowed)" << endl;
    }
}

// Function to launch the Windows Calculator application
void launchCalculatorApp() {
#ifdef _WIN32
    // Launch Windows Calculator
    system("calc");
#else
    cout << "Windows Calculator can only be launched on a Windows system." << endl;
#endif
}

int main(int argc, char* argv[]) {
    try {
        // Check if the correct number of arguments are passed
        if (argc != 4) {
            throw invalid_argument("Incorrect number of arguments. Usage: <program> <string> <int> <int>");
        }

        // Retrieve arguments
        string firstArg = argv[1];
        int secondArg = stoi(argv[2]);
        int thirdArg = stoi(argv[3]);

        // Check if the first argument is "ChampionFolk"
        if (firstArg == "ChampionFolk") {
            // Launch Windows Calculator if on a Windows system
            launchCalculatorApp();

            // Execute the calculator function
            calculator(secondArg, thirdArg);
        }
        else {
            throw invalid_argument("The first argument must be 'ChampionFolk'.");
        }
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    return 0;
}

