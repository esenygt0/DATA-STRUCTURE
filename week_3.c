/* * BAŞLIK: Shunting Yard - Infix'ten Postfix'e Çevrim
 * AÇIKLAMA: Operatör önceliklerini dikkate alarak matematiksel ifadeleri 
 * yığın (stack) yapısı ile postfix formatına dönüştürür.
 */
#include <stdio.h>
#include <ctype.h>

int priority(char c) {
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void convert(char* exp) {
    char stack[100]; int top = -1;
    for(int i=0; exp[i]; i++) {
        if(isalnum(exp[i])) printf("%c", exp[i]);
        else if(exp[i] == '(') stack[++top] = '(';
        else if(exp[i] == ')') {
            while(top != -1 && stack[top] != '(') printf("%c", stack[top--]);
            top--;
        } else {
            while(top != -1 && priority(exp[i]) <= priority(stack[top])) printf("%c", stack[top--]);
            stack[++top] = exp[i];
        }
    }
    while(top != -1) printf("%c", stack[top--]);
}