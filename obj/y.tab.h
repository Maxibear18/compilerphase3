/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_OBJ_Y_TAB_H_INCLUDED
# define YY_YY_OBJ_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INTCONST = 259,                /* INTCONST  */
    IF = 260,                      /* IF  */
    ELSE = 261,                    /* ELSE  */
    WHILE = 262,                   /* WHILE  */
    RETURN = 263,                  /* RETURN  */
    VOID = 264,                    /* VOID  */
    CHAR = 265,                    /* CHAR  */
    INT = 266,                     /* INT  */
    LBRACE = 267,                  /* LBRACE  */
    RBRACE = 268,                  /* RBRACE  */
    LPARENTHESIS = 269,            /* LPARENTHESIS  */
    RPARENTHESIS = 270,            /* RPARENTHESIS  */
    ASSIGN = 271,                  /* ASSIGN  */
    LBRACKET = 272,                /* LBRACKET  */
    RBRACKET = 273,                /* RBRACKET  */
    PLUS = 274,                    /* PLUS  */
    MINUS = 275,                   /* MINUS  */
    DIVIDE = 276,                  /* DIVIDE  */
    MULT = 277,                    /* MULT  */
    SEMICOLON = 278,               /* SEMICOLON  */
    COMMA = 279,                   /* COMMA  */
    LESSTHAN = 280,                /* LESSTHAN  */
    LESSTHANEQ = 281,              /* LESSTHANEQ  */
    GREATERTHAN = 282,             /* GREATERTHAN  */
    GREATERTHANEQ = 283,           /* GREATERTHANEQ  */
    EQ = 284,                      /* EQ  */
    NEQ = 285,                     /* NEQ  */
    STRCONST = 286,                /* STRCONST  */
    CHARCONST = 287,               /* CHARCONST  */
    ERROR = 288,                   /* ERROR  */
    ILLEGAL_TOK = 289,             /* ILLEGAL_TOK  */
    OPER_AT = 290,                 /* OPER_AT  */
    OPER_INC = 291,                /* OPER_INC  */
    OPER_DEC = 292,                /* OPER_DEC  */
    OPER_AND = 293,                /* OPER_AND  */
    OPER_OR = 294,                 /* OPER_OR  */
    OPER_NOT = 295                 /* OPER_NOT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INTCONST 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define RETURN 263
#define VOID 264
#define CHAR 265
#define INT 266
#define LBRACE 267
#define RBRACE 268
#define LPARENTHESIS 269
#define RPARENTHESIS 270
#define ASSIGN 271
#define LBRACKET 272
#define RBRACKET 273
#define PLUS 274
#define MINUS 275
#define DIVIDE 276
#define MULT 277
#define SEMICOLON 278
#define COMMA 279
#define LESSTHAN 280
#define LESSTHANEQ 281
#define GREATERTHAN 282
#define GREATERTHANEQ 283
#define EQ 284
#define NEQ 285
#define STRCONST 286
#define CHARCONST 287
#define ERROR 288
#define ILLEGAL_TOK 289
#define OPER_AT 290
#define OPER_INC 291
#define OPER_DEC 292
#define OPER_AND 293
#define OPER_OR 294
#define OPER_NOT 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "src/parser.y"

    int value;
    struct treenode *node;
    char *strval;

#line 153 "obj/y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_OBJ_Y_TAB_H_INCLUDED  */
