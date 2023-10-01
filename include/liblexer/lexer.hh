#ifndef LIBLEXER_LEXER_HH
#define LIBLEXER_LEXER_HH

#include <liblexer/lexer_rule.hh>
#include <liblexer/lexem.hh>
#include <liblexer/error.hh>
#include <vector>

template<typename Token>
class Lexer {
    private:
        std::vector<LexerRule<Token>> rules;
    public:
        Lexer(std::vector<LexerRule<Token>> rules) :
            rules(rules) {
        }
        std::vector<Lexem<Token>> process(std::string text) const {
            std::vector<Lexem<Token>> lexems = {};
            auto beginIt = text.cbegin();
            auto endIt = text.cend();
            std::string match;
            bool matched;
            while (beginIt != endIt) {
                matched = false;
                for (const LexerRule<Token>& rule : rules) {
                    match = rule.match(beginIt, endIt);
                    if (match.size() != 0) {
                        if (! rule.doIgnore())
                            lexems.push_back(Lexem<Token>(match, rule.getToken()));
                        beginIt += match.size();
                        matched = true;
                        break;
                    }
                }
                if (! matched) {
                    throw LexerError<Token>("not matching token found for \n" + std::string(beginIt, endIt));
                }
            }
            return lexems;
        }
};

#endif
