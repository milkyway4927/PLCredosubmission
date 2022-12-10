typedef struct Parser {

  Token* tokens;
  int numTokens;


  Node* parseTree;

  int currentToken;
} Parser;


Parser* Parser_create(Token* tokens, int numTokens) {
  // Allocate memory for a new Parser object.
  Parser* parser = (Parser*)malloc(sizeof(Parser));


  parser->tokens = tokens;
  parser->numTokens = numTokens;
  parser->currentToken = 0;


  return parser;
}


void Parser_generateParseTree(Parser* parser) {
  // Start the recursive descent parsing.
  parser->parseTree = Parser_parseExpression(parser);
}


Node* Parser_getParseTree(const Parser* parser) {
  return parser->parseTree;
}


void Parser_destroy(Parser* parser) {

  Parser_destroyNode(parser->parseTree);


  free(parser);
}


Node* Parser_parseExpression(Parser* parser) {

  Node* left = Parser_parseTerm(parser);


  if (parser->currentToken < parser->numTokens && parser->tokens[parser->currentToken].tokenCode == TOKEN_OPERATOR) {
    int operatorCode = parser->tokens[parser->currentToken].tokenCode;
    parser->currentToken++;

    Node* right = Parser_parseExpression(parser);


    Node* node = (Node*)malloc(sizeof(Node));
    node->tokenCode = operatorCode;
    node->left = left;
    node->right = right;
    return node;
  } else {

    return left;
  }
}


Node* Parser_parseTerm(Parser* parser) {

  if (parser->currentToken < parser->numTokens && parser->tokens[parser->currentToken].tokenCode == TOKEN_LEFT_PAREN) {
    parser->currentToken++;


    Node* node = Pars
}
}
