#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Token types
enum TokenType {
    KEYWORD,
    IDENTIFIER,
    CONSTANT,
    LITERAL,
    OPERATOR,
    INVALID
};

// Function to check if a string is a keyword
int isKeyword(char *str) {
    char keywords[][10] = {"if", "else", "while", "int", "float", "return"};
    for (int i = 0; i < 6; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;  // It is a keyword
        }
    }
    return 0;  // Not a keyword
}

// Function to categorize and print the token
void printToken(char *value, enum TokenType type) {
    const char *typeNames[] = {"KEYWORD", "IDENTIFIER", "CONSTANT", "LITERAL", "OPERATOR", "INVALID"};
    printf("<%s, %s>\n", value, typeNames[type]);
}

// Function to perform lexical analysis
void lexicalAnalyzer(FILE *file) {
    int c;
    char buffer[20];
    int bufferIndex = 0;

    while ((c = fgetc(file)) != EOF) {
        // Skip whitespaces
        if (isspace(c)) {
            continue;
        }

        // Check for identifiers or keywords
        if (isalpha(c) || c == '_') {
            bufferIndex = 0;
            do {
                buffer[bufferIndex++] = c;
                c = fgetc(file);
            } while (isalnum(c) || c == '_');
            buffer[bufferIndex] = '\0';
            fseek(file, -1, SEEK_CUR);

            if (isKeyword(buffer)) {
                printToken(buffer, KEYWORD);
            } else {
                printToken(buffer, IDENTIFIER);
            }
        }

        // Check for constants
        else if (isdigit(c)) {
            bufferIndex = 0;
            do {
                buffer[bufferIndex++] = c;
                c = fgetc(file);
            } while (isdigit(c));
            buffer[bufferIndex] = '\0';
            fseek(file, -1, SEEK_CUR);
            printToken(buffer, CONSTANT);
        }

        // Check for string literals
        else if (c == '\"') {
            bufferIndex = 0;
            do {
                buffer[bufferIndex++] = c;
                c = fgetc(file);
            } while (c != '\"' && c != EOF);
            buffer[bufferIndex++] = c;
            buffer[bufferIndex ] = '\0';
            printToken(buffer, LITERAL);
        }

        // Check for operators
        else if (strchr("+-*/=<>(){}", c) != NULL) {
            buffer[0] = c;
            buffer[1] = '\0';
            printToken(buffer, OPERATOR);
        }

        // Invalid character
        else {
            buffer[0] = c;
            buffer[1] = '\0';
            printToken(buffer, INVALID);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    printf("\nTokens:\n");
    lexicalAnalyzer(file);

    fclose(file);
    return EXIT_SUCCESS;
}
