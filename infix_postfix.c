#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1, k = 0;
    char ch;
    int i;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];

        // Check if operand (A-Z, a-z, 0-9)
        if ((ch >= 'a' && ch <= 'z') || 
            (ch >= 'A' && ch <= 'Z') || 
            (ch >= '0' && ch <= '9')) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            stack[++top] = ch;
        }
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // remove '('
        }
        else { // Operator
            int prec;
            if (ch == '^') prec = 3;
            else if (ch == '*' || ch == '/') prec = 2;
            else if (ch == '+' || ch == '-') prec = 1;
            else prec = 0;

            while (top != -1) {
                int topPrec;
                if (stack[top] == '^') topPrec = 3;
                else if (stack[top] == '*' || stack[top] == '/') topPrec = 2;
                else if (stack[top] == '+' || stack[top] == '-') topPrec = 1;
                else topPrec = 0;

                if (topPrec >= prec) {
                    postfix[k++] = stack[top--];
                } else {
                    break;
                }
            }
            stack[++top] = ch;
        }
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}

