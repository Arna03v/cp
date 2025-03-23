/*
UPSOLVING

find a k st (x+k) + (y+k) == (x+k) XOR (x+y) or determine this is not possible

if(x==y)
    x+k == y+k
    XOR will be 0
    but x and y are positive and k is non negative
    so k DNE

if(x!=y)
    assume x > y

    say y < x <= 2^l (some random l; where l is the first power of 2 where this equation satisfies)

    do +(2^l -x) to the entire equation
    -> x becomes 2^l
    -> y becomes some number less than 2^l (as x > y)

    using example
    2^l >= 13 > 5 -> l = 4 (add 16-13 to x and y)
    x = 16; y = 8
    x = 10000
    y = 01000 (note that y will only have 1s after the MSB; the bit that is set for x will always be unset for y as y<2^l)
    sum = 11000
    XOR = 11000

    thus sum == XOR

HOW TO THINK ABOUT THIS

I have 2 numbers a,b; when can a+b == aXORb; if they dont have any mutual 1s then we are good. Now lets try construct these numbers from the given number.

how to get this ituition? by solving more problems with bitwise operations



*/