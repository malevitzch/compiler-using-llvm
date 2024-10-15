#include "ast.hpp"

namespace ast
{

  BinaryOperator::BinaryOperator(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs, std::string name) 
  : lhs(std::move(lhs)), rhs(std::move(rhs)), name(name) {}

  void BinaryOperator::codegen() {/*TODO: implement */}
  
  UnaryOperator::UnaryOperator(std::unique_ptr<Expression> operand, std::string name)
  : operand(std::move(operand)), name(name) {}

  void UnaryOperator::codegen() {/*TODO: implement */}
}
