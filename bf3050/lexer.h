#pragma once

typedef struct {
	const char* Source;
	int sourceLength;
	char* currentToken;	// todo: remove this
} Lexer_t;

int LexerLex();
void LexerSetSource(const char* Source);
int LexerConsumeToken();

