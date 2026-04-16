%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<../src/tree.h>
#include<../src/strtab.h>

extern int yylineno;
extern int yylex(void);

int yywarning(char *msg);
int yyerror(char *msg);


typedef struct treenode tree;
extern tree *ast;

/* nodeTypes refer to different types of internal and external nodes
  that can be part of the abstract syntax tree.
  */

/* NOTE: mC has two kinds of scopes for variables : local and global.
  Variables declared outside any function are considered globals,
    whereas variables (and parameters) declared inside a function foo
    are local to foo.
  You should update the scope variable whenever you are inside a production
    that matches function definition (funDecl production).
  The rationale is that you are entering that function, so all variables,
    arrays, and other functions should be within this scope.
  You should pass this variable whenever you are
    calling the ST_insert or ST_lookup functions.
  This variable should be updated to scope = ""
    to indicate global scope whenever funDecl finishes.
  Treat these hints as helpful directions only.
  You may implement all of the functions as you like
    and not adhere to my instructions.
  As long as the directory structure is correct and the file names are correct,
    we are okay with it.
  */
static int global_scope_marker = 0;
static int function_scope_markers[1024];
static int function_scope_count = 0;
static int *current_scope = &global_scope_marker;
static int funID;
static int param_count = 0;
static int current_fun_ind = -1;
%}

/* the union describes the fields available in the yylval variable */
%union
{
    int value;
    struct treenode *node;
    char *strval;
}

/*Add token declarations below.
  The type <value> indicates that the associated token will be
    of a value type such as integer, float etc.,
    and <strval> indicates that the associated token will be of string type.
  */
%token <strval> ID
%token <value> INTCONST
/* TODO: Add the rest of the tokens below.*/
%token IF ELSE WHILE RETURN
%token VOID CHAR INT
%token LBRACE RBRACE
%token LPARENTHESIS RPARENTHESIS
%token ASSIGN
%token LBRACKET RBRACKET
%token PLUS MINUS DIVIDE MULT
%token SEMICOLON COMMA
%token LESSTHAN LESSTHANEQ GREATERTHAN GREATERTHANEQ EQ NEQ
%token STRCONST CHARCONST ERROR ILLEGAL_TOK
%token OPER_AT OPER_INC OPER_DEC OPER_AND OPER_OR OPER_NOT

/* TODO: Declare non-terminal symbols as of type node.
  Provided below is one example.
  node is defined as 'struct treenode *node' in the above union data structure.
  This declaration indicates to parser that these non-terminal variables
    will be implemented using a 'treenode *' type data structure.
  Hence, the circles you draw when drawing a parse tree,
    the following lines are telling yacc that these
    will eventually become circles in an AST.
  This is one of the connections between the AST you draw by hand
    and how yacc implements code to concretize that.
  We provide with two examples:
    program and declList from the grammar. Make sure to add the rest.
  */

%type <node> program declList decl typeSpec varDecl funDecl
%type <node> formalDeclListOpt formalDeclList formalDecl
%type <node> funBody localDeclListOpt localDeclList
%type <node> statementListOpt statementList
%type <node> statement
%type <node> compoundStmt assignStmt condStmt loopStmt returnStmt
%type <node> expression relop addExpr addop term mulop factor
%type <node> var funCallExpr argList argListOpt

%start program

%%
/* TODO: Your grammar and semantic actions go here.
  We provide with two example productions
    and their associated code for adding non-terminals to the AST.
  */

program         : declList
                 {
                    tree *progNode = maketree(PROGRAM);
                    addChild(progNode, $1);
                    ast = progNode;
                    $$ = progNode;
                 }
                ;

declList        : decl
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    $$ = declListNode;
                 }
                | declList decl
                 {
                    tree* declListNode = maketree(DECLLIST);
                    addChild(declListNode, $1);
                    addChild(declListNode, $2);
                    $$ = declListNode;
                 }
                ;

