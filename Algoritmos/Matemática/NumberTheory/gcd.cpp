// Algoritmo de Euclides
//
// Time Complexity: O(log min(a,b))
// Auxiliary Space: O(log min(a,b))

/*
if b=0   -> n
if b!=0  -> gcd (b, a mod b) 

multiplos numeros
gcd(a1, a2, a3, a4) = gcd(a1, gcd(a2, gcd(a3, a4)))


*/
int recursive_gcd(int a, int b){
    if(b == 0) return a;
    else return recursive_gcd(b, a % b);
}

int non_recursive_gcd(int a, int b){
    while(b){
        a %= b;
        swap(a, b);
    }
    return a;
}