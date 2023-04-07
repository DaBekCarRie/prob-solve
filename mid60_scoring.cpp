#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n, m;
    cin >> n >> m;
    long int arr[111][5];
    long int num, score, sum = 0;
    for (long int i = 0; i < 110; i++)
    {
        arr[i][1] = 0;
        arr[i][2] = 0;
    }
    for (long int i = 0; i < m; i++)
    {
        cin >> num >> score;
        if (score > arr[num][1])
        {
            arr[num][1] = score;
        }
        arr[num][2]++;
        // cout << "arr[" << num << "][2] == " << arr[num][2] << "\n";
        if (arr[num][2] > 5)
        {
            // cout << "gern"
            //  << "\n";
            arr[num][1] = 0;
        }
        // cout << "now = " << arr[num][1] << "\n";
    }

    for (long int i = 0; i < 110; i++)
    {
        // cout << "arr[" << i << "][1] = " << arr[i][1] << "\n";
        sum += arr[i][1];
    }
    cout << sum;
}