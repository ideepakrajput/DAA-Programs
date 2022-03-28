#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> vertex_cost;

int main()
{
    int n = 5;
    vector<vertex_cost> graph[n];
    graph[0].push_back({1, 2});
    graph[0].push_back({3, 6});
    graph[1].push_back({0, 2});
    graph[1].push_back({2, 3});
    graph[1].push_back({4, 5});
    graph[1].push_back({3, 8});
    graph[2].push_back({1, 3});
    graph[2].push_back({4, 7});
    graph[3].push_back({0, 6});
    graph[3].push_back({1, 8});
    graph[4].push_back({1, 5});
    graph[4].push_back({2, 7});


    int key[n];
    for(int i=0 ; i<n ; i++)
    {
        if(i==0)
        key[i]=0;
        else
        key[i]=INT16_MAX;
    }

    int Parent[n];
    for(int i=0 ; i<n ; i++)
    Parent[i]=-1;
    bool MST[n] = {false};
    int index;
    int cost = 0;
    int i = key[0];

    for (int count = 1; count <= n - 1; count++)
    {        
        int min = INT8_MAX;
        for (int k = 0; k < n; k++)
        {
            if (MST[k]==false && key[k] < min)
            {
                i = k;
                min = key[k];
            }
        }
        MST[i] = true;
        cost += min;
        
        for (int j = 0; j < graph[i].size(); j++)
        {
            if (MST[graph[i].at(j).first]==false && (key[graph[i].at(j).first] == INT16_MAX || key[graph[i].at(j).first] > graph[i].at(j).second))
            {
                Parent[graph[i].at(j).first] = i;
                key[graph[i].at(j).first] = graph[i].at(j).second;
            }
        }

    }
    cout<<"Minimum Spanning Tree-"<<endl;
    for (int i = 1; i < n; i++)
    {
        cout << i << "---" << Parent[i] << endl;
    }
    cout<<"Cost: "<<cost<<endl;
    return 0;
}