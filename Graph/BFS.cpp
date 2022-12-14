#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define mod 100000007
const int N = 2e5;
vector<int> graph[N];
int vis[N];
void bfs(int src){
    queue<int>q;
    q.push(src);
    vis[src]=1;
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v: graph[u]){
            if(!vis[v]){
                q.push(v);
                vis[v]=1;
            }
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
    
    bfs(1);
}
