# Lexical Analyzer

This is a simple lexical analyzer implemented in C++ that reads an input file `front.in` and tokenizes its contents.

## Overview

The program reads characters from the input file and classifies them into different token types such as identifiers, integer literals, and arithmetic operators. It follows a basic lexical analysis approach to recognize tokens.

## Features
- Recognizes integer literals
- Identifies identifiers (variable names)
- Detects arithmetic operators (`+`, `-`, `*`, `/`)
- Identifies parentheses (`(`, `)`)
- Handles whitespace and unknown characters

## Token Types
| Token Name  | Token Value |
|-------------|------------|
| LETTER      | 0          |
| DIGIT       | 1          |
| UNKNOWN     | 99         |
| INT_LIT     | 10         |
| IDENT       | 11         |
| ASSIGN_OP   | 20         |
| ADD_OP      | 21         |
| SUB_OP      | 22         |
| MULT_OP     | 23         |
| DIV_OP      | 24         |
| LEFT_PAREN  | 25         |
| RIGHT_PAREN | 26         |

## Files
- `front.in` (Input file containing source code to be tokenized)
- `lexer.cpp` (Source code for the lexical analyzer)

## How to Run
1. Compile the program using a C++ compiler:
   ```sh
   g++ lexer.cpp -o lexer
   ```
2. Run the executable:
   ```sh
   ./lexer
   ```
3. Ensure that `front.in` exists in the same directory and contains sample code.

## Code Explanation
### Main Functions

- **`getChar()`**: Reads the next character from the input file and classifies it as a letter, digit, or unknown.
- **`addChar()`**: Adds the current character to the lexeme.
- **`getNonBlank()`**: Skips whitespace characters.
- **`lookup(char ch)`**: Identifies symbols like `+`, `-`, `*`, `/`, `(`, `)`.
- **`lex()`**: The main lexical analyzer function that recognizes tokens and prints them.

## Sample Output
If `front.in` contains:
```
a = b + 5;
```
The output might be:
```
Next token is: 11, Next lexeme is a
Next token is: 99, Next lexeme is =
Next token is: 11, Next lexeme is b
Next token is: 21, Next lexeme is +
Next token is: 10, Next lexeme is 5
```

