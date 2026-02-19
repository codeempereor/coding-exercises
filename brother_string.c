#include <stdio.h>
#include <string.h>

int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};

unsigned long long calculate_product(const char *str) {
    unsigned long long product = 1;
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            product *= primes[c - 'a'];
        } else if (c >= 'A' && c <= 'Z') {
            product *= primes[c - 'A'];
        }
    }
    return product;
}

int are_brother_strings(const char *str1, const char *str2) {
    if (strlen(str1) != strlen(str2)) {
        return 0;
    }
    if (strcmp(str1, str2) == 0) {
        return 0;
    }
    return calculate_product(str1) == calculate_product(str2);
}

int main() {
    char str1[100], str2[100];
    printf("Please enter first string: ");
    scanf("%s", str1);
    printf("Please enter second string: ");
    scanf("%s", str2);
    if (are_brother_strings(str1, str2)) {
        printf("\"%s\" and \"%s\" are brother strings\n", str1, str2);
    } else {
        printf("\"%s\" and \"%s\" are not brother strings\n", str1, str2);
    }
    return 0;
}
