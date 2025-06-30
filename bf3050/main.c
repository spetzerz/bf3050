#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"
#include "parser.h"
#include "util.h"

Lexer_t  Lexer	= { 0 };
Parser_t Parser = { 0 };

int main() {
	char* newSource = malloc(INITIAL_SOURCE_CODE_SIZE + 1);
	if (!newSource) {
		MALLOC_ERROR
	}

	printf("Enter BF source code: ");
	gets_s(newSource, INITIAL_SOURCE_CODE_SIZE + 1);

	//strcpy_s(newSource, INITIAL_SOURCE_CODE_SIZE + 1, "");

	LexerSetSource(newSource);

	char* asmFile = calloc(1, INITIAL_SOURCE_CODE_SIZE + 1);
	if (!asmFile) {
		MALLOC_ERROR
	}
	char* immFile = calloc(1, INITIAL_SOURCE_CODE_SIZE + 1);
	if (!immFile) {
		MALLOC_ERROR
	}
	ParserInit(asmFile, immFile);

	if (LexerLex()) {
		printf("LexerLex encountered an error.\n");
		exit(EXIT_FAILURE);
	}

	if (ParserParse()) {
		printf("ParserParse encountered a error. \n");
		exit(EXIT_FAILURE);
	}

	printf("\n"); // because of the lexer printing the chars
	printf("--ASM--\n %s\n --IMM--\n %s", Parser.asmFile, Parser.immFile);

	return 0;
}
