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
        string str;
        cin >> str;
        stack<int> s;
        s.push(-1);
        int mx = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'C')
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