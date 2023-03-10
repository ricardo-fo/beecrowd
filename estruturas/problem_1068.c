# include <stdio.h>
# include <string.h>

int main () {
    int stack = 0;
    char str[1000];

    while(scanf("%s", str) != EOF) {
        for (int i = 0; i < strlen(str); i++) {
            if (str[i] != '\n' && str[i] != '(' && str[i] != ')') continue;

            if ((stack += str[i] == '(' ? 1 : -1) < 0) break;
        }

        printf("%s\n", stack == 0 ? "correct" : "incorrect");
        stack = 0;
    }

    return 0;
}