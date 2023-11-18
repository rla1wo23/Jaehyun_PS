#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int>> graph[100001];
bool vis[100001] = {
    false,
};
int ans = 0, node = 1;

void dfs(int x, int dist)
{
    if (dist > ans)
    {
        ans = dist;
        node = x;
    }
    vis[x] = true;
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
    int n;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    ans = 0;
    dfs(1, 0);
    ans = 0;
    for (int i = 0; i <= n; i++)
        vis[i] = false;
    dfs(node, 0);
    cout << ans;
}