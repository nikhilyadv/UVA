#include<bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
const int MAX = 1000001;

int m[MAX], mu[MAX];

void sieve() {
    bitset<MAX> b;
    fill_n(mu, MAX, 1);
    for (ll i = 2; i < MAX; i++) {
        if (b[i]) continue;
        ll t = i * i;
        for (ll j = t; j < MAX; j += t) mu[j] = 0;
        for (ll j = i; j < MAX; j += i) {
            mu[j] *= -1;				//counting mod 2 of prime numbers
            b.set(j);					//set it to 1
        }
    }
}

int main() {
    sieve();
    fill_n(m, MAX, 0);
    for (int i = 1; i < MAX; i++) m[i] = m[i - 1] + mu[i];
    int n;
    while (cin >> n, n) printf("%8d%8d%8d\n", n, mu[n], m[n]);
}
