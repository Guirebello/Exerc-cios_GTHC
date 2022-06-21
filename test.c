#include<stdio.h>

unsigned compressor(unsigned x, unsigned m){
    unsigned r, s, b, k, final;
    r = 0;
    s = 0;
    k = 65535;

    do{
        // Compressor
        b = m & 1;
        r = r | ((x & b) << s);
        s = s + b;
        k = ((k >> s) << s);

        x = x >> 1;
        m = m >> 1;
        final = r | k;

    } while (m != 0);

    return final;
}

int main(void){
    unsigned x = 0b0000111100111010;
    unsigned m = 0b0101110110010011;
    unsigned r = 0b0000000001110110;

    unsigned t = compressor(x, m);
    printf("%d\n", t); // resultado final do exercício 
    // printf("%d\n", r); --> 118

    return 0;
}