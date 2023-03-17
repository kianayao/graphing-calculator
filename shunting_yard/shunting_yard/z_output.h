#ifndef Z_OUTPUT_H
#define Z_OUTPUT_H

/*

infix: 5 + ( 5 * 5 / x ) + ( 5 * 5 / x )
postfix: 5 5 5 * x / + 5 5 * x / +

infix: 5 / ( 5 / 5 / x ) / ( 5 / 5 / x )
postfix: 5 5 5 / x / / 5 5 / x / /

infix: 5 / ( 5 ^ 5 / x ) / ( 5 / 5 ^ x )
postfix: 5 5 5 ^ x / / 5 5 x ^ / /

infix: 5 / ( 5 ^ 5 / x ) - ( 5 + 5 ^ x )
postfix: 5 5 5 ^ x / / 5 5 x ^ + -

infix: 5 / ( 5 ^ 7 ^ x ) - ( 8 + 5 ^ x )
postfix: 5 5 7 ^ x ^ / 8 5 x ^ + -

infix: 5 ^ ( 5 ^ 7 ^ x ) - ( 8 + 5 ^ x )
postfix: 5 5 7 ^ x ^ ^ 8 5 x ^ + -

*/

#endif // Z_OUTPUT_H
