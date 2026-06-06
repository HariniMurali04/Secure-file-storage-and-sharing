#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate random number in a range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to give feedback on how close the guess is
void giveHint(int guess, int number) {
    if (abs(guess - number) <= 5 && guess != number)
        cout << "You're very close!" << endl;
}

// Main game function
void playGuessingGame() {
    const int MIN = 1;
    const int MAX = 100;
    int secretNumber = generateRandomNumber(MIN, MAX);
    int guess;
    int attempts = 0;

    cout << "===== Welcome to the Unique Guessing Game! =====" << endl;
    cout << "I have picked a number between " << MIN << " and " << MAX << "." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try guessing lower." << endl;
            giveHint(guess, secretNumber);
        } else if (guess < secretNumber) {
            cout << "Too low! Try guessing higher." << endl;
            giveHint(guess, secretNumber);
        } else {
            cout << "🎉 Congratulations! You guessed the number in " << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);
}

int main() {
    // Seed random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Start the game
    playGuessingGame();

    return 0;
}
