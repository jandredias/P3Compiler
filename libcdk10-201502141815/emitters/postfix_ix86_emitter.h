// $Id: postfix_ix86_emitter.h,v 1.2 2014/02/25 21:43:13 david Exp $ -*- c++ -*-
#ifndef __CDK9_GENERATOR_IX86_H__
#define __CDK9_GENERATOR_IX86_H__

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cctype>
#include <cdk/emitters/basic_postfix_emitter.h>

namespace cdk {

  /** Class postfix_ix86_emitter: emitter for yasm/nasm code.  */
  class postfix_ix86_emitter: public basic_postfix_emitter {

    inline void debug(const std::string &s) {
      if (basic_postfix_emitter::debug()) {
        os() << "; " << s << std::endl;
      }
    }

    template<typename Type>
    inline void debug(const std::string &s, const Type &value) {
      if (basic_postfix_emitter::debug()) {
        os() << "; " << s << " " << value << std::endl;
      }
    }

    //----------------------------------------------------------------------

  public:
    inline postfix_ix86_emitter(std::shared_ptr<compiler> &compiler) :
        basic_postfix_emitter(compiler) {
      // Ensure that double literals are generated
      // in accordance with NASM rules.
      os() << std::setiosflags(std::ios::showpoint);
    }

    //----------------------------------------------------------------------

  private:
    template<typename T> void __cmd1(std::string mnemonic, T arg) {
      os() << "\t" << mnemonic << "\t" << arg << std::endl;
    }
    template<typename T1, typename T2> void __cmd2(std::string mnemonic, T1 arg1, T2 arg2) {
      os() << "\t" << mnemonic << "\t" << arg1 << ", " << arg2 << std::endl;
    }
    template<typename T> std::string _byte(T what) {
      std::ostringstream oss;
      oss << "byte " << what;
      return oss.str();
    }
    template<typename T> std::string _word(T what) {
      std::ostringstream oss;
      oss << "word " << what;
      return oss.str();
    }
    template<typename T> std::string _dword(T what) {
      std::ostringstream oss;
      oss << "dword " << what;
      return oss.str();
    }
    template<typename T> std::string _qword(T what) {
      std::ostringstream oss;
      oss << "qword " << what;
      return oss.str();
    }
    template<typename T> std::string _lbladdr(T what) {
      std::ostringstream oss;
      oss << "$" << what;
      return oss.str();
    }
    template<typename T> std::string _deref(T what) {
      std::ostringstream oss;
      oss << "[" << what << "]";
      return oss.str();
    }
    template<typename T> std::string _offset(T what, int offset) {
      std::ostringstream oss;
      if (offset < 0)
        oss << what << "-" << -offset;
      else if (offset > 0)
        oss << what << "+" << offset;
      else
        oss << what;
      return oss.str();
    }
    template<typename T> std::string _deref(T what, int offset) {
      return _deref(_offset(what, offset));
    }
    void _pop(std::string what) {
      __cmd1("pop", what);
    }
    void _push(std::string what) {
      __cmd1("push", what);
    }
    void _mov(std::string a, std::string b) {
      __cmd2("mov", a, b);
    }

    //!
    //! Arithmetic operations
    //!
    template<typename T> void _add(std::string a, T b) {
      __cmd2("add", a, b);
    }
    template<typename T> void _sub(std::string a, T b) {
      __cmd2("sub", a, b);
    }
    void _neg(std::string a) {
      __cmd1("neg", a);
    }
    void _imul(std::string a, std::string b) {
      __cmd2("imul", a, b);
    }

    /* Comparison */
    void _cmp(std::string a, std::string b) {
      __cmd2("cmp", a, b);
    }

    /* Logical operations */
    void _xor(std::string a, std::string b) {
      __cmd2("xor", a, b);
    }
    void _and(std::string a, std::string b) {
      __cmd2("and", a, b);
    }
    void _or(std::string a, std::string b) {
      __cmd2("or", a, b);
    }
    void _not(std::string a) {
      __cmd1("not", a);
    }

