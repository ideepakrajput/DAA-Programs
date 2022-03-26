#include<bits/stdc++.h>
using namespace std;

bool Search(vector<int> vec , int s)
{
    for(int i=0 ; i<vec.size() ; i++)
    if (vec.at(i)==s) return true;

    return false;
}

int main()
{
    int n=10;
 
    int graph[n][n]={
        {0,1,0,1,0,0,0,0,0,0},
        {1,0,1,0,1,0,1,1,0,0},
        {0,1,0,1,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,1,1,1,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,1,0,0,1,0,0,1,0,0},
        {0,1,0,0,1,0,1,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0}
    };

    vector<int> result;
    queue<int> q;
    int visited[n]={0};
    result.push_back(1);
    visited[0]=1;
    q.push(0);

    while(!q.empty())
    {
        int i=q.front();
        for(int j=i+1 ; j<n ; j++)
        {
            if(graph[i][j]==1 && (visited[j]==0))
            {
                q.push(j);
                result.push_back(j+1);
                visited[j]=1;
            }
        }
        q.pop();
    }

    for(int i=0 ; i<result.size() ; i++)
    cout<<result.at(i)<<"  ";
    cout<<endl;
    return 0;
}