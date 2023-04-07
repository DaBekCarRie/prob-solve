#include <iostream>
#include <list>
#include <bits/stdc++.h>
using namespace std;
void print(list<long int>::iterator it, list<long int> list1)
{
    it = list1.begin();
    for (; it != list1.end(); ++it)
        cout << *it << '\n';
    cout << endl;
}
int main()
{
    list<long int> list1;
    long int n, m;
    long int x, t, k = 0;
    cin >> n >> m;
    list<long int>::iterator it, iit;
    cin >> x;

    list1.assign(1, x);
    for (long int i = 1; i < n; i++)
    {
        cin >> x;
        list1.push_back(x);
    }
    it = list1.begin();
    for (long int i = 0; i < m; i++)
    {
        // k %= list1.size();
        cin >> t;
        switch (t)
        {
        case 1:
            it = list1.begin();
            // cout << *it << "\n";
            // print(it, list1);
            break;
        case 2:
            // cout << " " << *it << " " << list1.back() << "\n";
            if (*it == list1.back())
            {
                // cout << "XXX\n";
                it = list1.begin();
            }
            else
            {
                it++;
                // cout << *it << "\n";
            }
            //cout << "*it is " << *it << "\n";
            // print(it, list1);
            // cout << *it << "\n";
            break;
        case 3:
            cin >> x;
            list1.insert(it, x);
            // cout << *it << "\n";
            // print(it, list1);

            break;
        case 4:
            cin >> x;
            // cout << "*it is " << *it << "\n";
            iit = it;
            iit++;
            list1.insert(iit, x);
            // cout << "*it is " << *it << "\n";
            // print(it, list1);
            break;
        }
    }
    it = list1.begin();
    for (; it != list1.end(); ++it)
        cout << *it << '\n';
    cout << endl;

    return 0;
}