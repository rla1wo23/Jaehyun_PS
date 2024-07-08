#include <iostream>
#include <vector>
using namespace std;

int n, node, ans;
vector<pair<int, int>> graph[100001];
bool vis[100001] = {
    false,
};
void dfs(int x, int dist)
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
        int next_dist = dist + graph[x][i].second;
        if (!vis[next_node])
        {
            vis[next_node] = true;
            dfs(next_node, next_dist);
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
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    node = 1;
    ans = 0;
    dfs(1, 0);
    ans = 0;
    for (int i = 0; i <= n; i++)
    {
        vis[i] = false;
    }
    dfs(node, 0);
    cout << ans;
}