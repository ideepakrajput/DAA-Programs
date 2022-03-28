#include <bits/stdc++.h>
using namespace std;

void DFS(int *graph, int n, int *visited, int start)
{
    cout << start << " ";
    visited[start] = 1;
    for (int j = 0; j < n; j++)
    {
        if (graph[start * n + j] == 1 && visited[j] == 0)
        {
            DFS((int *)graph, n, visited, j);
        }
    }
    return;
}

int main()
{
    int n = 10;

    int graph[n][n] = {
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 0, 1, 1},
        {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}};

    int visited[n] = {0};
    cout << "DFS Traversal :- ";
    DFS((int *)graph, n, visited, 0);
    return 0;
}