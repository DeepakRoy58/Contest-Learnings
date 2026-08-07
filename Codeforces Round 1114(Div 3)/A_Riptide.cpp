#include <bits/stdc++.h>
using namespace std;

/*
Sort the three numbers ->x ≤ y ≤ z 
 If any two are already equal (x==y | y==z) , ans = 0
 Otherwise the middle value **never changes
   each round: smallest +1, largest –1, middle stays.
   after k rounds we will have  (x+k, y, z–k)
Game ends as soon as the smallest catches the middle / large catches the middle:)
   So k = min(y−x, z−y)
 Thas the ans


 complexity analysis : sorting we takes O(1) time & remaining all are const optns
 O(1) memory :)
*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int v[3];
        cin >> v[0] >> v[1] >> v[2];
        sort(v, v + 3);               // v[0] <- v[1] <- v[2]
        int ans;
        if (v[0] == v[1] || v[1] == v[2]) {
            ans = 0;                   
        } else {
            ans = min(v[1] - v[0], v[2] - v[1]);
        }
        cout << ans << '\n';
    }
    return 0;
}