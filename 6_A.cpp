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
        vector<int> inha;
        vector<int> bir;
        int N, M;
        cin >> N >> M;
        inha.push_back(0);
        bir.push_back(0);
        for (int i = 1; i <= N; i++)
        {
            inha.push_back(i);
            bir.push_back(i);
        }
        int vic = 0;
        for (int i = 1; i <= M; i++)
        {
            int a, b;
            cin >> a >> b;
            inha[a] = 100001 + i;
            bir[b] = 100001 + i;
            if (a >= b)
            {
                vic++;
            }
        }
        sort(inha.begin(), inha.end());
        sort(bir.begin(), bir.end());
        int iIdx = 1;
        int bIdx = 1;
        while (iIdx <= N - M && bIdx <= N - M)
        {
            if (inha[iIdx] >= bir[bIdx])
            {
                vic++;
                iIdx++;
                bIdx++;
            }
            else
            {
                iIdx++;
            }
        }
        if (vic > N / 2)
        {
            cout << 1 << "\n";
        }
        else
        {
            cout << 0 << "\n";
        }
    }
}