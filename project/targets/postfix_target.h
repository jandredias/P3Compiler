// $Id: postfix_target.h,v 1.1 2015/02/21 20:27:33 ist13500 Exp $
#ifndef __PWN_SEMANTICS_PFEVALUATOR_H__
#define __PWN_SEMANTICS_PFEVALUATOR_H__

#include <cdk/basic_target.h>
#include <cdk/symbol_table.h>
#include <cdk/ast/basic_node.h>
#include <cdk/compiler.h>
#include <cdk/emitters/postfix_ix86_emitter.h>
#include "targets/postfix_writer.h"
#include "targets/symbol.h"

namespace pwn {

  class postfix_target: public cdk::basic_target {
    static postfix_target _self;

  private:
    inline postfix_target() :
        cdk::basic_target("as") {
    }

  public:
    bool evaluate(std::shared_ptr<cdk::compiler> compiler) {
      // this symbol table will be used to check identifiers
      // during code generation
      cdk::symbol_table<pwn::symbol> symtab;

      // this is the backend postfix machine
      cdk::postfix_ix86_emitter pf(compiler);

      // generate assembly code from the syntax tree
      postfix_writer writer(compiler, symtab, pf);
      compiler->ast()->accept(&writer, 0);

      return true;
    }

  };

} // pwn

#endif
