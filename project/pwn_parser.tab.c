/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "pwn_parser.y"
/* $Id: pwn_parser.y,v 1.29 2015/05/19 16:38:00 ist175741 Exp $*/
/*-- don't change *any* of these: if you do, you'll break the compiler.*/
#include <cdk/compiler.h>
#include "ast/all.h"
#define LINE       compiler->scanner()->lineno()
#define yylex()    compiler->scanner()->scan()
#define yyerror(s) compiler->scanner()->error(s)
#define YYPARSE_PARAM_TYPE std::shared_ptr<cdk::compiler>
#define YYPARSE_PARAM      compiler
/*-- don't change *any* of these --- END!*/
#line 14 "pwn_parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
  int                   i;          /* integer value */
  double                d;	        /* double value */
  std::string          *s;	        /* symbol name or string literal */
  cdk::basic_node	     *node;	      /* node pointer */
  cdk::sequence_node	 *sequence;
  cdk::expression_node *expression; /* expression nodes */
  pwn::lvalue_node     *lvalue;
  pwn::block_node      *block;
  basic_type           *t;	        /*basic_type*/
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "pwn_parser.y"
/*-- The rules below will be included in yyparse, the main parsing function.*/
#line 53 "pwn_parser.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define tINTEGER 257
#define tDOUBLE 258
#define tID 259
#define tSTRING 260
#define tREPEAT 261
#define tIF 262
#define tPRINT 263
#define tREAD 264
#define tBEGIN 265
#define tEND 266
#define tNEXT 267
#define tSTOP 268
#define tLOCAL 269
#define tIMPORT 270
#define tRETURN 271
#define tNOOB 272
#define tTYPE_INT 273
#define tPLN 274
#define tVOID 275
#define tINT 276
#define tIFX 277
#define tELSE 278
#define tGE 279
#define tLE 280
#define tEQ 281
#define tNE 282
#define tUNARY 283
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    6,    6,    2,    2,    2,    3,    3,    3,    3,
    4,    4,    4,    4,    4,    4,    5,    5,    5,    5,
    5,    5,   12,   12,   15,   15,    8,    8,    7,    7,
   14,   14,   14,   14,    9,    9,    1,    1,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   10,   10,   10,   10,   10,   10,   10,   10,   10,   10,
   11,   11,   11,   13,   13,
};
static const YYINT yylen[] = {                            2,
    1,    1,    2,    2,    2,    1,    4,    2,    2,    4,
    4,    5,    5,    4,    5,    4,    6,    6,    6,    5,
    5,    5,    3,    4,    1,    1,    1,    3,    2,    4,
    4,    3,    3,    2,    1,    2,    2,    2,    2,    3,
    2,    3,    1,    5,    7,    9,    8,    2,    2,    2,
    2,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    2,    1,    3,    3,    1,    1,
    1,    1,    1,    1,    4,
};
static const YYINT yydefred[] = {                         0,
   26,    0,   25,    0,    0,    2,    0,    0,    6,    0,
    0,    0,    0,    4,    5,    3,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   10,    0,    0,
   71,   72,   73,    7,    0,   21,    0,    0,   29,   22,
    0,   20,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   34,   35,    0,    0,    0,   69,
   70,    0,   43,   18,    0,   19,   17,    0,    0,    0,
    0,    0,   41,    0,   39,   48,    0,   51,   49,   50,
   32,    0,   33,   36,   37,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,
   65,   30,   23,    0,    0,    0,    0,    0,    0,   42,
   40,   68,   31,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   54,   55,   56,    0,   24,    0,   75,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   45,   47,    0,   46,
};
static const YYINT yydgoto[] = {                          5,
   56,    6,    7,    8,    9,   10,   24,  104,   58,   59,
   60,   61,   62,   63,   11,
};
static const YYINT yysindex[] = {                       -21,
    0, -241,    0, -234,    0,    0, -219, -211,    0,  -21,
 -202,   24,  -37,    0,    0,    0,  -27,  -35,  -26, -207,
  -25, -222,  -48,    7, -175,  -48,   12,    0,  -48,   49,
    0,    0,    0,    0,  555,    0,  -48, -253,    0,    0,
  -48,    0,  -48,  -39,    0,   48,   61, -240, -212, -177,
   37,   37,   37,   37,    0,    0,  575,  386,   36,    0,
    0,  -30,    0,    0, -141,    0,    0,  622,   37,  231,
   37, -146,    0, -139,    0,    0,  225,    0,    0,    0,
    0,  595,    0,    0,    0,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,    0,   37,
    0,    0,    0,   58,  508,  343,   37,  390,  423,    0,
    0,    0,    0,  522,  529,  100,  100,  100,  100,  100,
  100,   29,   29,    0,    0,    0,  508,    0,   37,    0,
  434,   37,  642,  508,   37,  455, -153,  481,   37,  642,
  642,  492,    0,    0,  642,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  134,
    0,    0, -126,    0,    0,    0, -122,    0,    0,    0,
    0,    0, -219,    0,    0, -115,    0,    0, -114,    0,
    0,    0,    0,    0,    0,    0, -113,    0,    0,    0,
 -211,    0, -112,  -33,   25,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   -1,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   67,    0,    0,    0,    0,    0,
    0,    0,    0,   95,  360,   88,   97,  129,  136,  164,
  176,   62,   71,    0,    0,    0,   53,    0,    0,    0,
    0,    0,    0,   69,    0,    0,  616,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
  280,   -8,    0,    0,    0,  121,   98,    0,  101,  854,
  139,    0,    0,  142,    1,
};
#define YYTABLESIZE 993
static const YYINT yytable[] = {                         74,
   68,   16,   19,   74,   74,   23,    1,   74,   74,   74,
   74,   74,   21,   74,   26,   29,   72,   12,   25,   25,
    4,   25,    3,   20,   13,   73,   74,   74,   74,   74,
  100,   66,  101,   22,   31,   66,   66,   32,   65,   66,
   66,   66,   66,   66,   74,   66,   14,   37,   16,   33,
   38,   69,   41,   75,   15,   38,   17,   72,   66,   74,
   66,   72,   72,   18,   28,   98,   72,   72,   99,   72,
   96,   72,   98,   87,   35,   97,   51,   96,   94,   53,
   95,   54,   97,   39,   72,   67,   72,   70,   76,   43,
   74,   66,   38,   67,   52,   93,   67,   92,  128,   52,
   71,  129,   52,   53,   52,   52,   52,   27,   53,   28,
   27,   53,   28,   53,   53,   53,   27,  102,   30,  110,
   59,   52,   66,   52,  140,   59,  111,   63,   59,   60,
   53,   59,   53,    1,   60,   63,   98,   60,   63,    9,
   60,   96,   94,    8,   95,   67,   97,   59,   72,   59,
   16,   11,   13,   12,   52,   57,   60,   82,   60,   86,
   34,   62,   52,   53,   36,    0,   62,   40,   61,   62,
   42,    0,   62,   61,    0,    0,   61,    0,   64,   61,
   59,    0,   66,    0,   67,   52,    0,   63,   62,   60,
   62,    0,    0,    0,   53,   61,   58,   61,    0,    0,
    0,   58,    0,    0,   58,    0,    0,   58,   57,    0,
    0,   59,    0,   57,    0,    0,   57,    0,   63,   57,
   60,   62,    0,   58,    1,   58,    0,    0,   61,    0,
    0,    0,   74,    1,    1,   57,    0,   57,    1,    0,
    3,    0,    0,    0,    0,   74,   74,   74,   74,    3,
    3,    0,   62,    2,    3,    0,   58,    0,    0,   61,
    0,   98,   87,    0,   66,  112,   96,   94,   57,   95,
   51,   97,    0,   53,  107,   54,    0,   66,   66,   66,
   66,    0,    0,   26,   93,    0,   92,   58,    0,    0,
   72,    0,    0,   31,    0,   44,   32,    0,    0,   57,
    0,   85,    0,   72,   72,   72,   72,    0,   33,    0,
    0,    0,    0,    0,   88,   89,   90,   91,   67,    0,
    0,    0,    0,    0,    0,    0,    0,   52,    0,    0,
    0,    0,    0,    0,    0,    0,   53,   84,    0,    0,
   52,   52,   52,   52,    0,    0,    0,    0,   86,   53,
   53,   53,   53,   59,    0,    0,   52,    0,    0,    0,
   63,   84,   60,    0,    0,    0,   59,   59,   59,   59,
    0,    0,    0,    0,    0,   60,   60,   60,   60,   98,
   87,    0,    0,    0,   96,   94,    0,   95,    0,   97,
    0,    0,   64,    0,   62,    0,    0,   64,    0,    0,
   64,   61,   93,   64,   92,    0,    0,   62,   62,   62,
   62,    0,  137,    0,   61,   61,   61,   61,    0,  143,
  144,    0,    0,    0,  146,   51,   98,   87,   53,   58,
   54,   96,   94,  132,   95,  130,   97,    0,    0,    0,
    0,   57,   58,   58,   58,   58,    0,    0,    0,   93,
    0,   92,   64,    0,   57,   57,   57,   57,    0,   98,
   87,    0,    0,  133,   96,   94,   86,   95,    0,   97,
   98,   87,    0,    0,    0,   96,   94,  135,   95,    0,
   97,    0,   93,   64,   92,    0,    0,   31,    0,   44,
   32,   98,   87,   93,    0,   92,   96,   94,  139,   95,
    0,   97,   33,   88,   89,   90,   91,    0,   35,    0,
   83,   52,    0,   86,   93,    0,   92,   98,   87,    0,
    0,  141,   96,   94,    0,   95,    0,   97,   98,   87,
    0,    0,  145,   96,   94,    0,   95,    0,   97,    0,
   93,    0,   92,    0,   98,   87,   86,    0,    0,   96,
   94,   93,   95,   92,   97,    0,    0,   86,   98,   87,
    0,    0,    0,   96,   94,   98,   95,   93,   97,   92,
   96,   94,    0,   95,    0,   97,    0,    0,   86,    0,
    0,   93,    0,   92,    0,    0,    0,    0,   93,    0,
   92,    0,    0,    0,   51,    0,    4,   53,    0,   54,
    0,    0,    0,    0,   86,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   51,   86,    4,   53,    0,   54,
    0,   88,   89,   90,   91,   64,    0,    0,    0,    0,
    0,   86,    0,    0,   51,    0,    0,   53,    0,   54,
    0,    0,   31,    0,   44,   32,   46,   47,    0,    0,
    0,    0,   48,   49,    0,   44,   50,   33,   44,    0,
   44,   51,  103,    0,   53,    0,   54,    0,   88,   89,
   90,   91,    0,    0,    0,    0,    0,   35,    0,   55,
   52,   51,    0,    0,   53,    0,   54,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   35,    0,   81,
   52,   88,   89,   90,   91,    0,    0,    0,    0,    0,
    0,    0,   88,   89,   90,   91,    0,   35,    0,  113,
   52,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   88,   89,   90,   91,    0,   44,    0,
   44,   44,    0,    0,    0,    0,    0,   52,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   88,
   89,   90,   91,    0,   35,    0,    0,   52,    0,    0,
   88,   89,   90,   91,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,   89,   90,   91,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   88,   89,   90,   91,    0,    0,    0,   88,   89,   90,
   91,   31,    0,   44,   45,   46,   47,    0,    0,    0,
    0,   48,   49,    0,    0,   50,   33,    0,    0,    2,
    3,   31,    0,   44,   45,   46,   47,    0,    0,    0,
    0,   48,   49,    0,    0,   50,   33,    0,    0,    2,
    3,   31,    0,   44,   32,   46,   47,    0,    0,    0,
    0,   48,   49,    0,    0,   50,   33,    0,    0,    0,
    0,    0,   44,    0,   44,   44,   44,   44,   31,    0,
   44,   32,   44,   44,    0,    0,   44,   44,    0,    0,
    0,    0,    0,   33,    0,    0,    0,    0,   31,    0,
   44,   32,   46,   47,   77,   78,   79,   80,   48,   49,
    0,    0,   50,   33,    0,    0,    0,    0,    0,    0,
    0,  105,  106,  108,  109,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  114,
  115,  116,  117,  118,  119,  120,  121,  122,  123,  124,
  125,  126,    0,  127,    0,    0,    0,    0,    0,    0,
  131,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  134,    0,    0,  136,    0,    0,  138,    0,
    0,    0,  142,
};
static const YYINT yycheck[] = {                         33,
   40,   10,   40,   37,   38,   41,  260,   41,   42,   43,
   44,   45,   40,   47,   41,   41,  257,  259,   18,   19,
   42,   21,  276,   61,  259,  266,   60,   61,   62,   63,
   61,   33,   63,   61,  257,   37,   38,  260,   38,   41,
   42,   43,   44,   45,  257,   47,  266,   41,   57,  272,
   44,   91,   41,  266,  266,   44,  259,   33,   60,   93,
   62,   37,   38,   40,  272,   37,   42,   43,   33,   45,
   42,   47,   37,   38,  123,   47,   40,   42,   43,   43,
   45,   45,   47,  259,   60,   33,   62,   40,  266,   41,
  124,   93,   44,   41,   33,   60,   44,   62,   41,   38,
   40,   44,   41,   33,   43,   44,   45,   41,   38,   41,
   44,   41,   44,   43,   44,   45,   19,  259,   21,  266,
   33,   60,  124,   62,  278,   38,  266,   33,   41,   33,
   60,   44,   62,    0,   38,   41,   37,   41,   44,  266,
   44,   42,   43,  266,   45,   93,   47,   60,  124,   62,
  266,  266,  266,  266,   93,   35,   60,   57,   62,  124,
   22,   33,  126,   93,   23,   -1,   38,   26,   33,   41,
   29,   -1,   44,   38,   -1,   -1,   41,   -1,   37,   44,
   93,   -1,   41,   -1,   43,  124,   -1,   93,   60,   93,
   62,   -1,   -1,   -1,  124,   60,   33,   62,   -1,   -1,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   33,   -1,
   -1,  124,   -1,   38,   -1,   -1,   41,   -1,  124,   44,
  124,   93,   -1,   60,  260,   62,   -1,   -1,   93,   -1,
   -1,   -1,  266,  260,  260,   60,   -1,   62,  260,   -1,
  276,   -1,   -1,   -1,   -1,  279,  280,  281,  282,  276,
  276,   -1,  124,  275,  276,   -1,   93,   -1,   -1,  124,
   -1,   37,   38,   -1,  266,   41,   42,   43,   93,   45,
   40,   47,   -1,   43,   44,   45,   -1,  279,  280,  281,
  282,   -1,   -1,  259,   60,   -1,   62,  124,   -1,   -1,
  266,   -1,   -1,  257,   -1,  259,  260,   -1,   -1,  124,
   -1,  266,   -1,  279,  280,  281,  282,   -1,  272,   -1,
   -1,   -1,   -1,   -1,  279,  280,  281,  282,  266,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  266,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  266,   58,   -1,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,   -1,  124,  279,
  280,  281,  282,  266,   -1,   -1,  126,   -1,   -1,   -1,
  266,   82,  266,   -1,   -1,   -1,  279,  280,  281,  282,
   -1,   -1,   -1,   -1,   -1,  279,  280,  281,  282,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   33,   -1,  266,   -1,   -1,   38,   -1,   -1,
   41,  266,   60,   44,   62,   -1,   -1,  279,  280,  281,
  282,   -1,  133,   -1,  279,  280,  281,  282,   -1,  140,
  141,   -1,   -1,   -1,  145,   40,   37,   38,   43,  266,
   45,   42,   43,   44,   45,   93,   47,   -1,   -1,   -1,
   -1,  266,  279,  280,  281,  282,   -1,   -1,   -1,   60,
   -1,   62,   93,   -1,  279,  280,  281,  282,   -1,   37,
   38,   -1,   -1,   41,   42,   43,  124,   45,   -1,   47,
   37,   38,   -1,   -1,   -1,   42,   43,   44,   45,   -1,
   47,   -1,   60,  124,   62,   -1,   -1,  257,   -1,  259,
  260,   37,   38,   60,   -1,   62,   42,   43,   44,   45,
   -1,   47,  272,  279,  280,  281,  282,   -1,  123,   -1,
  125,  126,   -1,  124,   60,   -1,   62,   37,   38,   -1,
   -1,   41,   42,   43,   -1,   45,   -1,   47,   37,   38,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,   -1,
   60,   -1,   62,   -1,   37,   38,  124,   -1,   -1,   42,
   43,   60,   45,   62,   47,   -1,   -1,  124,   37,   38,
   -1,   -1,   -1,   42,   43,   37,   45,   60,   47,   62,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,  124,   -1,
   -1,   60,   -1,   62,   -1,   -1,   -1,   -1,   60,   -1,
   62,   -1,   -1,   -1,   40,   -1,   42,   43,   -1,   45,
   -1,   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   40,  124,   42,   43,   -1,   45,
   -1,  279,  280,  281,  282,  266,   -1,   -1,   -1,   -1,
   -1,  124,   -1,   -1,   40,   -1,   -1,   43,   -1,   45,
   -1,   -1,  257,   -1,  259,  260,  261,  262,   -1,   -1,
   -1,   -1,  267,  268,   -1,   40,  271,  272,   43,   -1,
   45,   40,   41,   -1,   43,   -1,   45,   -1,  279,  280,
  281,  282,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
  126,   40,   -1,   -1,   43,   -1,   45,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,  125,
  126,  279,  280,  281,  282,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  279,  280,  281,  282,   -1,  123,   -1,  125,
  126,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  279,  280,  281,  282,   -1,  123,   -1,
  125,  126,   -1,   -1,   -1,   -1,   -1,  126,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  279,
  280,  281,  282,   -1,  123,   -1,   -1,  126,   -1,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  279,  280,  281,  282,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  279,  280,  281,  282,   -1,   -1,   -1,  279,  280,  281,
  282,  257,   -1,  259,  260,  261,  262,   -1,   -1,   -1,
   -1,  267,  268,   -1,   -1,  271,  272,   -1,   -1,  275,
  276,  257,   -1,  259,  260,  261,  262,   -1,   -1,   -1,
   -1,  267,  268,   -1,   -1,  271,  272,   -1,   -1,  275,
  276,  257,   -1,  259,  260,  261,  262,   -1,   -1,   -1,
   -1,  267,  268,   -1,   -1,  271,  272,   -1,   -1,   -1,
   -1,   -1,  257,   -1,  259,  260,  261,  262,  257,   -1,
  259,  260,  267,  268,   -1,   -1,  271,  272,   -1,   -1,
   -1,   -1,   -1,  272,   -1,   -1,   -1,   -1,  257,   -1,
  259,  260,  261,  262,   51,   52,   53,   54,  267,  268,
   -1,   -1,  271,  272,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   68,   69,   70,   71,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   86,
   87,   88,   89,   90,   91,   92,   93,   94,   95,   96,
   97,   98,   -1,  100,   -1,   -1,   -1,   -1,   -1,   -1,
  107,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  129,   -1,   -1,  132,   -1,   -1,  135,   -1,
   -1,   -1,  139,
};
#define YYFINAL 5
#ifndef YYDEBUG
#define YYDEBUG 1
#endif
#define YYMAXTOKEN 283
#define YYUNDFTOKEN 301
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,0,0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,0,0,
0,0,0,0,0,0,0,"'<'","'='","'>'","'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"tINTEGER","tDOUBLE","tID",
"tSTRING","tREPEAT","tIF","tPRINT","tREAD","tBEGIN","tEND","tNEXT","tSTOP",
"tLOCAL","tIMPORT","tRETURN","tNOOB","tTYPE_INT","tPLN","tVOID","tINT","tIFX",
"tELSE","tGE","tLE","tEQ","tNE","tUNARY",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file : decs",
"decs : dec",
"decs : decs dec",
"dec : v_dec tEND",
"dec : f_dec tEND",
"dec : f_def",
"v_dec : type tID '=' literal",
"v_dec : type tID",
"v_dec : '*' tID",
"v_dec : '*' tID '=' tNOOB",
"f_dec : type tID '(' ')'",
"f_dec : type tID '(' vars ')'",
"f_dec : tVOID tID '(' vars ')'",
"f_dec : tVOID tID '(' ')'",
"f_dec : '*' tID '(' vars ')'",
"f_dec : '*' tID '(' ')'",
"f_def : type tID '(' vars ')' body",
"f_def : tVOID tID '(' vars ')' body",
"f_def : '*' tID '(' vars ')' body",
"f_def : type tID '(' ')' body",
"f_def : tVOID tID '(' ')' body",
"f_def : '*' tID '(' ')' body",
"f_call : tID '(' ')'",
"f_call : tID '(' arg_call ')'",
"type : tINT",
"type : tSTRING",
"arg_call : expr",
"arg_call : arg_call ',' expr",
"vars : type tID",
"vars : vars ',' type tID",
"body : '{' decs stmts '}'",
"body : '{' decs '}'",
"body : '{' stmts '}'",
"body : '{' '}'",
"stmts : stmt",
"stmts : stmts stmt",
"stmt : expr tEND",
"stmt : expr '!'",
"stmt : tSTOP tEND",
"stmt : tSTOP tINTEGER tEND",
"stmt : tNEXT tEND",
"stmt : tNEXT tINTEGER tEND",
"stmt : body",
"stmt : tIF '(' expr ')' stmt",
"stmt : tIF '(' expr ')' stmt tELSE stmt",
"stmt : tREPEAT '(' expr ',' expr ',' expr ')' stmt",
"stmt : tREPEAT '(' ',' expr ',' expr ')' stmt",
"stmt : tRETURN tEND",
"expr : '+' expr",
"expr : '-' expr",
"expr : '~' expr",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr tGE expr",
"expr : expr tLE expr",
"expr : expr tNE expr",
"expr : expr tEQ expr",
"expr : expr '|' expr",
"expr : expr '&' expr",
"expr : lval '?'",
"expr : lval",
"expr : lval '=' expr",
"expr : '(' expr ')'",
"expr : literal",
"expr : f_call",
"literal : tINTEGER",
"literal : tSTRING",
"literal : tNOOB",
"lval : tID",
"lval : tID '[' expr ']'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 58 "pwn_parser.y"
	{ compiler->ast(yystack.l_mark[0].sequence); }
