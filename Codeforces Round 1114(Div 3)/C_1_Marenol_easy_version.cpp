#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

// Problem:
/*
   Two binary strings a , b of len n. 
   Operations :
   - Swap s[i] and s[i+2] when they are different 001/100 011/110
   if a can be transfor b ?
*/

// Observations:
/*
   - Operations swaps chars with same parity
   - Outer chars in patterns alwasy different
   - count of 1s at even, odd
   -like bubble sort ??
*/

// Approach:
/*
   - Count 1s at even/odd postions in both strings
   - Both counts must match 
   */

void solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    
    int roy_even = 0, roy_odd = 0, sam_even = 0, sam_odd = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == '1') {
            if (i % 2 == 0) roy_even++;
            else roy_odd++;
        }
        if (b[i] == '1') {
            if (i % 2 == 0) sam_even++;
            else sam_odd++;
        }
    }
    
    cout << ((roy_even == sam_even && roy_odd == sam_odd) ? "YES" : "NO") << '\n';
}

int32_t main() {
    fastio;
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}