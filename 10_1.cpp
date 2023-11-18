#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> subject;
long long dp[1001][1001];

long long study(int l, int r, int days)
{
    if (l == r)
    {
        return subject[l] * days;
    }
    if (dp[l][r] != 0)
    {
        return dp[l][r];
    }
    else
    {
        return dp[l][r] = max(study(l + 1, r, days + 1) + days * subject[l], study(l, r - 1, days + 1) + days * subject[r]);
    }
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        subject.clear();
        for (int i = 0; i < 1001; i++)
        {
            for (int j = 0; j < 1001; j++)
            {
                dp[i][j] = 0;
            }
        }
        int subject_nums;
        cin >> subject_nums;
        for (int i = 0; i < subject_nums; i++)
        {
            int value;
            cin >> value;
            subject.push_back(value);
        }
        cout << study(0, subject_nums - 1, 1) << "\n";
    }
}
