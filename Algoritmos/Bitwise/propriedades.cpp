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