break;
case 2:
#line 61 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 3:
#line 62 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 4:
#line 65 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 5:
#line 66 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[-1].node; }
break;
case 6:
#line 67 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].node; }
break;
case 7:
#line 70 "pwn_parser.y"
	{ yyval.node = new pwn::var_dec_node(LINE, yystack.l_mark[-3].t, yystack.l_mark[-2].s, yystack.l_mark[0].expression); }
break;
case 8:
#line 71 "pwn_parser.y"
	{ yyval.node = new pwn::var_dec_node(LINE, yystack.l_mark[-1].t, yystack.l_mark[0].s); }
break;
case 9:
#line 72 "pwn_parser.y"
	{ yyval.node = new pwn::var_dec_node(LINE, new basic_type(4, basic_type::TYPE_POINTER), yystack.l_mark[0].s); }
break;
case 10:
#line 73 "pwn_parser.y"
	{ yyval.node = new pwn::var_dec_node(LINE, new basic_type(4, basic_type::TYPE_POINTER), yystack.l_mark[-2].s, new pwn::noob_node(LINE)); }
break;
case 11:
#line 76 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-2].s, NULL, yystack.l_mark[-3].t, true); }
break;
case 12:
#line 77 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, yystack.l_mark[-4].t, true); }
break;
case 13:
#line 78 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, new basic_type(0,basic_type::TYPE_VOID), true); }
break;
case 14:
#line 79 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-2].s, NULL, new basic_type(0,basic_type::TYPE_VOID), true); }
break;
case 15:
#line 80 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence, new basic_type(4,basic_type::TYPE_POINTER), true); }
break;
case 16:
#line 81 "pwn_parser.y"
	{ yyval.node = new pwn::function_dec_node(LINE, yystack.l_mark[-2].s, NULL, new basic_type(4,basic_type::TYPE_POINTER), true); }
