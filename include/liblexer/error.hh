#ifndef LIBLEXER_ERROR_HH
#define LIBLEXER_ERROR_HH

#include <stdexcept>

template<typename Token>
class LexerError : public std::runtime_error {
    public:
        LexerError() : std::runtime_error("LexerError") {}
};

#endif
