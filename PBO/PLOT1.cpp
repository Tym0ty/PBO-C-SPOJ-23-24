#include <iostream>
#include <string> // Include this line
#include <vector>
#include <cmath>

using namespace std;

// Function to evaluate RPN expression
int evaluate_rpn(string& expression, int x) {
    vector<int> stack;
    string token;
    size_t pos = 0;
    while ((pos = expression.find(' ')) != string::npos) {
        token = expression.substr(0, pos);
        expression.erase(0, pos + 1);
        if (token == "x") {
            stack.push_back(x);
        } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            stack.push_back(stoi(token));
        } else {
            int b = stack.back();
            stack.pop_back();
            int a = stack.back();
            stack.pop_back();
            if (token == "+") {
                stack.push_back(a + b);
            } else if (token == "-") {
                stack.push_back(a - b);
            } else if (token == "*") {
                stack.push_back(a * b);
            } else if (token == "/") {
                stack.push_back(a / b);
            } else if (token == "^") {
                stack.push_back(pow(a, b));
            }
        }
    }
    return round(stack[0]);
}

int main() {
    int N;
    cin >> N;
    cin.ignore();  // Consume the newline character

    vector<string> functions(N);
    for (int i = 0; i < N; ++i) {
        getline(cin, functions[i]);
    }

    const int grid_size = 21;
    char grid[grid_size][grid_size];

    // Initialize the grid with dots
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            grid[i][j] = '.';
        }
    }

    // Calculate and plot the values for the function
    for (int x = 0; x < grid_size; ++x) {
        int y = evaluate_rpn(functions[0], x);
        grid[y][x] = '*';
    }

    // Calculate and plot the derivative
    for (int x = 1; x < grid_size; ++x) {
        int y = evaluate_rpn(functions[0], x) - evaluate_rpn(functions[0], x - 1);
        grid[y][x] = '+';
    }

    // Output the grid
    for (int i = 0; i < grid_size; ++i) {
        for (int j = 0; j < grid_size; ++j) {
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}

