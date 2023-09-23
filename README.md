# Liblexer

A header-only lexer generator library, releasing the power of generic programming and reducing dependency between components: this library only declares minimal constructs to run a lexer, while you provide definitions as compile-time data.

## Example: Calculator tokenizer

You can find full code [here](src/tests/calc.cc).

### Defining the Token

A lexer needs some king of Token to return as Lexem to you. Because of that we define in our codebase a `typename Token`, either in headers or implementation code dependending on specific needs.

Using `typename` as specifier we aren't tied to a `class` but we can have more various kinds of type. In this case an enum is enough.

```c++
enum Token {
    INTEGER, ...
};
```

### Defining the Lexer

Now that a token type exists in our scope, we can use it to define the lexer rules: the rules by which the lexer will be forming lexems with input as `std::string` and tokens.

```c++
Lexer = [
    LexerRule = (
        regex (or string),
        token,
        ignore // whether to append or not the token to result
    )
]
```

given the above formal definition we can write an example lexer:

```c++
Lexer<Token> lexer ({
    {"^[0-9]+", Token::INTEGER, false},
    ...
});
```

As you can see, it isn't so dirty to declare, just let Template Deduction do the rest for you.

### Using the lexer

The following example take a line for `std::cin` and tokenizes it with the lexer we just defined. If no lexem could be taken from a point of the string an error is raised by the lexer. Finally if the token `QUIT` is found, we close the program.

```c++
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
            for (Lexem<Token>& lexem : lexems) {
                std::cout << " -  " << lexem.toString() << std::endl;
                if (lexem.getToken() == Token::QUIT)
                    active = false;
            }
        } catch(const LexerError<Token>& error) {
            std::cout << error.what() << " while processing:" << std::endl;
            std::cout << "\"" << line << "\"" << std::endl;
        }
    }
    std::cout << "safely quitting ..." << std::endl;
}
```
