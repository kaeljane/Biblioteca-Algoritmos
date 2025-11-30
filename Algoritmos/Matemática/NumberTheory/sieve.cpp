// Crivo de Erastotenes
//
// Time Complexity: O(nloglogn)
// Auxiliary Space: O(n)
// Find primes in range [2, n]

vector<int> sieve(int n){
    vector<int> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;

    for(int i = 2; (long long)i * i <= n; i++){
        if(is_prime[i]){
            for(int j = i * i; j <= n; j += i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

// vetor global
const int MAXN = 1e6 + 5;
vector<bool> is_prime(MAXN, true);
void sieve() {
    is_prime[0] = is_prime[1] = false; // 0 e 1 não são primos

    for (ll i = 2; i * i < MAXN; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < MAXN; j += i) {
                is_prime[j] = false;
            }
        }
    }
}




// numeros no vetor
// grande custo de memória por causa do long long
vector<ll> crivo(ll n){
    vector<ll> isprime(n+1, true);
    vector<ll> prime;
    isprime[0] = isprime[1] = false;

    for(ll i = 2; i * i <= n; i++){
        if(isprime[i]){
            for(ll j = i * i; j <=n; j+=i){
                isprime[j] = false;
            }
        }
    }

    for(ll i = 2; i <=n; i++)if(isprime[i])prime.push_back(i);

    return prime;
}


// -----------------------------------------------------------------
// VERSAO OTIMIZADA DO ANTERIOR
const ll MAXN = 1e6 + 5; // Defina o limite do problema

vl primes; 
vector<bool> is_prime(MAXN, true); 
 
void sieve(ll n) {
    is_prime[0] = is_prime[1] = false;
    
    for (ll i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }
}