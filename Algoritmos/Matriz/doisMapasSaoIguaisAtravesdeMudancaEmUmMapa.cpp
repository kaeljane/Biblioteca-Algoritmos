cin>>x>>y;
vll mat(x, vl(y, 0));
vll matAns(x, vl(y, 0));


ll qtResh = 0;
for (ll i=0; i<x; i++) {
    cin>>s;
    for (ll j=0; j<y; j++) {
        mat[i][j] = s[j];
        if (s[j] == '#') qtResh++; 
    }
}

ll qtReshResposta=0;
for (ll i=0; i<x; i++) {
    cin>>s;
    for (ll j=0; j<y; j++) {
        matAns[i][j] = s[j];
        if (s[j] == '#') qtReshResposta++; 
    }
}

if (qtResh != qtReshResposta){
    cout << "No" << el;
    return;
}

for (ll s=0; s < x; s++) {
    for (ll t=0; t < y; t++) {
        bool ehIgual = true;

        for (ll i=0; i < x; i++) {
            for (ll j=0; j < y; j++) {
                if (mat[(i + s) % x][(j + t) % y] != matAns[i][j]) {
                    ehIgual = false;
                    break; // para o loop j
                }
            }
            if (!ehIgual) break; // para o loop i
        }
        if (ehIgual) {
            cout << "Yes" << el;
            return;
        }
    }
}
cout << "No" << el;