break;
case 17:
#line 84 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, yystack.l_mark[-5].t, yystack.l_mark[0].block, true); }
break;
case 18:
#line 85 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[0].block, true); }
break;
case 19:
#line 86 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-4].s, yystack.l_mark[-2].sequence, new basic_type(4,basic_type::TYPE_POINTER), yystack.l_mark[0].block, true); }
break;
case 20:
#line 87 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-3].s, NULL, yystack.l_mark[-4].t, yystack.l_mark[0].block, true); }
break;
case 21:
#line 88 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-3].s, NULL, new basic_type(0,basic_type::TYPE_VOID), yystack.l_mark[0].block, true); }
break;
case 22:
#line 89 "pwn_parser.y"
	{ yyval.node = new pwn::function_def_node(LINE, yystack.l_mark[-3].s, NULL, new basic_type(4,basic_type::TYPE_POINTER), yystack.l_mark[0].block, true); }
break;
case 23:
#line 92 "pwn_parser.y"
	{ yyval.expression = new pwn::function_call_node(LINE, yystack.l_mark[-2].s, NULL); }
break;
case 24:
#line 93 "pwn_parser.y"
	{ yyval.expression = new pwn::function_call_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].sequence); }
break;
case 25:
#line 96 "pwn_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_INT); }
break;
case 26:
#line 97 "pwn_parser.y"
	{ yyval.t = new basic_type(4, basic_type::TYPE_STRING); }
