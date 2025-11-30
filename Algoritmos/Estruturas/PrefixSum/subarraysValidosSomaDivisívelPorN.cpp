#include <bits/stdc++.h>
using namespace std;

// Subarray Divisibility: https://cses.fi/problemset/view/1662/
// Contando a quantidade de subarrays que a soma é divisível por n.

int main(){
    
    int n; cin >> n;
 
    vector<ll> arr(n);
    arr[0]++;
    ll prefix = 0;
    for (int i = 1; i <= n; i++){
        ll a; cin >> a;
 
        prefix += a;
        arr[((prefix % n) + n) % n]++;
    }
 
    ll ans = 0;
    for (auto x : arr){
        ans += ((x-1)*(x))/2;
    }
 
    cout << ans << "\n";
}