/* TODO: This isn't the correct grammar for decl */
decl            
                 : varDecl
                 {
                  $$ = maketree(DECL);
                    // so $$ is now NULL, we can't dereference it
                  addChild($$,$1);
                 }
                 | funDecl
                 {
                    // $1 is an INTCONST
                    // INTCONST defined above as a token with yylval.value
                    // the tree functions aren't implemented
                    // so $$ is now NULL, we can't dereference it
                    $$ = maketree(DECL);
                    addChild($$, $1);
                 }
                ;

funDecl
    : typeSpec ID
      {
        funID = ST_insert($2, $1->val, FUNCTION, current_scope);
        current_fun_ind = funID;
        param_count = 0;
        current_scope = &function_scope_markers[function_scope_count++];
      }
      LPARENTHESIS formalDeclListOpt RPARENTHESIS funBody
      {

        $$ = maketree(FUNDECL);

        tree *funcTypeNode = maketree(FUNCTYPENAME);
        addChild(funcTypeNode, $1);
        addChild(funcTypeNode, maketreeWithVal(IDENTIFIER, funID));
        addChild($$, funcTypeNode);

        if ($5) addChild($$, $5);
        if ($7) addChild($$, $7);

        connect_params(current_fun_ind, param_count);
        current_scope = &global_scope_marker;
      }
    ;

typeSpec
    : INT
      {
          $$ = maketreeWithVal(TYPESPEC, INT_TYPE);
      }
    | CHAR
      {
          $$ = maketreeWithVal(TYPESPEC, CHAR_NODE);
      }
    | VOID
      {
          $$ = maketreeWithVal(TYPESPEC, VOID_TYPE);
      }
    ;

varDecl
    : typeSpec ID SEMICOLON
      {
          int valID = ST_insert($2, $1->val, SCALAR, current_scope);

          $$ = maketree(VARDECL);
          /*symEntry *entry = ST_lookup($1);*/
          addChild($$, $1);
          addChild($$, maketreeWithVal(IDENTIFIER, valID));
      }
    | typeSpec ID LBRACKET INTCONST RBRACKET SEMICOLON
      {
          int valID = ST_insert($2,$1->val, ARRAY,current_scope);

          $$ = maketree(VARDECL);
          addChild($$, $1);
          addChild($$, maketreeWithVal(IDENTIFIER, valID));
          addChild($$, maketreeWithVal(INTEGER, $4));
      }
    ;

formalDeclListOpt
                : /* e */
                {
                  $$ = NULL;
                }
                | formalDeclList
                {
                  $$ = $1;
                };

formalDeclList:
                formalDecl
                {
                  $$ = maketree(FORMALDECLLIST);
                  addChild($$, $1);
                }
                | formalDecl COMMA formalDeclList
                {
                  $$ = maketree(FORMALDECLLIST);
                  addChild($$, $1);
                  addChild($$, $3);
                };

formalDecl
    : typeSpec ID
      {
          int valID = ST_insert($2, $1->val, SCALAR, current_scope);
          $$ = maketree(FORMALDECL);
          addChild($$, $1);
          addChild($$, maketreeWithVal(IDENTIFIER, valID));
      }
    | typeSpec ID LBRACKET RBRACKET
      {
          int valID = ST_insert($2, $1->val, ARRAY, current_scope);

          $$ = maketree(FORMALDECL);
          addChild($$, $1);
          addChild($$, maketreeWithVal(IDENTIFIER, valID));
          addChild($$, maketree(ARRAYDECL));
      }
    ;

funBody: LBRACE localDeclListOpt statementListOpt RBRACE
{
  $$ = maketree(FUNBODY);
  addChild($$, $2);
  addChild($$, $3);
};

localDeclListOpt: /* e */
                {
                  $$ = NULL;
                }
                | localDeclList
                {
                  $$ = $1;
                }
                ;

