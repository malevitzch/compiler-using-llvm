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
  Singleton,
  Unknown
};

struct TokenMetadata
{
  std::size_t line;
  TokenType token_type;
  TokenMetadata(size_t line, TokenType token_type);
};

std::vector<std::pair<std::string, TokenMetadata>> get_tokens_from_file(std::string filename);
