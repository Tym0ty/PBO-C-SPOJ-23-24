#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    // Initialize the array
    vector<int> array(N, 0);

    // Process each query
    for (int q = 0; q < Q; ++q) {
        int a, b;
        cin >> a >> b;
        int start_index = max(1, a - 2 * b);
        int end_index = min(N, a + 2 * b);

        // Update the valid indices
        for (int i = start_index - 1; i < end_index; ++i) {
            array[i]++;
        }
    }

    // Print the final array
    for (int i = 0; i < N; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;

    return 0;
}
