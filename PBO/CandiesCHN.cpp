#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    while (n--)
    {
        int t, k;
        cin >> t >> k;

        deque<int> q;
        int arr[t];  // Array to store the elements

        for (int i = 0; i < t; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < t; i++)
        {
            while (!q.empty() && q.front() < i - k + 1)
                q.pop_front();

            while (!q.empty() && arr[q.back()] < arr[i])
                q.pop_back();

            q.push_back(i);

            if (i >= k - 1)
                cout << arr[q.front()] << " ";
        }
        cout << endl;
    }

    return 0;
}

