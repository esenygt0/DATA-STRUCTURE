/* 
 * BAŞLIK: Shunting Yard Algoritması - Infix'ten Postfix'e Dönüşüm
 * AÇIKLAMA: Bu program, operatör önceliklerini ve parantezleri dikkate alarak
 * infix (ara gösterim) matematiksel ifadeyi, yığın (stack) veri yapısını
 * kullanarak postfix (son gösterim) formuna dönüştürür.
 */

#include <stdio.h>
#include <ctype.h>

/* 
 * FONKSİYON: priority
 * AÇIKLAMA: Operatörlerin öncelik seviyesini belirler.
 * '*' ve '/' operatörleri '+' ve '-' operatörlerinden daha yüksek önceliğe sahiptir.
 */
int priority(char c) {
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return 0;
}

/* 
 * FONKSİYON: convert
 * AÇIKLAMA: Verilen infix ifadeyi postfix ifadeye dönüştürür.
 * Stack yapısı kullanılarak operatörler ve parantezler kontrol edilir.
 */
void convert(char *exp) {
    char stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {

        // Operand (harf veya rakam)
        if (isalnum(exp[i])) {
            printf("%c", exp[i]);
        }

        // Açık parantez
        else if (exp[i] == '(') {
            stack[++top] = '(';
        }

        // Kapalı parantez
        else if (exp[i] == ')') {
            while (top != -1 && stack[top] != '(') {
                printf("%c", stack[top--]);
            }
            if (top != -1) {
                top--; // '(' karakterini stack'ten sil
            }
        }

        // Operatör
        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(exp[i]) <= priority(stack[top])) {
                printf("%c", stack[top--]);
            }
            stack[++top] = exp[i];
        }
    }

    // Stack'te kalan operatörleri postfix ifadeye ekle
    while (top != -1) {
        printf("%c", stack[top--]);
    }

    printf("\n");
}

/* 
 * FONKSİYON: main
 * AÇIKLAMA: Programın başlangıç noktasıdır.
 * Örnek bir infix ifade alarak postfix dönüşümünü gerçekleştirir.
 */
int main() {
    char exp[] = "A+(B*C-D)/E";
    convert(exp);
    return 0;
}
