#include <memory>
namespace ast
{
  class ASTNode
  {
  private:
  public:
    virtual void codegen();
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
  };

  class BinaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> lhs;
    std::unique_ptr<Expression> rhs;
  public:
  };

  class UnaryOperator : public Expression
  {
  private:
    std::unique_ptr<Expression> operand;
  public:
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
