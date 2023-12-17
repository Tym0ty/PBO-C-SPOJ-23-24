#include <iostream>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

int ex = 0;

int evaluatePostfix(char exp[100], int x) {
    stack<int> st;
    int i;

    for (i = 0; exp[i]; ++i) {
        if (exp[i] == ' ')
            continue;
        else if (exp[i] == 'x') {
            st.push(x);
        } else if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (int)(exp[i] - '0');
                i++;
            }
            i--;
            st.push(num);
        } else {
            if (st.size() < 2) {
                cerr << "Error: Not enough operands for operator " << exp[i] << endl;
                exit(1);
            }

            int val1 = st.top();
            st.pop();
            int val2 = st.top();
            st.pop();

            switch (exp[i]) {
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
                    if (val1 == 0) {
                        cerr << "Error: Division by zero" << endl;
                        exit(1);
                    }
                    st.push(val2 / val1);
                    break;
                case '^':
                    st.push(pow(val2, val1));
                    break;
                default:
                    cerr << "Error: Unknown operator " << exp[i] << endl;
                    exit(1);
            }
        }
    }

    if (st.size() != 1) {
        cerr << "Error: Invalid expression" << endl;
        exit(1);
    }

    return st.top();
}


int main() {
    int N;
    cin >> N;

    while (N--) {
        ex = 0;
        char exp[100];
        cin.ignore(); // Clear input buffer
        cin.getline(exp, sizeof(exp));

        const int grid_size = 21;
        char grid[grid_size][grid_size];

        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                grid[i][j] = '.';
            }
        }

        for (int i = 0; i < grid_size; i++) {
            int y = ceil(evaluatePostfix(exp, i));
            grid[grid_size - y - 1][i] = '*';

            int der = y - ex;
            der = abs(der);
            grid[grid_size - der - 1][i] = '+';
            ex = y;
        }

        for (int i = 0; i < grid_size; ++i) {
            for (int j = 0; j < grid_size; ++j) {
                cout << grid[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}

