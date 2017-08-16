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
            current = input_buffer;             // get the current line as buffed data
            if(!gets(input_buffer)) {
                // no more input elements to get
                *current = '\o';                 // input value set to null character
                return EOI;
            }
            // now move to next line
            ++yylineno;
            while(isspace(*current)) {           // till it is having space skip it and come to the end where the real parsing start
                ++current;
            }
            // now we are at the  start of the statement from where we want to parse
            for(; *current; ++current) {
                // till the last token from the current statement execute all these codes
                yytext = current;
                yyleng = 1;
                switch (*current) {
                    case EOF: return EOI;
                    case ';': return SEMI;
                    case '+': return PLUS;
                    case '*': return TIMES;
                    case '(': return LP;
                    case ')': return RP;
                    case '\n':
                    case '\t':
                    case ' ': break;
                    default:
                        // check if not an character or integer print it to stderr with some message
                        if(!isalnum(*current)) {
                            fprintf(stderr,"Ignoring illegal input value <%c>\n", *current);
                        } else {
                            while(isalnum(*current)) {
                                ++current;
                            }
                            yyleng = current - yytext;
                            return NUM_OR_ID;
                        }
                    break;
                }
            }
        }
    }

}

int main() {
    char *current;
    current = yyleng + yytext;
    printf("Hello, World! %d\n", *current);
    return 0;
}