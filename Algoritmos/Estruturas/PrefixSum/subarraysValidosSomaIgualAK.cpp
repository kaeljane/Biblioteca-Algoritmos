#include <bits/stdc++.h>
using namespace std;

// Subarrays
//
// Subarray Sums II https://cses.fi/problemset/task/1661/

// Calculando a quantidade de subarrays válidos.
// Se a soma de um subarray é igual a k

int main(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
 
    ll ans = 0;
    ll prefix_sum = 0;
    map<ll, int> rastreio;
 
    rastreio[0]++;
    for (int x : arr){
        prefix_sum += x;
 
        ans += rastreio[prefix_sum - k];
 
        rastreio[prefix_sum]++;
    }
 
    cout << ans << "\n";
}