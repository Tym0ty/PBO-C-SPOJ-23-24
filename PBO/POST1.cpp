#include <cctype>
#include <cmath>
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

class ExpressionEvaluator {
private:
    char expression[100];

public:
    void setExpression(const char* exp) {
        strncpy(expression, exp, sizeof(expression) - 1);
        expression[sizeof(expression) - 1] = '\0';
    }

    int customRound(double number) {
        return static_cast<int>(number + 0.5 * (number > 0 ? 1 : -1));
    }

    double evaluatePostfix(double x) {
        stack<double> st;
        int i;

        for (i = 0; expression[i]; ++i) {
            if (expression[i] == ' ')
                continue;
            else if (isdigit(expression[i]) || (expression[i] == '-' && isdigit(expression[i+1]))) {
                st.push(atof(&expression[i]));
                while (isdigit(expression[i]) || expression[i] == '-' || expression[i] == '.') {
                    ++i;
                }
                --i;
            } else if (expression[i] == 'x') {
                st.push(x);
            } else {
                double val1 = st.top();
                st.pop();
                double val2 = st.top();
                st.pop();

                switch (expression[i]) {
                    case '+':
                        st.push(val2 + val1);
                        break;
                    case '-':
                        st.push(val2 - val1);
                        break;
                    case '*':
                        st.push(val2 * val1);
                        break;
                    case '/':
                        st.push(val2 / val1);
                        break;
                    case '^':
                        st.push(pow(val2, val1));
                        break;
                }
            }
        }

        return st.top();
    }

    double calculateDerivative(double x) {
        const double h = 0.0001;
        double ans = (evaluatePostfix(x + h) - evaluatePostfix(x - h)) / (2 * h);
        return ans;
    }

    void plotGraph(int grid_size) {
        char grid[grid_size][grid_size];

        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                grid[i][j] = '.';
            }
        }

        for (int x = 0; x < grid_size; ++x) {
            double value = evaluatePostfix(x);
            double derivative = calculateDerivative(x);

            int y_value = customRound(value);
            int dy_value = customRound(derivative);

            if (y_value >= 0 && y_value < grid_size) {
                grid[y_value][x] = '*';
            }

            if (dy_value >= 0 && dy_value < grid_size) {
                grid[dy_value][x] = '+';
            }
        }

        for (int y = grid_size - 1; y >= 0; --y) {
            for (int x = 0; x < grid_size; ++x) {
                cout << grid[y][x];
            }
            cout << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;

    ExpressionEvaluator evaluator;

    while (N--) {
        char input_expression[100];
        scanf(" %[^\n]", input_expression);
        evaluator.setExpression(input_expression);

        const int grid_size = 21;
        evaluator.plotGraph(grid_size);
    }

    return 0;
}
