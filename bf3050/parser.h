#pragma once
#include <stdlib.h>

typedef struct Token_s {
	char Token;
	struct Token_s* next;
} Token_t;

typedef struct {
	Token_t* Tokens;
	int tokensSize;
	int tokensSizeBytes;
	char* asmFile;
	char* immFile;
} Parser_t;

int ParserParse();
void ParserInit(char* asmFile, char* immFile);
void ParserPush(char token);
