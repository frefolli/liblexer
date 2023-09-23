#include "calc.hh"
#include <liblexer/lexer.hh>
#include <liblexer/lexer_rule.hh>
#include <liblexer/lexem.hh>
#include <iostream>

enum Token {
    INTEGER, ADD, SUB, MUL, DIV, LPAR, RPAR, SPACE, QUIT
};

std::ostream& operator<<(std::ostream& out, Token token) {
    switch (token) {
        case Token::INTEGER : out << "INTEGER"; break;
        case Token::ADD : out << "ADD"; break;
        case Token::SUB : out << "SUB"; break;
        case Token::MUL : out << "MUL"; break;
        case Token::DIV : out << "DIV"; break;
        case Token::LPAR : out << "LPAR"; break;
        case Token::RPAR : out << "RPAR"; break;
        case Token::SPACE : out << "SPACE"; break;
        case Token::QUIT : out << "QUIT"; break;
    }
    return out;
}

Lexer<Token> lexer ({
    {"^[0-9]+", Token::INTEGER, false},
    {"^\\+", Token::ADD, false},
    {"^\\-", Token::SUB, false},
    {"^\\*", Token::MUL, false},
    {"^\\\\", Token::DIV, false},
    {"^\\(", Token::LPAR, false},
    {"^\\)", Token::RPAR, false},
    {"^\\s+", Token::SPACE, true},
    {"^quit", Token::QUIT, false}
});

void RunCalc() {
    std::string line;
    std::vector<Lexem<Token>> lexems;
    std::cout << "liblexer/calc" << std::endl;
    bool active = true;
    while (active) {
        std::cout << ">> ";
        std::getline(std::cin, line);
        try {
            lexems = lexer.process(line);
            std::cout << "\"" << line << "\"" << std::endl;
            for (const Lexem<Token>& lexem : lexems) {
                std::cout << " -  " << lexem.toString() << std::endl;
                if (lexem.getToken() == Token::QUIT)
                    active = false;
            }
        } catch(LexerError<Token>& error) {
            std::cout << error.what() << " while processing:" << std::endl;
            std::cout << "\"" << line << "\"" << std::endl;
        }
    }
    std::cout << "safely quitting ..." << std::endl;
}
