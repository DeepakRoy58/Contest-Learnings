#include <bits/stdc++.h>
using namespace std;

/*
|f("aabbcc")|=
 |"abc"|=3
If the string is empty, its length is 0
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;

        // count original number of blocks
        // check whether a reduction is possible

        /*
        case: L == R and L != X  ->  merge outer blocks
        case: L != X, R != X
        */
        int blocks = 1;                     
        for (int i = 0; i + 1 < n; ++i)
            if (s[i] != s[i + 1]) ++blocks;

       
        bool good = false;
        for (int i = 1; i + 1 < n; ++i) {  
            char L = s[i - 1], X = s[i], R = s[i + 1];
 
            if (L == R && L != X) {
                good = true;
                break;
            }

            if (L != X && R != X) {
                bool left  = (i - 1 == 0)     || (s[i - 2] != X);
                bool right = (i + 1 == n - 1) || (s[i + 2] != X);
                if (left && right) {
                    good = true;
                    break;
                }
            }
        }

        int sol = good ? blocks - 1 : blocks;
        cout << sol << '\n';
    }
    return 0;
}