    /* Rotation and shift operations */
    void _rol(std::string a, std::string b) {
      __cmd2("rol", a, b);
    }
    void _ror(std::string a, std::string b) {
      __cmd2("ror", a, b);
    }
    void _sal(std::string a, std::string b) {
      __cmd2("sal", a, b);
    }
    void _sar(std::string a, std::string b) {
      __cmd2("sar", a, b);
    }
    void _shr(std::string a, std::string b) {
      __cmd2("shr", a, b);
    }

    /* Calls, jumps, etc. */
    void _call(std::string what) {
      __cmd1("call", what);
    }
    void _jmp(std::string what) {
      __cmd1("jmp", what);
    }

    /* Segments */
    void _segment(std::string what) {
      os() << "segment\t" << what << "\n";
    }

    /* Floating point */
    void _fild(std::string what) {
      __cmd1("fild", what);
    }
    void _fistp(std::string what) {
      __cmd1("fistp", what);
    }
    void _fld(std::string what) {
      __cmd1("fld", what);
    }
    void _fstp(std::string what) {
      __cmd1("fstp", what);
    }

    //----------------------------------------------------------------------

    // Implementation of the postfix interface

  public:

       void ORIG(int pos) {
         os() << "ORIG " << pos << std::endl;
       }
       void EQU(std::string label, int value) {
         os() << label << " EQU " << value << std::endl;
       }
       void WORD(std::string label, int value) {
         os() << label << " WORD " << value << std::endl;
       }
       void STR(std::string label, std::string value) {
         os() << label << " STR" << value << std::endl;
       }
       void TAB(std::string label, int value) {
         os() << label << " TAB " << value << std::endl;
       }
       void ADD() {
         os() << "POP R1" << std::endl;
         os() << "ADD M[SP + 1], R1" << std::endl;
       }
       void ADDC() {
         os() << "POP R1" << std::endl;
         os() << "ADDC M[SP + 1], R1" << std::endl;
       }
       void AND() {
         os() << "POP R1" << std::endl;
         os() << "AND M[SP + 1], R1" << std::endl;
       }
       void BRCOND(std::string cond, std::string value) {
        if(cond == std::to_string('C') || cond == std::string("NC") ||
            cond == std::to_string('N') || cond == std::string("NN") ||
            cond == std::to_string('O') || cond == std::string("NO") ||
            cond == std::to_string('Z') || cond == std::string("NZ") ||
            cond == std::to_string('I') || cond == std::string("NI") ||
            cond == std::to_string('P') || cond == std::string("NP")){
          os() << "BR." << cond << " " << value << std::endl;
        }
       }
       void BR(std::string label) {
         os() << "BR " << label << std::endl;
       }
       void CALL(std::string value) {
         os() << "CALL " << value << std::endl;
       }
       void CALLCOND(std::string cond, std::string value) {
         if(cond == std::to_string('C') || cond == std::string("NC") ||
            cond == std::to_string('N') || cond == std::string("NN") ||
            cond == std::to_string('O') || cond == std::string("NO") ||
            cond == std::to_string('Z') || cond == std::string("NZ") ||
            cond == std::to_string('I') || cond == std::string("NI") ||
            cond == std::to_string('P') || cond == std::string("NP")){
          os() << "CALL." << cond << " " << value << std::endl;
        }
       }
       void CLC() {
         os() << "CLC" << std::endl;
       }
       void CMC() {
         os() << "CMC" << std::endl;
       }
       void CMP() {
         os() << "CMP M[SP + 1], R1" << std::endl;
       }
       void COM() {
         os() << "COM M[SP + 1]" << std::endl;
       }
       void DEC() {
         os() << "DEC M[SP + 1]" << std::endl;
       }
       void DIV() {
         os() << "POP R1" << std::endl;
         os() << "POP R2" << std::endl;
         os() << "DIV R1, R2" << std::endl;
         os() << "PUSH R1" << std::endl;
         os() << "PUSH R2" << std::endl;
       }
       void DSI() {
         os() << "DSI" << std::endl;
       }
       void ENI() {
         os() << "ENI" << std::endl;
       }
       void INC() {
         os() << "INC M[SP + 1]" << std::endl;
       }
       void INT(int value) {
         os() << "INT " << value << std::endl;
       }
       void JMP(std::string value) {
         os() << "JMP " << value << std::endl;
       }
       void JMPCOND(std::string cond, std::string value) {
         if(cond == std::to_string('C') || cond == std::string("NC") ||
            cond == std::to_string('Z') || cond == std::string("NZ") ||
            cond == std::to_string('N') || cond == std::string("NN") ||
            cond == std::to_string('O') || cond == std::string("NO") ||
            cond == std::to_string('I') || cond == std::string("NI") ||
            cond == std::to_string('P') || cond == std::string("NP")){
          os() << "JMP." << cond << " " << value << std::endl;
        }
       }
       void MOD(){
         os() << "POP R1" << std::endl;
         os() << "DIV R1, M[SP + 1]" << std::endl;
       }
       void MOV(std::string a, std::string b) {
         os() << "MOV R1, " << b << std::endl;
         os() << "MOV " << a << ", R1" << std::endl;
       }
       void MUL() {
         os() << "POP R1" << std::endl;
         os() << "MUL M[SP + 1], R1" << std::endl;
         os() << "PUSH R1" << std::endl;
       }
       void MVBH() {
         os() << "POP R1" << std::endl;
         os() << "MVBH M[SP + 1], R1" << std::endl;
       }
       void MVBL() {
         os() << "POP R1" << std::endl;
         os() << "MVBL M[SP + 1], R1" << std::endl;
       }
       void NEG() {
         os() << "NEG M[SP + 1]" << std::endl;
       }
       void NOP() {
         os() << "NOP" << std::endl;
       }
       void OR() {
         os() << "POP R1" << std::endl;
         os() << "OR M[SP + 1], R1" << std::endl;
       }
       void POP() {
         os() << "POP R1" << std::endl;
       }
       void PUSH(int value) {
         os() << "PUSH " << value << std::endl;
       }
       void RET() {
         os() << "RET" << std::endl;
       }
       void RETN(int value) {
         os() << "RET " << value << std::endl;
       }
       void ROL(int value) {
         os() << "ROL M[SP + 1], " << value << std::endl;
       }
       void ROLC(int value) {
         os() << "ROLC M[SP + 1], " << value << std::endl;
       }
       void ROR(int value) {
         os() << "ROR M[SP + 1], " << value << std::endl;
       }
       void RORC(int value) {
         os() << "RORC M[SP + 1], " << value << std::endl;
       }
       void RTI() {
         os() << "RTI" << std::endl;
       }
       void SHL(int value) {
         os() << "SHL M[SP + 1], " << value << std::endl;
       }
       void SHLA(int value) {
         os() << "SHLA M[SP + 1], " << value << std::endl;
       }
       void SHR(int value) {
         os() << "SHR M[SP + 1], " << value << std::endl;
       }
       void SHRA(int value) {
         os() << "SHRA M[SP + 1], " << value << std::endl;
       }
       void STC() {
         os() << "STC" << std::endl;
       }
       void SUB() {
         os() << "POP R1" << std::endl;
         os() << "SUB M[SP + 1], R1" << std::endl;
       }
       void SUBB() {
         os() << "POP R1" << std::endl;
         os() << "SUBB M[SP + 1], R1" << std::endl;
       }
       void TEST() {
         //TODO
       }
       void XCH() {
         os() << "POP R1" << std::endl;
         os() << "POP R2" << std::endl;
         os() << "PUSH R1" << std::endl;
         os() << "PUSH R2" << std::endl;
       }
       void XOR() {
         os() << "POP R1" << std::endl;
         os() << "XOR M[SP + 1], R1" << std::endl;
       }

       void LABEL(std::string label){
         os() << label << ":";
       }
       void TRASH(int value){
         for(auto i = 0; i < value; i++)
          os() << "POP R0" << std::endl;
       }
       void LOAD(){
         os() << "POP R1" << std::endl;
         os() << "MOV R2, M[R1]" << std::endl;
         os() << "PUSH R2" << std::endl;
       }
       void ADDR(std::string value){
         os() << "PUSH " << value << std::endl;
       }
       void STORE(){
         os() << "POP R1" << std::endl;
         os() << "POP R2" << std::endl;
         os() << "MOV M[R1], R2" << std::endl;
       }
       void DUP(){
         os() << "POP R1" << std::endl;
         os() << "PUSH R1" << std::endl;
         os() << "PUSH R1" << std::endl;
       }

  };

} // namespace cdk

#endif
