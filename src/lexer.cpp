#include <unordered_set>
#include <fstream>

#include "lexer.hpp"

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

CharType get_char_type(char ch)
{
  using namespace char_tests;
  if(is_whitespace(ch)) return CharType::Whitespace;
  if(is_digit(ch)) return CharType::Digit;
  if(is_name_char(ch)) return CharType::NameChar;
  if(is_operator_char(ch)) return CharType::Operator;
  if(is_singleton(ch)) return CharType::Singleton;
  return CharType::Unknown;
}

Token::Token(std::string str, std::size_t line_index, TokenType type) : str(str), line_index(line_index), type(type) {}

std::unordered_set<std::string> get_operator_symbols_noprefix()
{
  //TODO: replace the usage of this with Trie cause we actually need trie for stuff like -= 
  static std::unordered_set<std::string> operator_symbols = 
  {
      "+", "-", "=", "*", "/",
  };
  return operator_symbols;
}

std::vector<Token> split_operator_token(Token token)
{
  //TODO: implement
}

std::vector<Token> split_operators(std::vector<Token> tokens)
{
  std::vector<Token> split_tokens;
  for(Token& token : tokens)
  {
    if(token.type == TokenType::Operator)
    {
      std::vector<Token> split = split_operator_token(token);
      split_tokens.insert(split_tokens.end(), split.begin(), split.end());
    }
  }
  return tokens;
}

std::vector<Token> get_tokens_from_file(std::string filename)
{

  std::ifstream file(filename);

  file >> std::noskipws;

  if(file.fail())
  {
    return {};
    //TODO: file error here, but that's only once we do error handling  
  }

  std::vector<Token> tokens;
  std::size_t line_number = 0;
  
  char cur_char;
  std::string buffer = "";
  TokenType token_type = TokenType::None;
  
  //TODO: implement
  auto finish_token = [&]() -> void
  {
    //TODO: operators and trie
    if(buffer.empty()) return;
    tokens.push_back(Token(buffer, line_number, token_type)); 
    buffer = "";
    token_type = TokenType::None;
  };

  while(!file.eof())
  {
    file >> cur_char;
    CharType char_type = get_char_type(cur_char);

    if(char_type == CharType::Whitespace) 
    {
      finish_token();
      continue;
    }

    if(char_type == CharType::Digit)
    {

      if(token_type != TokenType::Word && token_type != TokenType::Number)
      {
        finish_token();
        token_type = TokenType::Number;
      }
      buffer += cur_char;

    }

    if(char_type == CharType::NameChar)
    {
      if(token_type != TokenType::Word) finish_token();
      token_type = TokenType::Word;
      buffer += cur_char;
    }
    
    if(char_type == CharType::Operator)
    {
      if(token_type != TokenType::Operator) finish_token();
      token_type = TokenType::Operator;
      buffer += cur_char;
    }

    if(char_type == CharType::Singleton)
    {
      finish_token();
      tokens.push_back(Token(std::string(1, cur_char), line_number, TokenType::Singleton));
    }
    
    if(char_type == CharType::Unknown)
    {
      //TODO: handle this
    }

  }

  return tokens;
}
