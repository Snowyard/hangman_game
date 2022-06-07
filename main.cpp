#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

string game(char, string, string&);

int main() {
    cout << "\nWelcome to Bruno's Hangman!" << endl;
    
    vector<string> wordsList = {"feast", "guitar", "glue", "body", "wilderness"};
    srand(time(NULL));
    string randomWord = {wordsList.at(rand() % (wordsList.size()-1))};
    
    string result {}; // result not being changed after each game iteration
    
    for(int i {0}; i < randomWord.length(); i++) {
        result += "_";
    }
    
//    string &game_result {result};
    
    cout << "This is your word: " << result << endl;
    
    string win {"\nCongrats! You beat my game!\n\n"};
    string lose {"\nSucks to be you! The answer was " + randomWord + "!\n\n"};
    int x {0};
    
    int i {0};
    bool win_condition {false};
    
    while ((i < randomWord.length() + 5) && (win_condition == false)){
        char guess {};
        cout << "\nEnter letter: ";
        cin >> guess;
        
        game(guess, randomWord, result);
        i++;
        
        for(char c: result)  
            if(c == '_')
                x++;
            
        if(x == 0) {
            cout << win;
            win_condition = true;
        }
        
        x = 0;
        
    }
    
    for(char z: result)  
            if(z == '_') {
                cout << lose;
                break;
            }
    
    return 0;
}

string game(char guess, string randomWord, string &result) {
    bool correct {false};
    
    for(int i {0}; i < randomWord.length(); i++) {
        if(guess == randomWord.at(i)) {
            result.at(i) = guess;
            correct = true;
        }
    }
    
    if(correct == false) {
        cout << endl << guess << " is not present in the word! \n" << endl;
    }
    else {
        cout << "\nNice job!\n" << endl;
    }
    
    cout << result << endl;
    
    return result;
}
