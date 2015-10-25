%{
// $Id: pwn_parser.y,v 1.29 2015/05/19 16:38:00 ist175741 Exp $
//-- don't change *any* of these: if you do, you'll break the compiler.
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
//-- don't change *any* of these --- END!
%}

%union {
  int                   i;          /* integer value */
  double                d;	        /* double value */
  std::string          *s;	        /* symbol name or string literal */
  cdk::basic_node	     *node;	      /* node pointer */
  cdk::sequence_node	 *sequence;
  cdk::expression_node *expression; /* expression nodes */
  pwn::lvalue_node     *lvalue;
  pwn::block_node      *block;
  basic_type           *t;	        /*basic_type*/
};

%token <i> tINTEGER
%token <d> tDOUBLE
%token <s> tID tSTRING
%token tREPEAT tIF tPRINT tREAD tBEGIN tEND tNEXT tSTOP tLOCAL tIMPORT tRETURN tNOOB
%token tTYPE_INT tPLN tEND tVOID tINT tSTRING

%nonassoc tIFX
%nonassoc tELSE
%nonassoc '(' ')' '~' '[' ']'

%right '='
%left '|'
%left '&'
%left tGE tLE tEQ tNE '>' '<' '{'
%left '+' '-'
%left '*' '/' '%'
%nonassoc tUNARY


%type <node> stmt dec v_dec f_dec f_def
%type <sequence> decs   vars arg_call stmts
%type <expression> expr literal f_call
%type <i>
%type <lvalue> lval
%type <block> body
%type <t> type

%{
//-- The rules below will be included in yyparse, the main parsing function.
%}

%%
file    : decs    { compiler->ast($1); }
        ;