break;
case 27:
#line 100 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression); }
break;
case 28:
#line 101 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].expression, yystack.l_mark[-2].sequence); }
break;
case 29:
#line 104 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new pwn::var_node(LINE, yystack.l_mark[-1].t, yystack.l_mark[0].s)); }
break;
case 30:
#line 105 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, new pwn::var_node(LINE, yystack.l_mark[-1].t, yystack.l_mark[0].s), yystack.l_mark[-3].sequence); }
break;
case 31:
#line 108 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-2].sequence, yystack.l_mark[-1].sequence); }
break;
case 32:
#line 109 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, yystack.l_mark[-1].sequence, NULL); }
break;
case 33:
#line 110 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, NULL, yystack.l_mark[-1].sequence); }
break;
case 34:
#line 111 "pwn_parser.y"
	{ yyval.block = new pwn::block_node(LINE, NULL, NULL); }
break;
case 35:
#line 114 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node); }
break;
case 36:
#line 115 "pwn_parser.y"
	{ yyval.sequence = new cdk::sequence_node(LINE, yystack.l_mark[0].node, yystack.l_mark[-1].sequence); }
break;
case 37:
#line 118 "pwn_parser.y"
	{ yyval.node = new pwn::evaluation_node(LINE, yystack.l_mark[-1].expression); }
