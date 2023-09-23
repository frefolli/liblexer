#ifndef LIBLEXER_LEXEM_HH
#define LIBLEXER_LEXEM_HH

#include <string>
#include <ostream>

template<typename Token>
class Lexem {
    private:
        std::string match;
        Token token;
    public:
        Lexem(std::string match, Token token) :
            match(match), token(token) {
        }
        Token getToken() const {
            return token;
        }
        std::string getMatch() const {
            return match;
        }
        std::string toString() const {
            std::ostringstream rep ("");
            rep << "[" << token << ": \"" << match << "\"]";
            return rep.str();
        }
};

#endif
