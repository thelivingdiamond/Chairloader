#pragma once

void RemoveCR(char* pbuf);
void SkipCharacters(char** buf, const char* toSkip);
void SkipComments(char** buf, bool bSkipWhiteSpace);
bool fxIsFirstPass(char* buf);
int fxFillCR(char** buf, char* dst);
char* fxFillPr(char** buf, char* dst);
bool SkipChar(unsigned int ch);
int shFill(char** buf, char* dst, int nSize = -1);
