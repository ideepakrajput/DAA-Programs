#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> vertex_cost;
typedef pair<pair<int, int>, int> edge_cost;
bool Cycle_Check_1(vector<edge_cost> graph, int *visited, int start, int parent)
{
    // cout<<start<<" ";
    visited[start] = 1;

    for (int j = graph.size() - 1; j > 0; j--)
    {
        if (graph.at(j).first.first == start)
        {
            int i = graph.at(j).first.second;
            if (visited[i] == 1 && i != parent)
            {
                return true;
            }
            if (visited[i] == 0)
            {
                return Cycle_Check_1(graph, visited, i, start);
            }
        }
    }
    return false;
}

bool Cycle_Check_2(vector<edge_cost> graph, int *visited, int start, int parent)
{
    // cout<<start<<" ";
    visited[start] = 1;

    for (int j = 0; j < graph.size(); j++)
    {
        if (graph.at(j).first.first == start)
        {
            int i = graph.at(j).first.second;
            if (visited[i] == 1 && i != parent)
            {
                return true;
            }
            if (visited[i] == 0)
            {
                return Cycle_Check_2(graph, visited, i, start);
            }
        }
    }
    return false;
}

void Set_Zero(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = 0;
    return;
}

int main()
{
    int n = 7;
    vector<edge_cost> graph;
    // First Graph
    // graph.push_back({{0, 1}, 5});
    // graph.push_back({{0, 2}, 3});
    // graph.push_back({{1, 2}, 4});
    // graph.push_back({{1, 3}, 6});
    // graph.push_back({{1, 4}, 2});
    // graph.push_back({{2, 3}, 5});
    // graph.push_back({{2, 5}, 5});
    // graph.push_back({{3, 4}, 6});
    // graph.push_back({{3, 5}, 6});
    // graph.push_back({{4, 5}, 3});
    // graph.push_back({{4, 6}, 4});
    // graph.push_back({{5, 6}, 4});

    // Second Graph
    graph.push_back({{0,1},2});
    graph.push_back({{0,2},3});
    graph.push_back({{1,3},4});
    graph.push_back({{2,4},6});
    graph.push_back({{3,4},5});
    graph.push_back({{3,5},3});
    graph.push_back({{4,5},3});

    sort(graph.begin(), graph.end(), [&](edge_cost &a, edge_cost &b)
         { return a.second < b.second; });

    int a, b, c;
    cout << "Graph-\n";
    for (int i = 0; i < graph.size(); i++)
    {
        a = graph.at(i).first.first;
        b = graph.at(i).first.second;
        c = graph.at(i).second;
        cout << a << "--" << b << "-->" << c << endl;
    }

    vector<edge_cost> result;
    int cost = 0;
    int visited1[n] = {0};
    int visited2[n] = {0};
    vector<int>isolated;
    for (int i = 0; i < graph.size(); i++)
    {
        result.push_back({{graph.at(i).first.first, graph.at(i).first.second}, graph.at(i).second});
        result.push_back({{graph.at(i).first.second, graph.at(i).first.first}, graph.at(i).second});

        cost += graph.at(i).second;
        for (int k = 0; k < n; k++)
        {
            Set_Zero(visited1, n);
            Set_Zero(visited2, n);
            if (Cycle_Check_1(result,visited1,k,-1)||Cycle_Check_2(result,visited2,k,-1))
            {
                cost -= graph.at(i).second;
                result.pop_back();
                result.pop_back();
            }
        }
    }
    cout << "Spanning Tree-\n";
    for (int i = 0; i < result.size(); i++)
    {
        a = result.at(i).first.first;
        b = result.at(i).first.second;
        c = result.at(i).second;
        cout << a << "--" << b << "-->" << c << endl;
    }
    cout << "Size: " << result.size() << endl;
    cout << "Cost: " << cost << endl;
    return 0;
}
