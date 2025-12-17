// Propriedades

a | b = (a^b) + (a & b);
a ^ (a&b) =  (a | b) ^ b;
b ^ (a&b) = (a | b) ^ a;
(a&b) ^ (a|b) = a^b;

// Adição
a + b = (a|b) + (a&b);
a + b = (a^b) + 2 * (a&b);

// Subtração

a - b = (a ^ (a&b)) - ((a | b) ^ a);
a - b = ((a | b) ^ b) - ((a | b) ^ a);
a - b = (a ^ (a&b)) - (b ^ (a&b));
a - b = ((a | b) ^ b) - (b ^ (a&b));


// 
Na soma normal: Se A + B == c, então C - B == A (O inverso de somar é subtrair)
No XOR: Se A ^ B == C, então C + B == A (O inverso de "xorar" é "xorar" de novo!)

a^a = 0
a^0 = a
a^b^c = a^c^b

