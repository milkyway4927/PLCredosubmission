#include "syntax.h"

int main(void) 
{
   if ((in_fp = fopen("good.in", "r")) == NULL)
	 	printf("ERROR \n");
	 else {
	 	getChar();
	  //lex();
   // statement();
	 	begin();
	 }
	//  return 0;

  return 0;
} 