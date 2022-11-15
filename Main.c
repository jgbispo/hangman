// Hangman Game
// Created by: João Gustavo Soares Bispo
// Created on: 2022-11-15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

int drawHangman(int, char *);

int getWord(char[]);

int drawWord(char *, char *);

int drawLetters(char *, int);

int main(void) {
    char word[MAX], guess[MAX], letter;

    if (getWord(word) == 1) {
        return 1;
    } else {
        drawHangman(0, word);
        drawWord(word, guess);
    }

    return 0;
}

int getWord(char word[]) {
    FILE *file;
    int i = 0, j = 0, k = 0, n = 0;
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
    n = rand() % i;
    strcpy(word, words[n]);

    fclose(file);
    return 0;
}

int drawWord(char *word, char *guess) {
    int i, matches = 0, len = strlen(word);
    char letter;
    for (i = 1; i < len; i++) {
        if (word[i] == guess[i]) {
            printf("%c ", word[i]);
            matches++;
        } else {
            printf("_ ");
        }
    }
    if (matches == len) {
        return 0;
    }
    printf("\nGuess a letter: ");
    scanf(" %c", &letter);
    for (i = 0; i < len; i++) {
        if (word[i] == letter) {
            guess[i] = letter;
        }
    }
    return 0;
}

int drawHangman(int wrongGuesses, char *word) {
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
            printf("|       |\\n");
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
            printf("You lose! The word was %s", word);
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
            printf("You lose! The word was %s", word);
            break;
        default:
            printf("Invalid number of wrong guesses");
            break;
    }
    return 0;
}
