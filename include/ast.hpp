#include <memory>
#include <string>
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

  class Expression : public Statement
  {
  private:
  public:
    virtual void eval() = 0;
  };

  class BinaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;
    std::string name;
  public:
    BinaryOperator(std::unique_ptr<Expression> lhs, std::unique_ptr<Expression> rhs, std::string name); //TODO: 3rd argument is an object that represents the operator itself.
  };

  class UnaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> operand;
    std::string name;
  public:
    UnaryOperator(std::unique_ptr<Expression> operand, std::string name); //TODO: 2nd argument is an object that represents the operator itself.
  };
  
  class Value : public Expression
  {
  private:
  public:
  };

  class Constant : public Value
  {
  private:
  public:
  };
  
  class Variable : public Value
  {
  private:
  public:
  };
}
