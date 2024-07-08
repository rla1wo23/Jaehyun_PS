#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        vector<int> bi;
        vector<int> in;
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            bi.push_back(i + 1);
            in.push_back(i + 1);
        }
        int vic = 0;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            in[a - 1] = 100001 + i;
            bi[b - 1] = 100001 + i;
            if (a >= b)
            {
                vic++;
            }
        }
        sort(in.begin(), in.end());
        sort(bi.begin(), bi.end());
        int indx = 0;
        int bidx = 0;
        while (indx < n - m && bidx < n - m)
        {
            if (in[indx] >= bi[bidx])
            {
                vic++;
                indx++;
                bidx++;
            }
            else
            {
                indx++;
            }
        }
        if (vic * 2 > n)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}