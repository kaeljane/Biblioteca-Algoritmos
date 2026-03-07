#include <bits/stdc++.h>
#define ll long long
using namespace std;
// sem sobreposição

ll verificadorQtSubstringSemSubreposicao(string &s) {
    // string s = "ababa";
    string sub = "aba";

    ll cont = 0;
    size_t pos = 0;

    while ((pos = s.find(sub, pos)) != string::npos) {
        cont++;
        pos += sub.length(); // pula a palavra inteira que acabamos de achar
    }
    return cont;

}

ll verificadorQtSubstring(string &s) {
    // string s = "ababa";
    string sub = "aba";

    ll cont = 0;
    size_t pos = 0;

    while ((pos = s.find(sub, pos)) != string::npos) {
        cont++;
        pos += 1;
    }
    return cont;
    
}