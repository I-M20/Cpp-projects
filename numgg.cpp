#include <iostream>
#include <random>
using namespace std;

class Guesser{
protected:
int numtoguess;
public:
int number;
default_random_engine generator;
uniform_int_distribution<int> distribution;
Guesser() : distribution(1, 100), numtoguess(distribution(generator)) {}
int getNumToGuess() const { return numtoguess; }
int chosendiff;
int attempts;
virtual void guess(){
    cout<<"Guess the number: ";
    cin>>number;
}
virtual int difficutlies(){ 
    int Easy, Medium, Hard;
    if (chosendiff == 1){
        cout<<"You have chosen Easy. You have 10 chances to guess the number. \n";
        attempts = 10;
    }
    else if (chosendiff == 2){
        cout<<"You have chosen Medium. You have 6 chances to guess the number. \n";
        attempts = 6;
    }
    else if (chosendiff == 3){
        cout<<"You have chosen Hard. You have 3 chances to guess the number. \n";
        attempts = 3;
    }
    else{
        cout<<"Invalid choice. Please choose a valid difficulty. \n";
    }
}
int introduction(){
    cout<<"Hello and welcome to a guessing game for numbers. \nThe range for guessing the numbers is between 1 to 100. \nThere will be three modes of guessing. See them below.";
    cout<<"Choose the difficulty you desire:\n1. Easy (10 chances). \n2. Medium (6 chances).\n3. Hard(3 chances).\nWhich difficulty would you like? - ";
}

};


int main(){
    Guesser guesser;
    guesser.introduction();
    cin >> guesser.chosendiff;
    guesser.difficutlies();
    guesser.guess();
    if (guesser.difficutlies() == 1){
            if (guesser.number == guesser.getNumToGuess()){
                cout<<"Congratulations! You have guessed the number correctly. \n";
                break;
            }
            else if (guesser.number < guesser.getNumToGuess()){
                cout<<"The number you have guessed is lower than the number to guess. \n";
            }
            else if (guesser.number > guesser.getNumToGuess()){
                cout<<"The number you have guessed is higher than the number to guess. \n";
                cout<<"The number you have guessed is higher than the number to guess. \n";
            }
            else{
                cout<<"Invalid input. Please enter a valid number. \n";
            }
        }
    else if (guesser.difficutlies() == 2){
        for (int i = 0; i < guesser.attempts; i++){
            if (guesser.number == guesser.numtoguess){
                cout<<"Congratulations! You have guessed the number correctly. \n";
                break;
            }
            else if (guesser.number < guesser.numtoguess){
                cout<<"The number you have guessed is lower than the number to guess. \n";
            }
            else if (guesser.number > guesser.numtoguess){
                cout<<"The number you have guessed is higher than the number to guess. \n";
            }
            else{
                cout<<"Invalid input. Please enter a valid number. \n";
            }
        }
    }
    else if (guesser.difficutlies() == 3){
        for (int i = 0; i < guesser.attempts; i++){
            if (guesser.number == guesser.numtoguess){
                cout<<"Congratulations! You have guessed the number correctly. \n";
                break;
            }
            else if (guesser.number < guesser.numtoguess){
                cout<<"The number you have guessed is lower than the number to guess. \n";
            }
            else if (guesser.number > guesser.numtoguess){
                cout<<"The number you have guessed is higher than the number to guess. \n";
            }
            else{
                cout<<"Invalid input. Please enter a valid number. \n";
            }
        }
    }
    else{
        cout<<"Invalid input. Please enter a valid number. \n";
    }
    return 0;
    }