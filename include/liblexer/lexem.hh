#ifndef LIBLEXER_LEXEM_HH
#define LIBLEXER_LEXEM_HH

#include <string>
#include <ostream>

template<typename Token>
class Lexem {
    private:
        std::string string;
        Token token;
    public:
        Lexem(std::string string, Token token) :
            string(string), token(token) {
        }
        Token getToken() const {
            return token;
        }
        std::string getString() const {
            return string;
        }
        std::string toString() const {
            std::ostringstream rep ("");
            rep << "[" << token << ": \"" << string << "\"]";
            return rep.str();
        }
};

#endif
