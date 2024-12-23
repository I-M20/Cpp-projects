//below is a program for guessing a random number between 1 to 100
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Guesser {
protected:
    int numtoguess;

public:
    int number;
    int chosendiff;
    int attempts;
    int attemptsdone;
    Guesser():attemptsdone(0) {
    srand(time(0));{
        numtoguess=rand() %100 + 1;
    }
}

    int getNumToGuess() const { 
        return numtoguess; 
    }

    void introduction(){
    cout<<"Hello and welcome to a guessing game for numbers.\nThe range for guessing the numbers is between 1 to 100. \nThere will be three modes of guessing. See them below.";
    cout<<"Choose the difficulty you desire:\n1. Easy (10 chances). \n2. Medium (6 chances).\n3. Hard(3 chances).\nWhich difficulty would you like? - ";
}

    void difficutlies() { 
        if (chosendiff == 1) {
            cout << "You have chosen Easy. You have 10 chances to guess the number.\n";
            cout<<"The number to be guessed has been set.\n";
            attempts = 10;
        } else if (chosendiff == 2) {
            cout << "You have chosen Medium. You have 6 chances to guess the number.\n";
            cout<<"The number to be guessed has been set.\n";
            attempts = 6;
        } else if (chosendiff == 3) {
            cout << "You have chosen Hard. You have 3 chances to guess the number.\n";
            cout<<"The number to be guessed has been set.\n";
            attempts = 3;
        } else {
            cout << "Invalid choice. Please choose a valid difficulty (1, 2, or 3).\n";
            attempts = 0;
        }
    }

    void guess() {
        cout << "Guess the number: ";
        cin >> number;
        attemptsdone++;
    }

    void guessChecker() {
        if (number == getNumToGuess()) {
            cout << "Congratulations! You have guessed the number correctly.\n";
            cout<<"It took you "<<attemptsdone<< " attempts to guess it right.\n";
        } else if (number < getNumToGuess()) {
            cout << "Incorrect! The correct number is greater than " << number << ".\n";
        } else if (number > getNumToGuess()) {
            cout << "Incorrect! The correct number is less than " << number << ".\n";
        } else {
            cout << "Invalid input. Please enter a valid number.\n";
        }
    }
};

int main() {
    Guesser guesser;
    guesser.introduction();
    cin >> guesser.chosendiff;

    guesser.difficutlies();
    if (guesser.attempts == 0) return 0;

    for (int i = 0; i < guesser.attempts; i++) {
        guesser.guess();
        guesser.guessChecker();

        if (guesser.number == guesser.getNumToGuess()) {
            break;
        }

        if (i == guesser.attempts - 1) {
            cout << "Game over!\nYou have run out of attempts. The number to guess was " 
                 << guesser.getNumToGuess() << ".\n";
        }
    }

    return 0;
}
