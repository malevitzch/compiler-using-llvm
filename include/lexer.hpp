#pragma once

#include <vector>
#include <string>
#include <unordered_set>

//forward declaration
class Trie;

enum class TokenType
{
  Operator, //anything that conists of the characters dedicated to operators
  Number, //consisting of digits only
  Word, //starts with letters or underscore, can have digits as non-first character
  Singleton, //a singular character that has a specific meaning (mostly brackets and semicolon)
  None //a dummy type existing solely for the purpose of indicating that there is no token currently
};

enum class CharType
{
  Whitespace, //anything that satisfies the isspace function
  Digit, //digits from 0 to 9
  NameChar, //letters and underscores
  Operator, //characters from a special list
  Singleton, //basically brackets and semicolon
  Unknown //anything that does not fit into any other category, this should be treated as an error, maybe assert for it when generating tokens
};

namespace char_tests
{
  bool is_whitespace(char ch);
  bool is_digit(char ch);
  bool is_name_char(char ch);
  bool is_operator_char(char ch);
  bool is_singleton(char ch);
};

//returns the character type
CharType get_char_type(char ch);

Trie& get_operator_symbol_trie();

struct Token
{
  std::string str;
  std::size_t line_index;
  TokenType type;

  Token(std::string str, std::size_t line_index, TokenType type);
  Token() = default;
};

std::unordered_set<std::string>& get_operator_symbols_noprefix();

std::vector<Token> split_operator_token(Token token);

std::vector<Token> split_operators(std::vector<Token> tokens);

std::vector<Token> get_tokens_from_file(std::string filename);
