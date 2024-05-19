#include "sundaram.h"


std::vector<int> sieve(int n) {
    std::vector<int> primes;
    if (n < 2) return primes;

    int n_new = (n - 1) / 2;
    std::vector<bool> is_prime(n_new + 1, true);

    for (int i = 1; i <= n_new; ++i) {
        for (int j = i; (i + j + 2 * i * j) <= n_new; ++j) {
            is_prime[i + j + 2 * i * j] = false;
        }
    }

    if (n >= 2) primes.push_back(2);

    for (int i = 1; i <= n_new; ++i) {
        if (is_prime[i]) {
            primes.push_back(2 * i + 1);
        }
    }

    return primes;
}
