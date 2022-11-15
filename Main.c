// Hangman Game
// Created by: João Gustavo Soares Bispo
// Created on: 2022-11-15

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 100

int drawHangman(int);

int drawWord(char *, char *, int);

int main(void) {
    char word[MAX], guess[MAX], letter;


    return 0;
}

int drawWord(char *word, char *guess, int tries) {
    printf("%s", word);
    int i, matches = 0, len = strlen(word);
    char letter;
    for (i = 0; i < len; i++) {
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
    printf(" Tries: %d ", tries);
    printf(" Guess a letter: ");
    scanf(" %c", &letter);
    for (i = 0; i < len; i++) {
        if (word[i] == letter) {
            guess[i] = letter;
        }
    }
    return 1;
}


int drawHangman(int wrongGuesses) {
    switch (wrongGuesses) {
        case 0:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 1:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|       |\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 2:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 3:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      /\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            break;
        case 4:
            printf("|-------|\n");
            printf("|       |\n");
            printf("|       O\n");
            printf("|      /|\\\n");
            printf("|      / \\\n");
            printf("|\n");
            printf("|\n");
            printf("|\n");
            printf("You lose! The word was %s", "nenhuma");
            break;
        default:
            printf("Invalid number of wrong guesses");
            break;
    }
    return 0;
}
