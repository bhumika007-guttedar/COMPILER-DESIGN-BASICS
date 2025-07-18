#include <stdio.h>
#include <string.h>
#include <ctype.h> // Required for isalnum()

char keywords[32][10] = {
    "auto","break","case","char","const","continue","default","do","double","else",
    "enum","extern","float","for","goto","if","int","long","register","return",
    "short","signed","sizeof","static","struct","switch","typedef","union",
    "unsigned","void","volatile","while"
};

int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(keywords[i], word) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/%=<>&|!";
    for (int i = 0; i<strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *file;
    char filename[] = "input.c";
    char ch, buffer[100];
    int i = 0;

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        return 1;
    }

    printf("Lexical Analysis Output:\n\n");

    while ((ch = fgetc(file)) != EOF) {
        if (isalnum(ch)) { // If character is alphanumeric (letter or digit)
            buffer[i++] = ch;
        } else { // If character is not alphanumeric
            // If there's content in the buffer, it means we've finished reading a word/identifier/keyword
            if (i > 0) {
                buffer[i] = '\0'; // Null-terminate the string in the buffer
                if (isKeyword(buffer))
                    printf("[Keyword]    -> %s\n", buffer);
                else
                    printf("[Identifier] -> %s\n", buffer);
                i = 0; // Reset buffer index for the next word
            }

            // Check if the current non-alphanumeric character is an operator
            if (isOperator(ch)) {
                printf("[Operator]   -> %c\n", ch);
            }
            // Add an else-if for handling other delimiters (like spaces, newlines, semicolons, parentheses etc.)
            // For this basic lexical analyzer, we'll simply acknowledge and skip them if they're not operators.
            else if (isspace(ch) || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ',') {
                // You could optionally print these as "Delimiter" tokens if needed for more detailed analysis
                // printf("[Delimiter]  -> %c\n", ch);
            }
            // For characters that are neither alphanumeric, operators, nor common delimiters, you might want to
            // add more specific handling or categorize them as "Unknown Token" for robustness.
        }
    }

    // After the loop, if there's any content left in the buffer (e.g., file ends with a word)
    if (i > 0) {
        buffer[i] = '\0';
        if (isKeyword(buffer))
            printf("[Keyword]    -> %s\n", buffer);
        else
            printf("[Identifier] -> %s\n", buffer);
    }

    fclose(file);
    return 0;
}