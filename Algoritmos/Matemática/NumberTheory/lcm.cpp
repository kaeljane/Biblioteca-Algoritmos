// Minimo Multiplo Comum
//
// Time Complexity: O(log min(a,b))
// Auxiliary Space: O(log min(a,b))
// lcm(a, b) * gcd(a, b) = a * b

/*
formula
lcm(a,b) = (a*b) / gcd(a,b);

*/

int lcm(int a, int b){
    return a / __gcd(a, b) * b;
}