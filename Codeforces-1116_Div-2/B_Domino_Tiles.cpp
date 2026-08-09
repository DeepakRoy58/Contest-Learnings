#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;

/* cnt the num of binary strings from s by 
replace ? such that the sum
 of adjacent chars never 
stay the same for two neighbouring pairs

*/

long long solveChain(const string& s, int st){
    //int b = INT_MAX; 
    int b= -1;
    int k = 0;

    for(int i = st; i < (int)s.size(); i += 2, k++){
        if(s[i] != '?'){
            int x = s[i] - '0';
            int need = x ^ (k % 2);
            if(b == -1) b = need;
            else if(b != need) return 0;
        }
    }
    return (b == -1) ? 2 : 1;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >> n >> s;
        
        long long cnt_Odd = solveChain(s, 0); // even 0-idxs
        long long cnt_Even = solveChain(s, 1); // odd 0-indxs
        
        long long cnt_Ways = (cnt_Odd * cnt_Even) ;

        cout << cnt_Ways % MOD << "\n";
    }
    return 0;
}

/*O(N) time !!*/