string s = "codeforces";
string sub = "for";

if (s.find(sub) != string::npos) {
    cout << "Encontrou!" << el; 
}
else cout << "Não tem essa substring." << el;


// forma moderna c++23
if (s.contains(sub)) {
    cout << "Encontrou!" << el;
}
