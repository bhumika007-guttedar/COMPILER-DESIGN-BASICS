# COMPILER-DESIGN-BASICS

*COMPANY* : CODTECH IT SOULUTIONS

*NAME* : BHUMIKA

*INERN ID* : CT08K876

*DURATION* : 4 WEEKS

*MENTOR* : NEELA SANTOSH


Basic Lexical Analyzer for C Code
---------------------------------------------------------------------------------
This program (lexer.c) implements a fundamental lexical analyzer, often referred to as a scanner or tokenizer. It represents the first crucial phase of a compiler, whose primary role is to read the raw source code (a stream of characters) and convert it into a sequence of meaningful units called tokens. This process is analogous to breaking down a sentence into words, where each "word" (token) has a specific category and meaning. This simplified analyzer specifically targets C programming language constructs.


Logic:
The program's logic revolves around identifying and categorizing different types of tokens based on predefined rules. It leverages functions from <string.h> for string manipulation and <ctype.h> for character classification.

1. Token Categories and Definitions:

Keywords: C has a set of reserved words that have special meanings (e.g., int, while, if, return). These are explicitly listed in the char keywords[32][10] global array. The array is designed to hold 32 keywords, each up to 9 characters long plus a null terminator.

Operators: Symbols that perform operations on values (e.g., +, -, =, *, <, >). A string char operators[] = "+-*/%=<>&|!"; defines the set of recognized operators.

Identifiers: Names given by the programmer to variables, functions, etc., that are not keywords.

2. Helper Functions:

isKeyword(char *word): This function takes a string word as input. It iterates through the global keywords array, using strcmp() to compare the input word with each known keyword. If a match is found, it returns 1 (true); otherwise, it returns 0 (false) after checking all keywords.

isOperator(char ch): This function takes a single character ch as input. It iterates through the operators string, comparing ch with each character in the string. If a match is found, it returns 1 (true); otherwise, it returns 0 (false).

3. main Function - Tokenization Process:

File Opening: The program starts by attempting to open a file named input.c in read mode ("r") using fopen. An error check (if (file == NULL)) is immediately performed. If the file cannot be opened (e.g., it doesn't exist, or there are permission issues), an error message is printed, and the program exits, preventing further operations on a non-existent file stream.

Character-by-Character Reading: The core of the analysis happens within a while ((ch = fgetc(file)) != EOF) loop. fgetc(file) reads one character at a time from input.c until the End-Of-File (EOF) marker is reached, signifying the end of the file.

Buffer Accumulation for Words:

if (isalnum(ch)): If the character ch is alphanumeric (a letter a-z, A-Z, or a digit 0-9), it's considered part of a potential word (keyword or identifier). This character is appended to the buffer array, and the i index (which tracks the current length of the word in the buffer) is incremented.

else: If the character ch is not alphanumeric, it means the current word (if any) has ended, or ch itself might be a token (like an operator or delimiter).

if (i > 0): This condition checks if there's any content accumulated in the buffer. If i is greater than 0, it means an alphanumeric sequence (a word) was just parsed.

buffer[i] = '\0';: The accumulated word in buffer is null-terminated, turning it into a valid C string.

if (isKeyword(buffer)) ... else ...: The isKeyword function is called to determine if the buffered word is a C keyword. It's then printed as [Keyword] or [Identifier] accordingly.

i = 0;: The buffer index i is reset to 0, clearing it for the next word.

Operator Check: if (isOperator(ch)) checks if the current non-alphanumeric character ch is one of the defined operators. If it is, it's printed as [Operator].

Delimiter Handling: else if (isspace(ch) || ch == ';' || ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ','): This else-if block explicitly handles common C delimiters like whitespace, semicolons, parentheses, and curly braces. For this basic analyzer, these characters are simply acknowledged as separators, allowing the program to continue to the next token. In a more advanced lexer, these might also be classified as specific "Delimiter" tokens.

End of File Cleanup: After the while loop finishes, it's possible that the input file ends with an alphanumeric sequence. The final if (i > 0) block after the loop ensures that any remaining content in the buffer is processed and classified before the program concludes.

File Closing: fclose(file); closes the input file stream, releasing system resources.

This program provides a rudimentary but functional example of how source code is initially processed by a compiler to identify its fundamental building blocks. It highlights the importance of state management (the buffer and i) and character classification in tokenization.

Execution:
To successfully run this lexical analyzer:

1. Save the Analyzer Code: Save the provided C code as lexer.c in a chosen directory (e.g., my_compiler_project).

2. Create Input File: In the exact same directory, create a new text file and name it input.c. This file will contain the C source code that your lexer.c program will analyze.

Example input.c content:

// This is a sample C code file
int main() {
    int x = 10;
    if (x > 5) {
        return 0;
    }
}


Expected Output (for the sample input.c above):
------------------------------------------------------------------------
Lexical Analysis Output:

[Operator]   -> /
[Operator]   -> /
[Identifier] -> This
[Identifier] -> is
[Identifier] -> a
[Identifier] -> sample
[Identifier] -> C
[Identifier] -> code
[Identifier] -> file
[Keyword]    -> int
[Identifier] -> main
[Keyword]    -> int
[Identifier] -> x
[Operator]   -> =
[Identifier] -> 10
[Keyword]    -> if
[Identifier] -> x
[Operator]   -> >
[Identifier] -> 5
[Keyword]    -> return
[Identifier] -> 0

OUTPUT
---------------------------------------------------------
<img width="1918" height="1077" alt="Image" src="https://github.com/user-attachments/assets/e84c4517-cfa3-4e64-a4a4-470e3fabc9b5" />
