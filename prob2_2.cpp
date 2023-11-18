#include <iostream>
using namespace std;

int main()
{
    int dp[10000002];
    dp[0] = 1;
    dp[1] = 1;
    int tmp = 2; // 이제 구해야 할 수를 저장하는 것
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n > tmp)
        {
            for (int i = tmp; i <= n; i++)
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
        }
        cout << dp[n] << "n";
    }
}