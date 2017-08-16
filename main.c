#include "lex.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

char *yytext = "";                              // Initialize it with empty string
int yyleng = 0;                                 // Initialize with no number
int yylineno = 0;                               // No input line at start

lex() {
    static char input_buffer[128];               // taking input as buffer so to make it speedy
    char *current;                               // Hold the current context of text
    while(true) {                                // infinite loop for parsing until the end
        while(!*current) {                       // *current is a pointer stores *current = 0 = false and !false = true and while loop executes until false

        }
    }
}

int main() {
    char *current;
    current = yyleng + yytext;
    printf("Hello, World! %d\n", *current);
    return 0;
}