#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Problem:
/*

*/

// Observations:
/*
- greedy gives ans
*/

// Approach:
/*

1. compute greedy length base.
 2. detect block C C D D -> can gain 2.
  3.iIf not, detect a pair C C with safe neighbour -> can gain 1.
 4. ans = base + gain.
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 2, 0);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int L0 = 0; // lenth
    int last = -1;

    for (int i = 1; i <= n; i++) {
        if (i == 1 || a[i] != last) {
            L0++;
            last = a[i];
        }
    }

    // does it incr by 2 ??
    bool incr2 = false;

    for (int i = 1; i + 3 <= n; i++) {
        if (a[i] == a[i + 1] &&
            a[i + 2] == a[i + 3] &&
            a[i] != a[i + 2]) {
            incr2 = true;
            break;
        }
    }

    //or incre by 1
    bool incr1 = false;

    if (!incr2) {
        for (int i = 1; i + 1 <= n; i++) {
            if (a[i] != a[i + 1])
                continue;

            int c = a[i];



            if (i > 1 &&
                a[i - 1] != c &&
                (i - 2 < 1 || a[i - 2] != c)) { // left side searchhh
                incr1 = true;
                break;
            }



            if (i + 2 <= n &&
                a[i + 2] != c &&
                (i + 3 > n || a[i + 3] != c)) { // right side seacrh
                incr1 = true;
                break;
            }
        }
    }

    cout << L0 + (incr2 ? 2 : (incr1 ? 1 : 0)) << endl;
}

int32_t main() {
    fastio;

    int T;
    cin >> T;

    while (T--)
        solve();

    return 0;
}