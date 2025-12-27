
map<ll, int> factors; 

ll mulmod(ll a, ll b, ll m) {
    ll res = 0;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res + a) % m;
        a = (a * 2) % m;
        b /= 2;
    }
    return res;
}

ll binPow(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1) result = mulmod(result, base, mod);
        base = mulmod(base, base, mod);
        e >>= 1;
    }
    return result;
}

bool checkComposite(ll n, ll a, ll d, int s) {
    ll x = binPow(a, d, n);
    if (x == 1 || x == n - 1) return false;
    for (int r = 1; r < s; r++) {
        x = mulmod(x, x, n);
        if (x == n - 1) return false;
    }
    return true;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a) return true;
        if (checkComposite(n, a, d, s)) return false;
    }
    return true;
}

ll pollard_rho(ll n) {
    if (n % 2 == 0) return 2;
    ll x = 2, y = 2, d = 1, c = 1;
    
    // ALTERADO: Lambda function usando mulmod
    auto f = [&](ll x) { 
        return (mulmod(x, x, n) + c) % n; 
    };

    while (d == 1) {
        x = f(x);
        y = f(f(y));
        
        ll val = (x > y) ? (x - y) : (y - x);
        d = __gcd(val, n);

        if (d == n) {
            ll big_rand = (ll)rand() * rand(); 
            x = big_rand % (n - 2) + 2;
            y = x;
            c = big_rand % (n - 1) + 1;
            d = 1;
        }
    }
    return d;
}

void factorize(ll n) {
    if (n == 1) return;
    if (isPrime(n)) {
        factors[n]++;
        return;
    }
    ll divisor = pollard_rho(n);
    factorize(divisor);
    factorize(n / divisor);
}

void solve() {
    cin >> n;
    factors.clear();
    factorize(n);

}

signed main() {
    ___
    srand(time(0));
    cin >> t;
    while(t--)
        solve();
    return 0;
}