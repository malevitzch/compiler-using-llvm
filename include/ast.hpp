#include <memory>
#include <string>
#include <vector>

namespace ast
{
  class ASTNode
  {
  private:
  public:
    virtual void codegen() = 0;
  };

  class Statement : public ASTNode
  {
  private:
  public:
  };

  class Block : public ASTNode
  {
  private:
    std::vector<std::unique_ptr<Statement>> statements;
  public:
  };

  class Expression : public Statement
  {
  private:
  public:
  };

  class BinaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;
    std::string name;
  public:
    BinaryOperator(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs, std::string name); //TODO: 3rd argument is an object that represents the operator itself.
    void codegen();
  };

  class UnaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> operand;
    std::string name;
  public:
    UnaryOperator(std::unique_ptr<Expression> operand, std::string name); //TODO: 2nd argument is an object that represents the operator itself.
    void codegen();
  };
  
  class Value : public Expression
  {
  private:
  public:
  };

  //NOTE: Constants should probably be kept somewhere in a different type and the constant class should just reference the constant. 
  class Constant : public Value
  {
  private:
    std::string name;
  public:
    Constant(std::string name); //TODO: The argument should probably be something else than just the name.
  };
  
  //NOTE: Variables should be done the same way, the Variable class only contains a reference to an external structure that represents the var
  class Variable : public Value
  {
  private:
  public:
  };
}
