// Hangman Game
// Created by: João Gustavo Soares Bispo
// Created on: 2022-11-15
// IDE: CLion
// Version: 1.0
// Repository: https://github.com/jgbispo/hangman

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

#define MAX 100

int drawHangman(int);

int getWord(char[]);

int drawWord(char *, char *, int);

int main(void) {
    char word[MAX], guess[MAX];
    int attempt = 0;
    getWord(word);
    do {
        drawHangman(attempt);
        attempt = drawWord(word, guess, attempt);

    } while (attempt < 6);
    printf("Game Over. The word was \"%s\"", word);
}

int drawWord(char *word, char *guess, int attempt) {
    int i, matches = 0, len = strlen(word) - 1;
    char letter;
    bool found = false;
    for (i = 0; i < len; i++) {
        if (word[i] == guess[i]) {
            printf("%c ", word[i]);
            matches++;
        } else {
            printf("_ ");
        }
    }

    if (matches == len) {
        printf("You Win");
        return 6;
    }

    printf("\nGuess a letter: ");
    scanf(" %c", &letter);
    for (i = 0; i < len; i++) {
        if (word[i] == letter) {
            guess[i] = letter;
            found = true;
        }
    }

    if (!found) {
        attempt += 1;
        return attempt;
    } else {
        return attempt;
    }
}

int drawHangman(int wrongGuesses) {
    switch (wrongGuesses) {
        case 0:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;

        case 1:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|       |\\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 3:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      /\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 5:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 6:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      ---\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        default:
            printf("Invalid number of wrong guesses");
            break;
    }
    return 0;
}

int getWord(char word[]) {
    FILE *file;
    int i = 0;
    char line[MAX], words[MAX][MAX];

    file = fopen("../words.txt", "r");

    if (file == NULL) {
        printf("Error opening file words.txt");
        return 1;
    }

    while (fgets(line, MAX, file) != NULL) {
        strcpy(words[i], line);
        i++;
    }

    srand(time(NULL));
    int n = rand() % i;
    strcpy(word, words[n]);

    fclose(file);
    return 0;
}
