#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;


string generatePassword(const vector<string>& words, int user_number) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, words.size() - 1);

    string password;
    for (int i = 0; i < user_number; i++) {
        int index = dis(gen);
        password += words[index];
    }
    reverse(password.begin(), password.end());
    return password;
}


string replaceWithUppercase(string password) {
    for (char& c : password) {
        if (isalpha(c)) {
            c = toupper(c);
        }
    }
    return password;
}


string swapLetters(string password) {
    if (password.length() >= 4) {
        string firstTwo = password.substr(0, 2);
        string lastTwo = password.substr(password.length() - 2);
        password.replace(0, 2, lastTwo);
        password.replace(password.length() - 2, 2, firstTwo);
    }
    return password;
}


bool searchLetter(const string& source, char keyLetter) {
    return source.find(keyLetter) != string::npos;
}

int main() {

    vector<string> words = {"password", "secure", "authentication", "random", "generate", "string", "reverse", "uppercase", "swap"};


    int userNumber;
    do {
        cout << "Please enter a value (from 3 to 7) for the number of words: ";
        cin >> userNumber;
    } while (userNumber < 3 || userNumber > 7);


    string initialPassword = generatePassword(words, userNumber);


    string finalPassword = swapLetters(replaceWithUppercase(initialPassword));


    cout << "Initial password: " << initialPassword << endl;
    cout << "Final version of the password: " << finalPassword << endl;


    char keyLetter = 'r';
    bool found = searchLetter(finalPassword, keyLetter);
    if (found) {
        cout << "Key letter '" << keyLetter << "' found in the password." << endl;
    } else {
        cout << "Key letter '" << keyLetter << "' not found in the password." << endl;
    }

    return 0;
}