#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// ---------- Number Guessing Game ----------
void guessingGame() {
    int level, maxNum, attempts, secret, guess, i;
    int won = 0;

    cout << "\n--- NUMBER GUESSING GAME ---\n";
    cout << "1. Easy   (1-50,  10 attempts)\n";
    cout << "2. Medium (1-100,  7 attempts)\n";
    cout << "3. Hard   (1-500,  9 attempts)\n";
    cout << "Choose difficulty: ";
    cin >> level;

    if (level == 1) {
        maxNum = 50;
        attempts = 10;
    }
    else if (level == 3) {
        maxNum = 500;
        attempts = 9;
    }
    else {
        maxNum = 100;
        attempts = 7;
    }

    secret = rand() % maxNum + 1;      // random number from 1 to maxNum
    cout << "I am thinking of a number between 1 and " << maxNum << ".\n";

    for (i = 1; i <= attempts; i++) {
        cout << "Attempt " << i << "/" << attempts << " - Your guess: ";
        cin >> guess;

        if (guess == secret) {
            won = 1;
            break;
        }
        else if (guess < secret) {
            cout << "Too low!\n";
        }
        else {
            cout << "Too high!\n";
        }
    }

    if (won == 1) {
        cout << "Correct! You won in " << i << " attempt(s). Score: "
             << (attempts - i + 1) * 10 << "\n";
    }
    else {
        cout << "Out of attempts! The number was " << secret << ".\n";
    }
}

// ---------- Quiz ----------
void quiz() {
    int answer;
    int score = 0;

    cout << "\n--- C++ QUIZ ---\n";

    cout << "\nQ1. Which language is C++ an extension of?\n";
    cout << "1) Java  2) C  3) Python  4) Pascal\n";
    cout << "Your answer (1-4): ";
    cin >> answer;
    if (answer == 2) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong! Correct answer: 2\n";
    }

    cout << "\nQ2. Which header file is needed for cin and cout?\n";
    cout << "1) <stdio.h>  2) <iostream>  3) <string>  4) <cmath>\n";
    cout << "Your answer (1-4): ";
    cin >> answer;
    if (answer == 2) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong! Correct answer: 2\n";
    }

    cout << "\nQ3. Which symbol ends a statement in C++?\n";
    cout << "1) .  2) :  3) ;  4) ,\n";
    cout << "Your answer (1-4): ";
    cin >> answer;
    if (answer == 3) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong! Correct answer: 3\n";
    }

    cout << "\nQ4. Which loop always runs at least once?\n";
    cout << "1) for  2) while  3) do-while  4) if\n";
    cout << "Your answer (1-4): ";
    cin >> answer;
    if (answer == 3) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong! Correct answer: 3\n";
    }

    cout << "\nQ5. Which data type stores whole numbers?\n";
    cout << "1) float  2) char  3) double  4) int\n";
    cout << "Your answer (1-4): ";
    cin >> answer;
    if (answer == 4) {
        cout << "Correct!\n";
        score++;
    }
    else {
        cout << "Wrong! Correct answer: 4\n";
    }

    cout << "\nFinal score: " << score << "/5\n";
}

// ---------- Main menu ----------
int main() {
    int choice;
    srand(time(0));                    // new random numbers every run

    do {
        cout << "\n=========== GAME MENU ===========\n";
        cout << "1. Number Guessing Game\n";
        cout << "2. Quiz\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                guessingGame();
                break;
            case 2:
                quiz();
                break;
            case 3:
                cout << "Thanks for playing!\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);

    return 0;
}
