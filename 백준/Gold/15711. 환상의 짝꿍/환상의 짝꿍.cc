#include <iostream>
#include <vector>
using namespace std;
#define MAX 2000001
bool table[MAX] = {0};

void generatePrimes(vector<long long> &primes) {
    for (long long i = 2; i < MAX; i++) {
        if (!table[i]) {
            primes.push_back(i);
            for (long long j = i * i; j < MAX; j += i) {
                table[j] = 1;
            }
        }
    }
}

bool isPrime(long long x, const vector<long long> &primes) {
    if (x < 2) return false;
    if (x < MAX) return !table[x];
    for (long long p : primes) {
        if (p * p > x) break;
        if (x % p == 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<long long> primes;
    generatePrimes(primes);

    while (n--) {
        long long a, b;
        cin >> a >> b;

        if (a + b < 4) {
            cout << "NO\n";
        } else if ((a + b) % 2 == 0) {
            cout << "YES\n";
        } else {
            if (isPrime(a + b - 2, primes)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
