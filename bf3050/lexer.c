#include <string.h>
#include <stdbool.h>
#include "lexer.h"
#include "parser.h"

static bool isAToken(const char* ch);

extern Lexer_t Lexer;
extern Parser_t Parser;

/**
 * Top-level function
 * 
 * \return
 * 0 - success
 * 1 - failure
 */
int LexerLex() {
	while (LexerConsumeToken());

	return 0;
}

/**
 * Set the lexer's new source code
 * 
 * \param newSource New source code to be set too.
 */
void LexerSetSource(const char* newSource) {
	Lexer.Source = newSource;
	Lexer.sourceLength = strlen(Lexer.Source);
	Lexer.currentToken = Lexer.Source;

	//Lexer.Source[Lexer.sourceLength + 1] = '\0'; // Safety
}

/**
 * Consume the next token in the source code
 * 
 * \return
 * 0 - Reached end of file
 * 1 - Continue
 */
int LexerConsumeToken() {
	static char* nextToken = NULL;
	if (nextToken == NULL) {
		nextToken = Lexer.currentToken;
	} // like static char* nextToken = Lexer.Source;

	while (!isAToken(*nextToken)) {
		if (*nextToken == '\0') {
			ParserPush('\0');
			return 0;
		}

		Lexer.currentToken = ++nextToken;
		return 1;
	}
	
	ParserPush(*Lexer.currentToken++);
	nextToken = Lexer.currentToken;

	return 1;
}

// Consume the next token in the source code

/**
 * Checks if ch is a BF token
 * 
 * \param ch The char to scan for whether its a BF token.
 * \return True or false depending on if its a BF token.
 */
static bool isAToken(const char ch) {
	return
		ch == '<' ||
		ch == '>' ||
		ch == '+' ||
		ch == '-' ||
		ch == '[' ||
		ch == ']' ||
		ch == ',' ||
		ch == '.'
	;
}
