#include "lexer.hpp"
#include <unordered_set>

namespace char_tests
{

  bool is_whitespace(char ch)
  {
    return isspace(ch);
  }
  
  bool is_digit(char ch)
  {
    return ch >= '0' && ch <= '9';
  }

  bool is_name_char(char ch)
  {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch == '_');
  }

  //TODO: make a different way to get operator characters
  bool is_operator_char(char ch) 
  {
    static std::unordered_set<char> operator_chars = {'+', '-', '*', '/', '=', '!', '<', '>', '?'};
    return operator_chars.count(ch);
  } 

  bool is_singleton(char ch)
  {
    //TODO: move the list of singleton characters somewhere?
    static std::unordered_set<char> singleton_chars = {'(', ')', ';'};
    return singleton_chars.count(ch);
  }

};

Token::Token(std::string contents, std::size_t line_index, TokenType type) : contents(contents), line_index(line_index), type(type) {}


std::vector<Token> get_tokens_from_file(std::string filename)
{
  std::vector<Token> tokens;
  std::size_t line_number = 0;
  return tokens;
}
