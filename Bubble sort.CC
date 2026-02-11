#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int travellingSalesman(vector<vector<int> > graph, int start) {
    int n = graph.size();
    vector<int> vertices;

    for (int i = 0; i < n; i++) {
        if (i != start)
            vertices.push_back(i);
    }

    int min_cost = INT_MAX;

    do {
        int cost = graph[start][vertices[0]];

        for (size_t i = 0; i < vertices.size() - 1; i++) {
            cost += graph[vertices[i]][vertices[i + 1]];
        }

        cost += graph[vertices.back()][start];
        min_cost = min(min_cost, cost);

    } while (next_permutation(vertices.begin(), vertices.end()));

    return min_cost;
}

int main() {
    vector<vector<int> > graph(4, vector<int>(4));

    graph[0][0]=0;  graph[0][1]=10; graph[0][2]=15; graph[0][3]=20;
    graph[1][0]=10; graph[1][1]=0;  graph[1][2]=35; graph[1][3]=25;
    graph[2][0]=15; graph[2][1]=35; graph[2][2]=0;  graph[2][3]=30;
    graph[3][0]=20; graph[3][1]=25; graph[3][2]=30; graph[3][3]=0;

    cout << "Minimum cost: " << travellingSalesman(graph, 0);
    return 0;
}