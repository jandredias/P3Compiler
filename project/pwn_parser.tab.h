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
extern YYSTYPE yylval;
