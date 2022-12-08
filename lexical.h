#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int chClass;
char lexeme[100];
char nextChar;  //The next char
int lexLength;  //Length of Lex
int currToken;  //Current Token
int nextToken;  //Next Token
FILE *in_fp;
char nextkey;
int searcher(char ch); //
void addChar(void); //
void getChar(void); //
void nonBlank(void); //
int lex(void);  //
void error49(void); //

#define LETTER 0
#define DIGITS 1

#define RANDRAND 10
#define Starts 11
#define Finish 12

#define INTEGE 20
#define IDENTI 21
#define ASSIGN 22

#define ADDITION 30
#define SUBTRACT 31
#define MULTIPLY 32
#define DIVIDE 33
#define MODULUS 34

#define LPARPAR 40
#define RPARPAR 41
#define LBRACK 42
#define RBRACK 43

#define COMMAS 50
#define SEMICOL 51
#define PERIOD 52

#define LESSER 60
#define GREATER 61
#define LESSEQ 62
#define GREATEQ 63
#define EQUALS 64
#define NOTEQUAL 65

#define IF_STMT 70
#define LOOPER 71
#define NUMERS 72

int searcher(char ch) {
  switch (ch) {
    case '(':
		  addChar();
      nextToken = LPARPAR;
      break;
    case ')':
      addChar();
      nextToken = RPARPAR;
      break;
    case '+':
      addChar();
      nextToken = ADDITION;
      break;
    case '-':
			 addChar();
			 nextToken = SUBTRACT;
			 break;
		case '*':
			 addChar();
			 nextToken = MULTIPLY;
			 break;
		case '/':
			 addChar();
			 nextToken = DIVIDE;
			 break;
		case '=':
			 addChar();
			 nextToken = ASSIGN;
			 break;
		case '%':
			 addChar();
			 nextToken = MODULUS;
			 break;
		case ';':
			 addChar();
			 nextToken = SEMICOL;
			 break;
		case ',':
			 addChar();
			 nextToken = COMMAS;
			 break;
		case '{':
			 addChar();
			 nextToken = LBRACK;
			 break;
		case '}':
			 addChar();
			 nextToken = RBRACK;
			 break;
		case '.':
			 addChar();
			 nextToken = PERIOD;
			 break;
		case '<':
			 addChar();
			 nextToken = LESSER;
			 break;
		case '>':
			 addChar();
			 nextToken = GREATER;
			 break;
    case '^':
       addChar();
			 nextToken = Starts;
			 break;
    case '$':
      addChar();
      nextToken = Finish;
      break;
    case '#':
      addChar();
      nextToken = NUMERS;
      break;
    case '!':
      addChar();
      nextToken = NOTEQUAL;
      break;
		 default:
			 addChar();
			 nextToken = EOF;
			 break;
	 }
	 return nextToken;
}

void addChar(void) 
{
	if (lexLength < 73 && lexLength != 10) 
  {
		lexeme[lexLength++] = nextChar;
		lexeme[lexLength] = '\0';
	} 
  else
  {
    printf("Error: lexeme is too long \n");  
  }
}

void getChar(void) 
{
	 if ((nextChar = getc(in_fp)) != EOF) 
   {
		 if (isalpha(nextChar))
     {
      chClass = LETTER;  
     } 
		 else if (isdigit(nextChar)) 
     {
      chClass = DIGITS;  
     }
      
		 else 
     {
      chClass = RANDRAND;  
     }
	 } 
   else
   {
     chClass = EOF;  
   } 	
}

void nonBlank(void) {
	while (isspace(nextChar))
	getChar();
}

void error49(void){
	 printf("ERROR STOP");
   exit(0);
}

