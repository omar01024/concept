#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int charClass;
string lexeme;
char nextChar;
int lexLen;
int token;
int nextToken;
string input = "x = 42 + (y - 3) * 5 / 2";
int pos = 0;

void addChar();
void getChar();
void getNonBlank();
int lex();

const int LETTER = 0;
const int DIGIT = 1;
const int UNKNOWN = 99;
const int INT_LIT = 10;
const int IDENT = 11;
const int ASSIGN_OP = 20;
const int ADD_OP = 21;
const int SUB_OP = 22;
const int MULT_OP = 23;
const int DIV_OP = 24;
const int LEFT_PAREN = 25;
const int RIGHT_PAREN = 26;

int main() {
    getChar();
    do {
        lex();
    } while (nextToken != EOF);
    return 0;
}

int lookup(char ch) {
    switch (ch) {
        case '(':
            addChar();
            nextToken = LEFT_PAREN;
            break;
        case ')':
            addChar();
            nextToken = RIGHT_PAREN;
            break;
        case '+':
            addChar();
            nextToken = ADD_OP;
            break;
        case '-':
            addChar();
            nextToken = SUB_OP;
            break;
        case '*':
            addChar();
            nextToken = MULT_OP;
            break;
        case '/':
            addChar();
            nextToken = DIV_OP;
            break;
        case '=':
            addChar();
            nextToken = ASSIGN_OP;
            break;
        default:
            addChar();
            nextToken = EOF;
            break;
    }
    return nextToken;
}

void addChar() {
    if (lexLen <= 98) {
        lexeme += nextChar;
        lexLen++;
    } else {
        cout << "Error - lexeme is too long" << endl;
    }
}

void getChar() {
    if (pos < input.length()) {
        nextChar = input[pos++];
        if (isalpha(nextChar))
            charClass = LETTER;
        else if (isdigit(nextChar))
            charClass = DIGIT;
        else
            charClass = UNKNOWN;
    } else {
        charClass = EOF;
    }
}

void getNonBlank() {
    while (isspace(nextChar)) {
        getChar();
    }
}

int lex() {
    lexLen = 0;
    lexeme.clear();
    getNonBlank();

    switch (charClass) {
        case LETTER:
            addChar();
            getChar();
            while (charClass == LETTER || charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = IDENT;
            break;

        case DIGIT:
            addChar();
            getChar();
            while (charClass == DIGIT) {
                addChar();
                getChar();
            }
            nextToken = INT_LIT;
            break;

        case UNKNOWN:
            lookup(nextChar);
            getChar();
            break;

        case EOF:
            nextToken = EOF;
            lexeme = "EOF";
            break;
    }

    cout << "Next token is: " << nextToken << ", Next lexeme is " << lexeme << endl;
    return nextToken;
}
