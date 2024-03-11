#include <stdio.h>
#include <stdlib.h>

// Structure to represent a three-address code
typedef struct {
    char op;      // Operator (+, -, *, /)
    char arg1[10]; // Operand 1
    char arg2[10]; // Operand 2
    char result[10]; // Result
} ThreeAddressCode;

// Function to generate three-address code for a simple arithmetic expression
ThreeAddressCode* generateCode(char op, const char* arg1, const char* arg2, const char* result) {
    ThreeAddressCode* code = (ThreeAddressCode*)malloc(sizeof(ThreeAddressCode));
    code->op = op;
    snprintf(code->arg1, sizeof(code->arg1), "%s", arg1);
    snprintf(code->arg2, sizeof(code->arg2), "%s", arg2);
    snprintf(code->result, sizeof(code->result), "%s", result);
    return code;
}

int main() {
    // Example: Generating code for the expression: a = y + z + 20

    // Generate three-address code
    ThreeAddressCode* code1 = generateCode('+', "y", "z", "t1");
    ThreeAddressCode* code2 = generateCode('+', "t1", "20", "a");

    // Print generated code
    printf("Generated Three-Address Code:\n");
    printf("%s = %s %c %s\n", code1->result, code1->arg1, code1->op, code1->arg2);
    printf("%s = %s %c %s\n", code2->result, code2->arg1, code2->op, code2->arg2);

    // Free allocated memory
    free(code1);
    free(code2);

    return 0;
}
