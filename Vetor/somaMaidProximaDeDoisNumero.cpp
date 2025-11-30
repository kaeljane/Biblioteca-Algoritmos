pair<ll, ll> somaMaisProxima(vector<ll> list, ll x) {
        ll n = list.size();
        ll s = 0, e=n-1;
        ll absDiff = INT_MAX;
        ll l, r;

        while (s<e){
                ll somaAtual = list[s] + list[e];
                if (abs(somaAtual - x) < absDiff){
                        l = s;
                        r = e;
                        absDiff = abs(somaAtual - x);

                }
                if (somaAtual > x) e--;
                else s++;
        }

        return {list[l], list[r]};
}