localDeclList
: varDecl localDeclList
    {
        $$ = maketree(LOCALDECLLIST);
        addChild($$, $1);  
        addChild($$, $2);  
    }
    | varDecl
    {
        $$ = maketree(LOCALDECLLIST);
        addChild($$, $1);
    };
statementListOpt
    : /* e */
      {
          $$ = NULL;
      }
    | statementList
      {
          $$ = $1;
      }
    ;
statementList
    : statement
      {
        $$ = maketree(STATEMENTLIST);
        addChild($$, $1);
      }
    | statement statementList
      {
        $$ = maketree(STATEMENTLIST);
        addChild($$, $1);
        addChild($$, $2);
      }
    ;

statement
    : compoundStmt
      { $$ = maketree(STATEMENT); addChild($$, $1); }
    | assignStmt SEMICOLON
      { $$ = maketree(STATEMENT); addChild($$, $1); }
    | condStmt
      { $$ = maketree(STATEMENT); addChild($$, $1); }
    | loopStmt
      { $$ = maketree(STATEMENT); addChild($$, $1); }
    | returnStmt SEMICOLON
      { $$ = maketree(STATEMENT); addChild($$, $1); }
    ;
/*statement
    : matchedStmt
    | unmatchedStmt
    ;

matchedStmt
    : compoundStmt
      { $$ = $1; }
    | assignStmt SEMICOLON
      { $$ = $1; }
    | loopStmt
      { $$ = $1; }
    | returnStmt SEMICOLON
      { $$ = $1; }
    | expression SEMICOLON
      { $$ = $1; }
    | IF LPARENTHESIS expression RPARENTHESIS matchedStmt ELSE matchedStmt
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
          addChild($$, $7);
      }
    ;

unmatchedStmt
    : IF LPARENTHESIS expression RPARENTHESIS statement
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
      }
    | IF LPARENTHESIS expression RPARENTHESIS matchedStmt ELSE unmatchedStmt
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
          addChild($$, $7);
      }
    ;
matchedStmt
    : compoundStmt
      { $$ = $1; }
    | assignStmt SEMICOLON
      { $$ = $1; }
    | loopStmt
      { $$ = $1; }
    | returnStmt SEMICOLON
      { $$ = $1; }
    | IF LPARENTHESIS expression RPARENTHESIS matchedStmt ELSE matchedStmt
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
          addChild($$, $7);
      }
    ;

unmatchedStmt
    : IF LPARENTHESIS expression RPARENTHESIS statement
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
      }
    | IF LPARENTHESIS expression RPARENTHESIS matchedStmt ELSE unmatchedStmt
      {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
          addChild($$, $7);
      }
    ; */

compoundStmt
            : LBRACE localDeclListOpt statementListOpt RBRACE
            {
              $$ = maketree(COMPOUNDSTMT);
              addChild($$, $2);
              addChild($$, $3);
            };

assignStmt
    : var ASSIGN expression{
      $$ = maketree(ASSIGNSTMT);
      addChild($$, $1);
      addChild($$, $3);
    }
    | expression
      {
          $$ = maketree(ASSIGNSTMT);
          addChild($$, $1);
      }
    ;

returnStmt
          : RETURN
          {
            $$ = maketree(RETURNSTMT);
          }
          | RETURN expression
          {
            $$ = maketree(RETURNSTMT);
            addChild($$, $2);
          };

loopStmt
        : WHILE LPARENTHESIS expression RPARENTHESIS statement
        {
          $$ = maketree(LOOPSTMT);
          addChild($$, $3);
          addChild($$, $5);
        };

condStmt
        : IF LPARENTHESIS expression RPARENTHESIS statement
        {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
        }
        | IF LPARENTHESIS expression RPARENTHESIS statement ELSE statement
        {
          $$ = maketree(CONDSTMT);
          addChild($$, $3);
          addChild($$, $5);
          addChild($$, $7);
        };

