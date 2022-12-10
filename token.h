class Token {
  private:

    string lexeme;
    int tokenCode;

  public:
    Token(string lexeme, int tokenCode) {
      this->lexeme = lexeme;
      this->tokenCode = tokenCode;
    }


    string getLexeme() const {
      return lexeme;
    }

    int getTokenCode() const {
      return tokenCode;
    }
};