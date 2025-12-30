void printSubarrays(vi &v) {
    int n = sz(v);
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "[ ";
            for (int k = i; k <= j; k++) {
                cout << v[k] << " ";
            }
            cout << "]" << el;
        }
    }
}