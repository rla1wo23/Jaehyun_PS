#include <iostream>
#include <algorithm>
using namespace std;
int value[1001] = {
    0,
};
long long dp[1001][1001];
long long study(int l, int r, int days)
{
    if (l == r)
    {
        return value[l] * days;
    }
    if (dp[l][r] != 0)
    {
        return dp[l][r];
    }
    else
    {
        return dp[l][r] = max(study(l + 1, r, days + 1) + value[l] * days, study(l, r - 1, days + 1) + value[r] * days);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        for (int i = 0; i < 1001; i++)
        {
            value[i] = 0;
        }
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = 0;
            }
        }
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            value[i] = num;
        }
        cout << study(0, n - 1, 1) << "\n";
    }
}