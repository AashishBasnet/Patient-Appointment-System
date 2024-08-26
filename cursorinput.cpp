#include "cursorinput.h"
#include<conio.h>
char* text_input(int x1, int y1, int h, int w, char* initialInput) {
    char input[100]={'\0'}; // Assuming max input length of 100 characters
    strcpy(input, initialInput);
    char ch;
    bool cursoripcondition = true;
    while (cursoripcondition) {
        if (kbhit()) {
            ch = getch();
            setbkcolor(WHITE);

            if (ch == 13) { // Enter key
                textfield(x1, y1, h, w);
                strcpy(initialInput, input); // Copy input back to initialInput
                return initialInput;
            }

            if (ch == 8) { // Backspace key
                int len = strlen(input);
                if (len > 0) {
                    input[len - 1] = '\0';
                }
            } else {
                int len = strlen(input);
                if (len < sizeof(input) - 1) {
                    input[len] = ch;
                    input[len + 1] = '\0';
                }
            }
            setfillstyle(SOLID_FILL, WHITE);
            bar(x1 + 5, y1 + 5, x1 + w - 5, y1 + h - 5);

            setcolor(BLACK);
            settextstyle(4,0,1);
            outtextxy(x1 + 10, y1 + 10, input);
        }

        delay(10);
    }
    return initialInput;
}

char* pwtext_input(int x1, int y1, int h, int w, char* initialInput) {
    char input[100] = {'\0'};  // Assuming max input length of 100 characters
    strcpy(input, initialInput);
    char display[100] = {'\0'};  // Array to store asterisks for display
    char ch;
    bool cursoripcondition = true;
    int len = strlen(input);  // Track the length of input

    // Initialize display based on existing input
    for (int i = 0; i < len; i++) {
        display[i] = '*';
    }
    display[len] = '\0';

    while (cursoripcondition) {
        if (kbhit()) {
            ch = getch();
            setbkcolor(WHITE);

            if (ch == 13) {  // Enter key
                textfield(x1, y1, h, w);
                strcpy(initialInput, input);  // Copy input back to initialInput
                return initialInput;
            }

            if (ch == 8) {  // Backspace key
                if (len > 0) {
                    input[len - 1] = '\0';  // Remove the last character from the input
                    display[len - 1] = '\0';  // Remove the last asterisk
                    len--;  // Decrement length
                }
            } else {
                if (len < sizeof(input) - 1) {
                    input[len] = ch;  // Store the actual character
                    display[len] = '*';  // Store an asterisk for display
                    input[len + 1] = '\0';
                    display[len + 1] = '\0';
                    len++;  // Increment length
                }
            }

            // Clear the entire text display area
            setfillstyle(SOLID_FILL, WHITE);
            bar(x1 + 5, y1 + 5, x1 + w - 5, y1 + h - 5);

            // Draw the updated string of asterisks
            setcolor(BLACK);
            settextstyle(4, 0, 1);
            outtextxy(x1 + 10, y1 + 10, display);  // Display asterisks
        }

        delay(10);
    }
    return initialInput;
}

char*  max_char_text_input(int x1, int y1, int h, int w, char* initialInput, int maxChars) {
    char* input = new char[maxChars + 1]; // Dynamic array to store the input
    strcpy(input, initialInput);
    char ch;
    bool cursoripcondition = true;

    while (cursoripcondition) {
        if (kbhit()) {
            ch = getch();
            setbkcolor(WHITE);

            if (ch == 13) { // Enter key
                textfield(x1, y1, h, w);
                strcpy(initialInput, input); // Copy input back to initialInput
                delete[] input; // Free the dynamically allocated memory
                return initialInput;
            }

            if (ch == 8) { // Backspace key
                int len = strlen(input);
                if (len > 0) {
                    input[len - 1] = '\0';
                }
            } else {
                int len = strlen(input);
                if (len < maxChars) { // Allow input only if it's within the limit
                    input[len] = ch;
                    input[len + 1] = '\0';
                }
            }

            setfillstyle(SOLID_FILL, WHITE);
            bar(x1 + 5, y1 + 5, x1 + w - 5, y1 + h - 5);

            setcolor(BLACK);
            settextstyle(4, 0, 1);
            outtextxy(x1 + 10, y1 + 10, input);
        }

        delay(10);
    }

    delete[] input; // Free the dynamically allocated memory
    return initialInput;
}

