#include <bits/stdc++.h>
using namespace std;
int main()
{
    int count = 0, len, i, pos = 0;
    string s, signals;
    cin >> s >> signals;
    for (i = 0; i < signals.length(); i++)
    {
        if (signals[i] == s[pos])
        {
            pos++;
            pos %= s.length();
            if (pos == 0)
            {
                count++;
            }
        }
    }
    cout << count;
}