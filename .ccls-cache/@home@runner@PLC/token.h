class Token {
  private:
    // The lexeme representation of the token.
    string lexeme;

    // The token code.
    int tokenCode;

  public:
    // Constructor for the Token class.
    Token(string lexeme, int tokenCode) {
      this->lexeme = lexeme;
      this->tokenCode = tokenCode;
    }

    // Returns the lexeme representation of the token.
    string getLexeme() const {
      return lexeme;
    }

    // Returns the token code.
    int getTokenCode() const {
      return tokenCode;
    }
};