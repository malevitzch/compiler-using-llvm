#include "ast.hpp"

namespace ast
{

  BinaryOperator::BinaryOperator(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs, std::string name) 
  : lhs(std::move(lhs)), rhs(std::move(rhs)), name(name) {}
  void BinaryOperator::codegen() {/*TODO: implement */}
  

}
