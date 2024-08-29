#include <iostream>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/Verifier.h>
#include <llvm/Support/raw_ostream.h>

#include "lexer.hpp"

int main()
{

  std::cout << "Input the name of the file that you want to tokenize: ";
  std::string filename;
  std::cin>>filename;
  auto tokens = get_tokens_from_file(filename);
  for(auto token : tokens) std::cout << "[" << token.contents << "] ";
}
