#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e5;
vector<int> graph[N];
int vis[N];

void dfs(int u)
{
    vis[u] = 1;
    for (auto v : graph[u])
    {
        if (vis[v] == 0)
        {
            dfs(v);
        }
    }
}

int main()
{
    int n, e;
    // Number of Node and Edge
    cin >> n >> e;
    
    // Visited array 0
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < e; i++)
    {
        // node a to b and b to a
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a); // remove if directed graph
    }
    // Calling DFS function from a node
    int cnt=0;
    for (int i = 1; i <=n; i++)
    {
        if(vis[i]==0){
            dfs(i);
            cnt++;
        }
    }
    cout<<"Number of Component: "<<cnt<<endl;


}
