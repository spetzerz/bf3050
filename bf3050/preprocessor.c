#include <string.h>
#include "preprocessor.h"
#include "parser.h"
#include "util.h"

extern Parser_t Parser;

void preprocess(char* src) {
	char* Context = NULL;
	char* replacement = strstr(src, "#") + 1;

}
