#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

bool vis[100001];
int n, u, v, cost;
int node, ans;
vector<pair<int, int>> graph[100001];

void DFS(int x, int dist)
{
    vis[x] = true;

    if (dist > ans)
    {
        ans = dist;
        node = x;
    }

    for (int i = 0; i < graph[x].size(); i++)
    {
        int next_node = graph[x][i].first;
        int next_dist = graph[x][i].second + dist;
        if (!vis[next_node])
        {
            vis[next_node] = true;
            DFS(next_node, next_dist);
            vis[next_node] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i < n; i++)
    {
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
    ans = 0;
    DFS(1, 0);
    ans = 0;
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    DFS(node, 0);
    cout << ans << '\n';
}