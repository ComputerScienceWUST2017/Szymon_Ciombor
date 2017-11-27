#ifndef TOKENFUNCTIONS_H_INCLUDED
#define TOKENFUNCTIONS_H_INCLUDED
int isLLetter(char character);
int isULetter(char character);
int isDigit(char character);
int isSign(char character);
int isDigitOrPoint(char character);
int isPunctuation(char character);
void cutPunctuation(char* buffer);
int nextWord(char* buffer, int len);
int nextName(char* buffer, int len);
int nextIntNumber(char* buffer, int len);
int nextFpNumber(char* buffer, int len);
int nextTelNumber(char* buffer, int len);


#endif // TOKENFUNCTIONS_H_INCLUDED
