#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a+3);
        long long soln;
        if(a[2] <= a[0] + a[1]){
            soln = a[2] - a[0];
        } else {
            soln = a[1];
        }
        cout << soln << "\n";
    }
    return 0;
}