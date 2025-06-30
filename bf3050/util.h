#pragma once
#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INITIAL_SOURCE_CODE_SIZE 1048576

#define MALLOC_ERROR printf("Failed to allocate memory\n"); exit(EXIT_FAILURE);
#define REALLOC_ERROR printf("Failed to reallocate memory\n"); exit(EXIT_FAILURE);

int getCurrentLine(char* str);
char* encode_packed_imms(unsigned int first_imm, unsigned int second_imm, bool subtractOneFromFirstImm);
