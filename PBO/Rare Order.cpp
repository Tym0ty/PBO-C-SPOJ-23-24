#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <unordered_set>
using namespace std;

struct TopologicalSort {
    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> in_degree;
    unordered_set<char> visited;
    stack<char> resultStack;

    void initializeGraph() {
        string input;
        while (getline(cin, input) && input != "#") {
            while (input != "#") {
                for (char &c : input) {
                    if (in_degree.find(c) == in_degree.end()) {
                        in_degree[c] = 0;
                        graph[c] = vector<char>();
                    }
                }
                string next_input;
                if (getline(cin, next_input) && next_input == "#") break;
                int i = 0;
                while (i < input.size() && i < next_input.size() && input[i] == next_input[i]) {
                    i++;
                }
                if (i < input.size() && i < next_input.size()) {
                    graph[input[i]].push_back(next_input[i]);
                    in_degree[next_input[i]]++;
                }
                input = next_input;
            }

            topologicalSort();
            graph.clear();
            in_degree.clear();
            visited.clear();
            while (!resultStack.empty()) {
                resultStack.pop();
            }
        }
    }

    void topologicalSort() {
        for (auto &p : in_degree) {
            if (!visited.count(p.first)) {
                dfs(p.first);
            }
        }

        while (!resultStack.empty()) {
            cout << resultStack.top();
            resultStack.pop();
        }
        cout << endl;
    }

    void dfs(char node) {
        visited.insert(node);

        for (char &neighbor : graph[node]) {
            if (!visited.count(neighbor)) {
                dfs(neighbor);
            }
        }

        resultStack.push(node);
    }
};

int main() {
    TopologicalSort topSort;
    topSort.initializeGraph();

    return 0;
}

