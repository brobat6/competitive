#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1E9 + 7; // const MOD

int main() {
    mt19937_64 rng_64(chrono::steady_clock::now().time_since_epoch().count()); // 64-bit random numbers.
    
    int MOD2 = (int)1E9 + 7; // non const MOD

    clock_t first = clock();

    int temp = 0;
    for(int i = 0; i < 1'000'000'00; i++) {
        temp = (temp + rng_64() % MOD) % MOD;
        temp = (temp * rng_64()) % MOD;
        temp = (temp - rng_64() % MOD + MOD) % MOD; 
    }

    clock_t second = clock();

    temp = 0;
    for(int i = 0; i < 1'000'000'00; i++) {
        temp = (temp + rng_64() % MOD2) % MOD2;
        temp = (temp * rng_64()) % MOD2;
        temp = (temp - rng_64() % MOD2 + MOD2) % MOD2; 
    }

    clock_t third = clock();

    cout << "Execution time with const MOD - " << (double)(second - first)/CLOCKS_PER_SEC << '\n';

    cout << "Execution time with non const MOD - " << (double)(third - second)/CLOCKS_PER_SEC << '\n';
}