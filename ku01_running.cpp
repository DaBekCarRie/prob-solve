#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n, k, x;
    long int min = 1000000001;
    long int arr[100100];
    int left = n;
    int count = 0;
    cin >> n >> k;
    for (long int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    // for( long int i =0;i<n;i++){
    //     cout << arr[i] << "\n";

    // }
    // cout << min;
    for (long int i = 0; i < n; i++)
    {

        if ((k * arr[i] - k * min) / arr[i] < 1)
        {
            count++;
        }
    }
    cout << count;
}