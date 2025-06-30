#include <stdbool.h>
#include "util.h"

int getCurrentLine(char* str) {
	int numLines = 0;
	while (str != '\0') {
		str++;
		if (str == '\n')
			numLines++;
	}

	return numLines;
}

char* encode_packed_imms(unsigned int first_imm, unsigned int second_imm, bool subtractOneFromFirstImm) {
    if (first_imm > 0xFFFF || second_imm > 0xFFFF) {
        return NULL;
    }

    if (subtractOneFromFirstImm && first_imm != 0)
        first_imm--;

    unsigned int A = (first_imm >> 8) & 0xFF;
    unsigned int B = first_imm & 0xFF;
    unsigned int C = (second_imm >> 8) & 0xFF;
    unsigned int D = second_imm & 0xFF;

    char* result = malloc(32);
    if (!result) 
        return NULL;

    sprintf_s(result, 32, "%u %u %u %u", A, B, C, D);

    return result;
}

void 