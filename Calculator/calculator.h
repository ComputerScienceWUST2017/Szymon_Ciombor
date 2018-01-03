#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED


typedef enum
{
    EQUALS,ADD,SUBTRACT,NUMBER,WORD,PREV,MULTIPLY,DIVIDE
} TokenType;
int nextIntNumber(char* tk, int len);
int nextFpNumber(char* tk, int len);
int isAddition(char tk[], int len);
int isEquation(char tk[], int len);
int isSubtraction(char tk[], int len);
int isPrev(char tk[], int len);
int isMultiplication(char tk[], int len);
int isDivision(char tk[], int len);
TokenType getNextToken(char tk[], int len);
char* lineCalc(char* line, int len);


#endif // CALCULATOR_H_INCLUDED
