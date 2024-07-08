#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string full_map;
        cin >> full_map;
        stack<int> s;
        s.push(-1);
        int mx = 0;
        for (int i = 0; i < full_map.size(); i++)
        {
            if (full_map[i] == 'C')
            {
                s.push(i);
            }
            else
            {
                s.pop();
                if (s.empty())
                {
                    s.push(i);
                    continue;
                }
                int t = s.top();
                mx = max(i - t, mx);
            }
        }
        cout << mx << "\n";
    }
}