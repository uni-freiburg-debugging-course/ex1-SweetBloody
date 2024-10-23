#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char random_operator(void) {
    char operators[] = {'+', '-', '*', '/'};
    return operators[rand() % 3];
}

int random_integer(void) {
    return (rand() % 2000) - 1000;
}

void generate_random_expression(char* buffer, size_t buffer_size) {
    char op = random_operator();
    int num1 = random_integer();
    int num2 = random_integer();
    snprintf(buffer, buffer_size, "(simplify (%c %d %d))", op, num1, num2);
}

int main(int argc, char **argv) {
    FILE *file = fopen(argv[1], "w");
    if (file == NULL) {
        perror("Error opening");
        return EXIT_FAILURE;
    }

    srand(time(NULL));

    for (int i = 0; i < atoi(argv[2]); ++i) {
        char expression[50];
        generate_random_expression(expression, sizeof(expression));

        fprintf(file, "%s\n", expression);
    }

    fclose(file);

    printf("Success '%s'.\n", argv[1]);

    return 0;
}
