vl girarVetorHorarioOtimizado(vl list, ll n) {
        t = sz(list);
        n = n%t;

        reverse(list.begin(), list.begin() + t - n);
        reverse(list.begin() + t-n, list.end());
        rev(list);
        return list;
}

vl girarVetorHorario(vl list, ll n) {
        t = sz(list);
        n = n%t;

        vl output;
        for (ll i=t-n; i <= t-1; i++) {
                output.pb(list[i]);
        }

        for (ll i=0; i < t-n; i++){
                output.pb(list[i]);
        }
        return output;
}