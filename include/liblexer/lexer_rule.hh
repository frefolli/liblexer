#ifndef LIBLEXER_LEXER_RULE_HH
#define LIBLEXER_LEXER_RULE_HH

#include <regex>
#include <string>
#include <ostream>

template<typename Token>
class LexerRule {
    private:
        std::regex expr;
        Token token;
        bool ignore;
    public: 
        LexerRule(std::string expr, Token token, bool ignore = false) : 
            expr(std::regex(expr)), token(token), ignore(ignore) {
        }
        LexerRule(std::regex expr, Token token, bool ignore = false) : 
            expr(expr), token(token), ignore(ignore) {
        }
        Token getToken() const {
            return token;
        }
        bool doIgnore() const {
            return ignore;
        }
        std::string match(std::string::const_iterator beginIt,
                          std::string::const_iterator endIt) const {
            std::smatch result;
            std::regex_search(beginIt, endIt,
                              result, expr,
                              std::regex_constants::match_continuous |
                                  std::regex_constants::match_not_null);
            return result.str();
        }
        std::string toString() const {
            std::ostringstream rep;
            rep << "["  << token << ", " << ignore <<  "]";
            return rep.str();
        }
};

#endif
