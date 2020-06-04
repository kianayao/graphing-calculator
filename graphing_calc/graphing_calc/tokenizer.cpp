#include "tokenizer.h"
#include <string.h>

Tokenizer::Tokenizer(): _infix() {
    // INTETNIONALLY LEFT BLANK
}

Tokenizer::Tokenizer(string s): _infix(tokenize(s)) {
    // INTENTIONALLY LEFT BLANK
}

Tokenizer::Tokenizer(char* c): _infix(tokenize(c)) {
    // INTENTIONALLY LEFT BLANK
}

Queue<Token*> Tokenizer::tokenize(string s) {
    Queue<Token*> infix;
    char temp[] = {};

    for (unsigned int i = 0; i < s.length(); i++)
        temp[i] = s[i];
    temp[s.length()] = '\0';

    char *tokens = strtok(temp, " ");

    while (tokens != NULL) {
        if (isdigit(*tokens) || *tokens == 'x' || *tokens == 'X')
            infix.push_end(new Numbers(to_string(*tokens)));
        else if (*tokens == '+' || *tokens == '-' || *tokens == '/' ||
                 *tokens == '/')
            infix.push_end(new Function(to_string(*tokens), 2));
        else // trig functions
            infix.push_end(new Function(to_string(*tokens), 1));
        tokens = strtok(temp, " ");
    }
    return infix;
}

Queue<Token*> Tokenizer::tokenize(char* c) {
    Queue<Token*> infix;

    char *tokens = strtok(c, " ");

    while (tokens != NULL) {
        if (isdigit(*tokens) || *tokens == 'x' || *tokens == 'X')
            infix.push_end(new Numbers(to_string(*tokens)));
        else if (*tokens == '+' || *tokens == '-' || *tokens == '/' ||
                 *tokens == '/')
            infix.push_end(new Function(to_string(*tokens), 2));
        else // trig functions
            infix.push_end(new Function(to_string(*tokens), 1));
        tokens = strtok(c, " ");
    }
    return infix;
}

Queue<Token*> Tokenizer::get_infix() {
    return _infix;
}
