#include <vector>
#include <string>

enum class TokenType
{
  Operator, //anything that conists of the characters dedicated to operators
  Number, //consisting of digits only
  Word, //starts with letters or underscore, can have digits as non-first character
  Singleton //a singular character that has a specific meaning (mostly brackets and semicolon)
};

enum class CharType
{
  Whitespace,
  Digit,
  NameChar, //letters and underscores
  Operator,
  Singleton,
  Unknown
};

namespace char_tests
{
  bool is_whitespace(char ch);
  bool is_digit(char ch);
  bool is_name_char(char ch);
  bool is_operator_char(char ch);
  bool is_singleton(char ch);
};

CharType get_char_type(char ch);

struct Token
{
  std::string contents;
  std::size_t line_index;
  TokenType type;
  Token(std::string contents, std::size_t line_index, TokenType type);
};

std::vector<Token> get_tokens_from_file(std::string filename);