decs    : dec      { $$ = new cdk::sequence_node(LINE, $1); }
        | decs dec { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;

dec     : v_dec tEND { $$ = $1; }
        | f_dec tEND { $$ = $1; }
        | f_def      { $$ = $1; }
        ;

v_dec   : type tID '=' literal { $$ = new pwn::var_dec_node(LINE, $1, $2, $4); }
        | type tID             { $$ = new pwn::var_dec_node(LINE, $1, $2); }
        | '*'  tID             { $$ = new pwn::var_dec_node(LINE, new basic_type(4, basic_type::TYPE_POINTER), $2); }
        | '*'  tID '=' tNOOB   { $$ = new pwn::var_dec_node(LINE, new basic_type(4, basic_type::TYPE_POINTER), $2, new pwn::noob_node(LINE)); }
        ;

f_dec   : type tID '(' ')' { $$ = new pwn::function_dec_node(LINE, $2, NULL, $1, true); }
        | type tID '(' vars ')' { $$ = new pwn::function_dec_node(LINE, $2, $4, $1, true); }
        | tVOID tID '(' vars ')' { $$ = new pwn::function_dec_node(LINE, $2, $4, new basic_type(0,basic_type::TYPE_VOID), true); }
        | tVOID tID '(' ')' { $$ = new pwn::function_dec_node(LINE, $2, NULL, new basic_type(0,basic_type::TYPE_VOID), true); }
        | '*' tID '(' vars ')' { $$ = new pwn::function_dec_node(LINE, $2, $4, new basic_type(4,basic_type::TYPE_POINTER), true); }
        | '*' tID '(' ')' { $$ = new pwn::function_dec_node(LINE, $2, NULL, new basic_type(4,basic_type::TYPE_POINTER), true); }
        ;

f_def   : type tID '(' vars ')' body  { $$ = new pwn::function_def_node(LINE, $2, $4, $1, $6, true); }
        | tVOID tID '(' vars ')' body { $$ = new pwn::function_def_node(LINE, $2, $4, new basic_type(0,basic_type::TYPE_VOID), $6, true); }
        | '*' tID '(' vars ')' body   { $$ = new pwn::function_def_node(LINE, $2, $4, new basic_type(4,basic_type::TYPE_POINTER), $6, true); }
        | type tID '(' ')' body  { $$ = new pwn::function_def_node(LINE, $2, NULL, $1, $5, true); }
        | tVOID tID '(' ')' body { $$ = new pwn::function_def_node(LINE, $2, NULL, new basic_type(0,basic_type::TYPE_VOID), $5, true); }
        | '*' tID '(' ')' body   { $$ = new pwn::function_def_node(LINE, $2, NULL, new basic_type(4,basic_type::TYPE_POINTER), $5, true); }
        ;

f_call  : tID '(' ')'       { $$ = new pwn::function_call_node(LINE, $1, NULL); }
        | tID '(' arg_call ')'  { $$ = new pwn::function_call_node(LINE, $1, $3); }
        ;

type    : tINT        { $$ = new basic_type(4, basic_type::TYPE_INT); }
        | tSTRING     { $$ = new basic_type(4, basic_type::TYPE_STRING); }
        ;

arg_call: expr        { $$ = new cdk::sequence_node(LINE, $1); }
        | arg_call ',' expr { $$ = new cdk::sequence_node(LINE, $3, $1); }
        ;

vars    : type tID           { $$ = new cdk::sequence_node(LINE, new pwn::var_node(LINE, $1, $2)); }
        | vars ',' type tID  { $$ = new cdk::sequence_node(LINE, new pwn::var_node(LINE, $3, $4), $1); }
        ;

body    : '{' decs stmts '}' { $$ = new pwn::block_node(LINE, $2, $3); }
        | '{' decs '}'       { $$ = new pwn::block_node(LINE, $2, NULL); }
        | '{' stmts '}'      { $$ = new pwn::block_node(LINE, NULL, $2); }
        | '{' '}'            { $$ = new pwn::block_node(LINE, NULL, NULL); }
        ;

stmts   : stmt           { $$ = new cdk::sequence_node(LINE, $1); }
        | stmts stmt     { $$ = new cdk::sequence_node(LINE, $2, $1); }
        ;

stmt    : expr tEND           { $$ = new pwn::evaluation_node(LINE, $1); }
        | expr '!'            { $$ = new pwn::print_node(LINE, $1); }
        | tSTOP tEND          { $$ = new pwn::stop_node(LINE); }
        | tSTOP tINTEGER tEND { $$ = new pwn::stop_node(LINE, $2); }
        | tNEXT tEND          { $$ = new pwn::next_node(LINE); }
        | tNEXT tINTEGER tEND { $$ = new pwn::next_node(LINE, $2); }
        | body                { $$ = $1; }
        | tIF '(' expr ')' stmt %prec tIFX            { $$ = new cdk::if_node(LINE, $3, $5); }
        | tIF '(' expr ')' stmt tELSE stmt            { $$ = new cdk::if_else_node(LINE, $3,$5, $7); }
        | tREPEAT '(' expr ',' expr ',' expr ')' stmt { $$ = new pwn::repeat_node(LINE, $3, $5, $7, $9); }
        | tREPEAT '(' ',' expr ',' expr ')' stmt      { $$ = new pwn::repeat_node(LINE, NULL, $4, $6, $8); }
        | tRETURN tEND                                { $$ = new pwn::return_node(LINE); }
        ;

expr    : '+' expr %prec tUNARY                           { $$ = new pwn::identity_node(LINE, $2); }
        | '-' expr %prec tUNARY                           { $$ = new cdk::neg_node(LINE, $2); }
        | '~' expr %prec tUNARY                           { $$ = new pwn::not_node(LINE, $2); }
        | expr '+' expr                                   { $$ = new cdk::add_node(LINE, $1, $3); }
        | expr '-' expr                                   { $$ = new cdk::sub_node(LINE, $1, $3); }
        | expr '*' expr                                   { $$ = new cdk::mul_node(LINE, $1, $3); }
        | expr '/' expr                                   { $$ = new cdk::div_node(LINE, $1, $3); }
        | expr '%' expr                                   { $$ = new cdk::mod_node(LINE, $1, $3); }
        | expr '<' expr                                   { $$ = new cdk::lt_node(LINE, $1, $3); }
        | expr '>' expr                                   { $$ = new cdk::gt_node(LINE, $1, $3); }
        | expr tGE expr                                   { $$ = new cdk::ge_node(LINE, $1, $3); }
        | expr tLE expr                                   { $$ = new cdk::le_node(LINE, $1, $3); }
        | expr tNE expr                                   { $$ = new cdk::ne_node(LINE, $1, $3); }
        | expr tEQ expr                                   { $$ = new cdk::eq_node(LINE, $1, $3); }
        | expr '|' expr                                   { $$ = new pwn::or_node(LINE, $1, $3); }
        | expr '&' expr                                   { $$ = new pwn::and_node(LINE, $1, $3); }
        | lval '?'                                        { $$ = new pwn::address_node(LINE, $1); }
        | lval                                            { $$ = new pwn::rvalue_node(LINE, $1); }
        | lval '=' expr                                   { $$ = new pwn::assignment_node(LINE, $1, $3); }
        | '(' expr ')'                                    { $$ = $2; }
        | literal                                         { $$ = $1; }
        | f_call                                          { $$ = $1; }
        ;

literal : tINTEGER    { $$ = new cdk::integer_node(LINE, $1); }
        | tSTRING     { $$ = new cdk::string_node(LINE, $1); }
        | tNOOB       { $$ = new pwn::noob_node(LINE); }
        ;

lval    : tID          { $$ = new pwn::lvalue_node(LINE, $1); /* FIXME*/ }
        | tID '[' expr ']' { $$ = new pwn::index_node(LINE, $1, $3); }
        ;

%%
