#include <iostream>
#include <string>
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
        string ts;
        cin >> ts;
        sort(str.begin(), str.end());
        sort(ts.begin(), ts.end());
        if (ts.size() != str.size())
        {
            break;
        }
        int chk = 0;
        for (int i = 0; i < ts.size(); i++)
        {
            if (str[i] != ts[i])
            {
                cout << "F" << endl;
                chk = 1;
                break;
            }
        }
        if (chk == 0)
        {
            cout << "T" << endl;
        }
    }
}