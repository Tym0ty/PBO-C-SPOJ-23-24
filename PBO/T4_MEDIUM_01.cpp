#include <iostream>
#include <deque>
#include <stack>
using namespace std;

int main() {
    int itr;
    cin >> itr;
    char viet[300000];

    while (itr--) {
        int x;
        char y;
        
        scanf("%d %c",&x,&y);
        scanf("%s",&viet);

        deque<char> dq;
        stack<char> st;

        for (int i = 0;i<x;i++)
        {
            dq.push_back(viet[i]);
            st.push(viet[i]);
        }

        while (!st.empty()) {
            dq.push_front(st.top());
            st.pop();
        }

        int count = 0;

        for (int i = 0; i < dq.size(); i++) {
            int temp = 0;
            if (dq.front() == y) {
                while (dq.front() != 'x' && !dq.empty()) { 
                    temp++;
                    dq.pop_front();
                }
                if (temp > count) {
                    count = temp;
                }
            } else {
                dq.pop_front();
            }
        }

        cout << count << endl;
    }

    return 0;
}
