// ------------ Repetition repetition repetition repetition repetition repet... ------------
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, int>
#define vl vector<long long>
#define vll vector<vector<long long>>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define soma(v) accumulate(all(v), 0LL)
#define max_el(v) *max_element(all(v))
#define min_el(v) *min_element(all(v))
#define f(i,b,e) for (ll i = (b); i < (e); i++)
#define rf(i,b,e) for (ll i = (b); i >= (e); i--)
#define fi first
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define sec second
#define el '\n'
#define imp(v, t, e) copy(v.begin(), v.end(), ostream_iterator<t> (cout, e))
#define uset unordered_set
#define ___ ios::sync_with_stdio(false); cin.tie(nullptr);
// 18/05/2026 by Kaeljane
using namespace std;

ll MOD = 1e9 + 7; // 998244353;
ll INF = 1e18 + 7;
const int MAXN = 1e5 + 5;
// matriz vll mat(n, vl(m, 0))

ll n, t, k, x, y, z, q;
string s, a, b, c;

/* (mind) 
    56min

    template de segtree da aula do joao com adicao de id
    
    
*/
int ns[MAXN];
#define e(u) (u*2)
#define d(u) (e(u)+1)
#define out (l > r || l > b || r < a)
#define in (a <= l && r <= b)

struct Node {
    ll v = 0;
    ll id = 0; /////

    Node operator+(const Node b) {
        if (v > b.v) return {v, id};
        else return {b.v, b.id}; ////
    }
};

struct SEG {
    Node seg[MAXN*4];
    ll lim;

    void build(ll u, ll l, ll r) {
        if (l == r) {
            seg[u].v = 5;
            seg[u].id = l; ////////
        }
        else {
            const ll m = (l+r)/2;
            build(e(u), l, m), build(d(u), m+1, r);
            seg[u] = seg[e(u)] + seg[d(u)];
        }
    }
    void build(ll lim_) {
        lim = lim_; ////
        build(1, 0, lim); // 0-based
    }

    void update(ll u, ll l, ll r, ll a, ll b) {
        if (l == r) { // no folha
            seg[u].v = b;
            return;
        }
        const ll m = (l+r)/2;
        if (a <= m) update(e(u), l, m, a, b);
        else update(d(u), m+1, r, a, b);
        seg[u] = seg[e(u)] + seg[d(u)];

    }

    void update (ll pos, ll newv) {
        update(1, 0, lim, pos, newv);
    }

    Node query (ll u, ll l, ll r, ll a, ll b) {
        if (out) return Node();
        if (in) return seg[u];
        const ll m = (l+r)/2;
        return query(e(u), l, m, a, b) + query(d(u), m+1, r, a, b);
    }
    Node query(ll l, ll r) {
        return query(1, 0, lim, l, r);
    }
} seg;


// void solve() {
//     cin>>n>>q;
//     seg.build(n-1);
//     vl v(n); for (ll i = 0; i < n; i++) cin>>v[i];
    
//     f (i, 0, n) seg.update(i, v[i]);

//     f (i, 0, q) {
//         cin>>x>>y; // 1-based
//         Node ans = seg.query(x-1, y-1);

//         if (ans.v == 0) {
//             cout << "Nenhum Rei Desta Vez!" << el;
//         }
//         else {
//             cout << "Grande Rei Ragnar " << ans.v << el;
//             seg.update(ans.id, 0);
//         }
//     }


// }