expression
    : addExpr
      {
        $$ = maketree(EXPRESSION);
        addChild($$, $1);
      }
    | addExpr relop addExpr
      {
        $$ = maketree(EXPRESSION);

        tree *leftExpr = maketree(EXPRESSION);
        addChild(leftExpr, $1);
        addChild($$, leftExpr);
        addChild($$, $2);
        addChild($$, $3);
      }
    ;
relop
      : LESSTHAN
      {
        $$ = maketreeWithVal(RELOP, LT);
      }
      | LESSTHANEQ
      {
        $$ = maketreeWithVal(RELOP, LTE);
      }
      | GREATERTHAN
      {
        $$ = maketreeWithVal(RELOP, GT);
      }
      | GREATERTHANEQ
      {
        $$ = maketreeWithVal(RELOP, GTE);
      }
      | EQ
      {
        $$ = maketreeWithVal(RELOP, OP_EQ);
      }
      | NEQ
      {
        $$ = maketreeWithVal(RELOP, OP_NEQ);
      };

addExpr
    : term
      {
        $$ = maketree(ADDEXPR);
        addChild($$, $1);
      }
    | addExpr addop term
      {
        $$ = maketree(ADDEXPR);
        addChild($$, $1);
        addChild($$, $2);
        addChild($$, $3);
      }
    ;
addop
      : PLUS
      {
        $$ = maketreeWithVal(ADDOP, ADD);
      }
      | MINUS
      {
        $$ = maketreeWithVal(ADDOP, SUB);
      };

term
    : factor
      {
        $$ = maketree(TERM);
        addChild($$, $1);
      }
    | term mulop factor
      {
        $$ = maketree(TERM);
        addChild($$, $1);
        addChild($$, $2);
        addChild($$, $3);
      }
    ;

mulop
      : MULT
      {
        $$ = maketreeWithVal(MULOP, MUL);
      }
      | DIVIDE
      {
        $$ = maketreeWithVal(MULOP, DIV);
      };

factor
    : INTCONST
      {
        $$ = maketree(FACTOR);
        addChild($$, maketreeWithVal(INTEGER, $1));
      }
    | var
      {
        $$ = maketree(FACTOR);
        addChild($$, $1);
      }
    | funCallExpr
      {
        $$ = maketree(FACTOR);
        addChild($$, $1);
      }
    | LPARENTHESIS expression RPARENTHESIS
      {
        $$ = maketree(FACTOR);
        addChild($$, $2);
      }
    ;

var
    : ID
      {
          symEntry *entry = ST_lookup($1);
          if (entry == NULL) {
            yywarning("undeclared symbol");
          }
          $$ = maketree(VAR);
          addChild($$, maketreeWithVal(IDENTIFIER, -1));
      }
    | ID LBRACKET expression RBRACKET
      {
          symEntry *entry = ST_lookup($1);
          if (entry == NULL) {
            yywarning("undeclared symbol");
          }
          $$ = maketree(VAR);
          addChild($$, maketreeWithVal(IDENTIFIER, -1));
          addChild($$, $3);
      };

funCallExpr
            : ID LPARENTHESIS argListOpt RPARENTHESIS
{
  symEntry *entry = ST_lookup($1);
          if (entry == NULL) {
            yywarning("undeclared symbol");
          }
  $$ = maketree(FUNCCALLEXPR);
  addChild($$, maketreeWithVal(IDENTIFIER, -1));
  addChild($$, $3);
};

argListOpt
          : /* e */
          {
            $$ = NULL;
          }
          | argList
          {
            $$ = $1;
          };

argList
        : expression
        {
          $$ = maketree(ARGLIST);
          addChild($$, $1);
        }
        | argList COMMA expression
        {
          $$ = maketree(ARGLIST);
          addChild($$, $1);
          addChild($$, $3);
        };
%%

int yywarning(char *msg){
  printf("warning: line %d: %s\n", yylineno, msg);
  return 0;
}

int yyerror(char * msg){
  printf("error: line %d: %s\n", yylineno, msg);
  return 0;
}