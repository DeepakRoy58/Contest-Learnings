#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Problem:
/*
   here are cards with values 2 to n+1.
   a smaller card wins if one value divides the other,
   otherwise the larger card wins.
   determine where exists a card that beats every other card.
*/

// Observations:
/*
   - we need to ans multiple primality queries efficiently.
   - since n <= 2e5, precompute all primes up to 200002 
   for n + 1 to beat a smaller card k:

    if (n + 1) % k == 0, then k wins
            otherwise n+1 wins :)
*/

// Approach:
/*
   - build a sieve once before processing test cases.
   - for each n:
       * Check if (n + 1) is marked prime.
       * Print YES or NO accordingly.
*/

void solve() {
    int n;
    cin >> n;

    static vector<bool> isPrime;
    static bool precomputed = false;

    if (!precomputed) {
        const int max_of_n = 200000;
        const int LIMIT = max_of_n + 2;

        isPrime.assign(LIMIT + 1, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= LIMIT; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= LIMIT; j += i)
                    isPrime[j] = false;
            }
        }

        precomputed = true;
    }

    cout << (isPrime[n + 1] ? "YES" : "NO") << endl;
}

int32_t main() {
    fastio;

    int T = 1;
    cin >> T;

    while (T--) solve();

    return 0;
}

// Notes:
/*
   - complexity -> O(N log log N)
   - each query -> O(1)
   - overall total => O(N log log N + T)
*/