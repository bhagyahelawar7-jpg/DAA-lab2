#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int travellingSalesman(const vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> vertices;

    for (int i = 0; i < n; i++) {
        if (i != start)
            vertices.push_back(i);
    }

    int min_cost = INT_MAX;

    do {
        int cost = 0;
        int current = start;

        for (int i = 0; i < vertices.size(); i++) {
            cost += graph[current][vertices[i]];
            current = vertices[i];
        }

        cost += graph[current][start];
        min_cost = min(min_cost, cost);

    } while (next_permutation(vertices.begin(), vertices.end()));

    return min_cost;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Minimum cost: " << travellingSalesman(graph, 0);
    return 0;
}
