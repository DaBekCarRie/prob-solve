#include <iostream>
#include <iomanip>
#include <list>

const int MAX_M = 100000;

int main() {
    std::list<int> demo;
    auto its = demo.begin();

    int m, save, check1, check2;
    while (std::cin >> m && m != 0) {
        for (int i = 1; i <= m; i++) {
            demo.insert(its, i);
        }

        if (m == 1) {
            save = 1;
        }

        check1 = m;
        check2 = m - 2;
        std::cout << "Discarded cards:";
        while (demo.size() > 1) {
            if (check1 == m - check2) {
                std::cout << ' ' << demo.front();
            } else {
                std::cout << ' ' << demo.front() << ',';
            }

            demo.pop_front();
            save = demo.front();
            demo.pop_front();
            demo.push_back(save);
            check1--;
        }

        std::cout << '\n' << "Remaining card: " << save << '\n';
        demo.clear();
    }
    return 0;
}