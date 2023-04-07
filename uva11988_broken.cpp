#include <iostream>
#include <list>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        list<char> l;
        auto it = l.begin();
        for (auto i : s) {
            if (i == '[') {
                it = l.begin();
            } else if (i == ']') {
                it = l.end();
            } else {
                if (it == l.end()) {
                    l.push_back(i);
                } else {
                    it = l.insert(it, i);
                    it++;
                }
            }
        }
        for (auto a : l) {
            cout << a;
        }
        cout << '\n';
    }
    return 0;
}