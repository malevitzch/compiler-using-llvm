#include <vector>
#include <string>

enum class Token
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
  Singleton
};

std::vector<std::string> get_tokens_from_file(std::string filename);
