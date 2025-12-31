// Propriedades
/*
    Binary AND               &
    Binary OR                |
    Binary XOR               ^
    Binary One's Complement  ~
    Binary Left Shift        <<
    Binary Right Shift       >>    

    [Binary And &]
        5 & 7 = 5

        0000101 = 5
    &   0000111 = 7
        -------
        0000101 = 5
    

    [Binary OR |]
        5|8 = 13

        0101 = 5
    |   1000 = 8
        ----
        1101 = 13
    
    [Binary Not ~]
        ~5 = -6

        0000...0101 = 5
        1111...1010 = -6 (Representação em complemento de 2)
    
    [Binary Left SHIFT <<]
        5 << 1 = 10

        0000...0101 = 5
        0000...1010 = 10

    [Binary Right SHIFT >>]
        5 >> 1 = 2

        0000...0101 = 5
        0000...0010 = 2



*/ 
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