int x;
int lex(void) {
	 lexLength = 0;
	 nonBlank();
   int x;
   int y;
	 switch (chClass) {
		 case LETTER:
       y=1;
			 addChar();
			 getChar();
			 while (chClass == LETTER) {
         y++;
				 addChar();
				 getChar();
			 } 
      if(y<=8 && y>=6 && lexeme[0]!='l' && lexeme[0] !='c' && lexeme[0] != 'n' ){
			 nextToken = IDENTI;
      }
      else if(lexeme[0]=='l'&&lexeme[1]=='o'&&lexeme[2]=='o'&&lexeme[3]=='p') {
        nextToken=LOOPER;
      }
       
      else if(lexeme[0]=='c'&&lexeme[1]=='o'&&lexeme[2]=='n' ) {
        nextToken=IF_STMT;
      }
      else if((lexeme[1]!='o'||lexeme[2]!='o'||lexeme[3]!='p') && y>=6 && y<=8){
        nextToken= IDENTI;
        }
       
     else{
       error49();
     }
     break;
	
		 case DIGITS:
			 addChar();
			 getChar();
			 while (chClass == DIGITS) {
				 addChar();
				 getChar();
			 }
       if( nextChar == 'v' || nextChar == 'r' || nextChar == 'e' ){
			  	 addChar();
				   getChar();
        }
       if( nextChar != '.'){
			 nextToken = INTEGE;
       } else {
         error49();
		  	 while (chClass == DIGITS) {
			  	 addChar();
				   getChar();
           }
        if( nextChar == 'v' || nextChar == 'r' || nextChar == 'e' ){
			  	 addChar();
				   getChar();
        }
           
			  //nextToken = FLOAT_LIT;
       }
		 	break;
		/* Parentheses and operators */
    /*  ^[a-zA-Z0-9]  is the regular expression for an special charater */
		 case RANDRAND:
       if( nextChar == '.'){
  			 addChar();
	  		 getChar();
         if(chClass == DIGITS ){
		  	    while (chClass == DIGITS) {
			  	    addChar();
				      getChar();
			      }
            if( nextChar == 'd' || nextChar == 'f' ){
			  	    addChar();
				      getChar();
            }
			    //  nextToken = FLOAT_LIT;
          }
          nextToken = PERIOD;
       } else {
			  searcher(nextChar);
			  getChar();
        if ( nextToken == LESSER && nextChar == '=' ) {
          addChar();
          getChar();
          nextToken = LESSEQ;
        } else if ( nextToken == GREATER && nextChar == '=' ) {
          addChar();
          getChar();
          nextToken = GREATEQ;
        }else if ( nextToken == ASSIGN && nextChar == '=' ) {
          addChar();
          getChar();
          nextToken = EQUALS;
          }
         
       }
			 break;
			/* EOF */
		case EOF:
			 nextToken = EOF;
			 lexeme[0] = 'E';
			 lexeme[1] = 'O';
			 lexeme[2] = 'F';
			 lexeme[3] = '\0';
		 	break;
    case Starts:
      nextToken= Starts;
     
	 } /* End of switch */
  switch(nextToken){
    case 11: //print out token name
    printf("Next token is: Starts, Next lexeme is %s\n", lexeme);
    break;
    case 12:
    printf("Next token is: Finish, Next lexeme is %s\n", lexeme);
    break;
    
    case 20:
    printf("Next token is: INTEGE, Next lexeme is %s\n", lexeme);
    break;
    
    case 21:
    printf("Next token is: IDENTI, Next lexeme is %s\n", lexeme);
    break;
     
    case 22:
    printf("Next token is: ASSIGN, Next lexeme is %s\n", lexeme);
    break;
    
     case 30:
    printf("Next token is: ADDITION, Next lexeme is %s\n", lexeme);
    break;
    
     case 31:
    printf("Next token is: SUBTRACT, Next lexeme is %s\n", lexeme);
    break;
    
     case 32:
    printf("Next token is: MULTIPLY, Next lexeme is %s\n", lexeme);
    break;
    
     case 33:
    printf("Next token is: DIVIDE, Next lexeme is %s\n", lexeme);
    break;
    
     case 34:
    printf("Next token is: MODULUS, Next lexeme is %s\n", lexeme);
    break;
    
     case 40:
    printf("Next token is: LPARPAR, Next lexeme is %s\n", lexeme);
    break;
    
      case 41:
    printf("Next token is: RPARPAR, Next lexeme is %s\n", lexeme);
    break;
    
      case 42:
    printf("Next token is: LBRACK, Next lexeme is %s\n", lexeme);
    break;
    
      case 43:
    printf("Next token is: RBRACK, Next lexeme is %s\n", lexeme);
    break;
    
      case 51:
    printf("Next token is: SEMICOL, Next lexeme is %s\n", lexeme);
    break;
    
      case 60:
    printf("Next token is: LESSER, Next lexeme is %s\n", lexeme);
    break;
    
      case 61:
    printf("Next token is: GREATER, Next lexeme is %s\n", lexeme);
    break;
    
      case 62:
    printf("Next token is: LESSEQ, Next lexeme is %s\n", lexeme);
    break;
    
      case 63:
    printf("Next token is: GREATEQ, Next lexeme is %s\n", lexeme);
    break;
      
    case 64:
    printf("Next token is: EQUALS, Next lexeme is %s\n", lexeme);
    break;

      case 65:
    printf("Next token is: NOTEQUALS, Next lexeme is %s\n", lexeme);
    break;
    
      case 70:
    printf("Next token is: IF_STMT, Next lexeme is %s\n", lexeme);
    break;
    
      case 71:
    printf("Next token is: LOOPER, Next lexeme is %s\n", lexeme);
    break;

      case 72:
    printf("Next token is: NUMERS, Next lexeme is %s\n", lexeme);
    break;
    
    
  }
//	 printf("Next token is: %d, Next lexeme is %s\n",
//	 nextToken, lexeme);
	 return nextToken;
} /* End of function lex */