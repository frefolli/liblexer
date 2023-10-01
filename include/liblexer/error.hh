#ifndef LIBLEXER_ERROR_HH
#define LIBLEXER_ERROR_HH

#include <stdexcept>

template<typename Token>
class LexerError : public std::runtime_error {
    private:
        std::string message;
    public:
        LexerError(std::string message) : std::runtime_error("") {
            this->message = "Lexer Error: " + message;
        }
        const char* what() {
            return this->message.c_str();
        }
};
#endif
