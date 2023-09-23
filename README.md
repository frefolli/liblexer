# Liblexer

A header-only lexer generator library, releasing the power of generic programming and reducing dependency between components: this library only declare miniman constructs to run a lexer, while you provide definitions as compile-time data.

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
    LexerRule(
        regex (or string),
        token,
        ignore // whether to append or not the token to result
    )
]
```

given the above formal definition we can write an example lexer:

```c++
Lexer<Token> lexer ({
    LexerRule<Token>("^[0-9]+", Token::INTEGER, false),
    ...
});
```

### Using the lexer
