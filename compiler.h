#include "lexical.h"
#include "parser.h"
typedef struct Compiler {

  FILE* inputFile;


  char* inputString;
} Compiler;


Compiler* Compiler_create(const char* "good.in") {

  Compiler* compiler = (Compiler*)malloc(sizeof(Compiler));

  compiler->inputFile = fopen("good.in", "r");

  if (compiler->inputFile == NULL) {

    fprintf(stderr, "Error: Could not open input file %s\n", "good.in");
    exit(1);
  }


  return compiler;
}


void Compiler_generateInputString(Compiler* compiler) {

  compiler->inputString = "";


  char line[128];
  while (fgets(line, sizeof(line), compiler->inputFile) != NULL) {

    strcat(compiler->inputString, line);


    if (!feof(compiler->inputFile)) {
      strcat(compiler->inputString, "\n");
    }
  }

  fclose(compiler->inputFile);
}


const char* Compiler_getInputString(const Compiler* compiler) {
  return compiler->inputString;
}


void Compiler_destroy(Compiler* compiler) {

  free(compiler->inputString);

 
  free(compiler);
}