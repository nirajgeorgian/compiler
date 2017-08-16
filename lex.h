//
// Created by niraj georgian on 17/08/17.
//

#ifndef COMPILER_LEX_H
#define COMPILER_LEX_H

#endif //COMPILER_LEX_H
#define EOI 0                    /*  End of input */
#define SEMI 1                   /*  ; */
#define PLUS 2                   /*  + */
#define TIMES 3                  /*  * */
#define LP 4                     /* ( */
#define RP 5                     /*  ) */
#define NUM_OR_ID                /*  decimal number or identifier */

extern char *yytext;             /*  current lexeme or full statement */
extern int yyleng;               /*  length of character or operator (no. of operator or character) */
extern int yylineno;             /*  on which line it is currently */