break;
case 38:
#line 119 "pwn_parser.y"
	{ yyval.node = new pwn::print_node(LINE, yystack.l_mark[-1].expression); }
break;
case 39:
#line 120 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE); }
break;
case 40:
#line 121 "pwn_parser.y"
	{ yyval.node = new pwn::stop_node(LINE, yystack.l_mark[-1].i); }
break;
case 41:
#line 122 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE); }
break;
case 42:
#line 123 "pwn_parser.y"
	{ yyval.node = new pwn::next_node(LINE, yystack.l_mark[-1].i); }
break;
case 43:
#line 124 "pwn_parser.y"
	{ yyval.node = yystack.l_mark[0].block; }
break;
case 44:
#line 125 "pwn_parser.y"
	{ yyval.node = new cdk::if_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 45:
#line 126 "pwn_parser.y"
	{ yyval.node = new cdk::if_else_node(LINE, yystack.l_mark[-4].expression,yystack.l_mark[-2].node, yystack.l_mark[0].node); }
break;
case 46:
#line 127 "pwn_parser.y"
	{ yyval.node = new pwn::repeat_node(LINE, yystack.l_mark[-6].expression, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 47:
#line 128 "pwn_parser.y"
	{ yyval.node = new pwn::repeat_node(LINE, NULL, yystack.l_mark[-4].expression, yystack.l_mark[-2].expression, yystack.l_mark[0].node); }
break;
case 48:
#line 129 "pwn_parser.y"
	{ yyval.node = new pwn::return_node(LINE); }
break;
case 49:
#line 132 "pwn_parser.y"
	{ yyval.expression = new pwn::identity_node(LINE, yystack.l_mark[0].expression); }
break;
case 50:
#line 133 "pwn_parser.y"
	{ yyval.expression = new cdk::neg_node(LINE, yystack.l_mark[0].expression); }
break;
case 51:
#line 134 "pwn_parser.y"
	{ yyval.expression = new pwn::not_node(LINE, yystack.l_mark[0].expression); }
break;
case 52:
#line 135 "pwn_parser.y"
	{ yyval.expression = new cdk::add_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 53:
#line 136 "pwn_parser.y"
	{ yyval.expression = new cdk::sub_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 54:
#line 137 "pwn_parser.y"
	{ yyval.expression = new cdk::mul_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 55:
#line 138 "pwn_parser.y"
	{ yyval.expression = new cdk::div_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 56:
#line 139 "pwn_parser.y"
	{ yyval.expression = new cdk::mod_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 57:
#line 140 "pwn_parser.y"
	{ yyval.expression = new cdk::lt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 58:
#line 141 "pwn_parser.y"
	{ yyval.expression = new cdk::gt_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 59:
#line 142 "pwn_parser.y"
	{ yyval.expression = new cdk::ge_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 60:
#line 143 "pwn_parser.y"
	{ yyval.expression = new cdk::le_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 61:
#line 144 "pwn_parser.y"
	{ yyval.expression = new cdk::ne_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 62:
#line 145 "pwn_parser.y"
	{ yyval.expression = new cdk::eq_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 63:
#line 146 "pwn_parser.y"
	{ yyval.expression = new pwn::or_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 64:
#line 147 "pwn_parser.y"
	{ yyval.expression = new pwn::and_node(LINE, yystack.l_mark[-2].expression, yystack.l_mark[0].expression); }
break;
case 65:
#line 148 "pwn_parser.y"
	{ yyval.expression = new pwn::address_node(LINE, yystack.l_mark[-1].lvalue); }
break;
case 66:
#line 149 "pwn_parser.y"
	{ yyval.expression = new pwn::rvalue_node(LINE, yystack.l_mark[0].lvalue); }
break;
case 67:
#line 150 "pwn_parser.y"
	{ yyval.expression = new pwn::assignment_node(LINE, yystack.l_mark[-2].lvalue, yystack.l_mark[0].expression); }
break;
case 68:
#line 151 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[-1].expression; }
break;
case 69:
#line 152 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 70:
#line 153 "pwn_parser.y"
	{ yyval.expression = yystack.l_mark[0].expression; }
break;
case 71:
#line 156 "pwn_parser.y"
	{ yyval.expression = new cdk::integer_node(LINE, yystack.l_mark[0].i); }
break;
case 72:
#line 157 "pwn_parser.y"
	{ yyval.expression = new cdk::string_node(LINE, yystack.l_mark[0].s); }
break;
case 73:
#line 158 "pwn_parser.y"
	{ yyval.expression = new pwn::noob_node(LINE); }
break;
case 74:
#line 161 "pwn_parser.y"
	{ yyval.lvalue = new pwn::lvalue_node(LINE, yystack.l_mark[0].s); /* FIXME*/ }
break;
case 75:
#line 162 "pwn_parser.y"
	{ yyval.lvalue = new pwn::index_node(LINE, yystack.l_mark[-3].s, yystack.l_mark[-1].expression); }
break;
#line 1037 "pwn_parser.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
