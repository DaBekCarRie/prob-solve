#include <iostream>
#include <vector>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int L, R;
    std::cin >> L >> R;
    
    std::vector<int> primes;
    for (int i = L; i <= R; ++i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    
    int nub = 0;
    for (int i = 1; i < primes.size(); ++i) {
        if (primes[i] - primes[i-1] == 2) {
            nub++;
        }
    }
    
    std::cout << nub << std::endl;
    return 0;
}