#include <iostream>
#include <unordered_map>
#include <sstream>
using namespace std;

// Global map to store Morse code representations for each character
unordered_map<char, string> charToMorseMap;

// Function to set up the charToMorseMap with Morse code representations
void initializeCharToMorseMap() {
    // Assign Morse code to each letter and number, also include space as '/'
    charToMorseMap['A'] = ".-";
    charToMorseMap['B'] = "-...";
    charToMorseMap['C'] = "-.-.";
    charToMorseMap['D'] = "-..";
    charToMorseMap['E'] = ".";
    charToMorseMap['F'] = "..-.";
    charToMorseMap['G'] = "--.";
    charToMorseMap['H'] = "....";
    charToMorseMap['I'] = "..";
    charToMorseMap['J'] = ".---";
    charToMorseMap['K'] = "-.-";
    charToMorseMap['L'] = ".-..";
    charToMorseMap['M'] = "--";
    charToMorseMap['N'] = "-.";
    charToMorseMap['O'] = "---";
    charToMorseMap['P'] = ".--.";
    charToMorseMap['Q'] = "--.-";
    charToMorseMap['R'] = ".-.";
    charToMorseMap['S'] = "...";
    charToMorseMap['T'] = "-";
    charToMorseMap['U'] = "..-";
    charToMorseMap['V'] = "...-";
    charToMorseMap['W'] = ".--";
    charToMorseMap['X'] = "-..-";
    charToMorseMap['Y'] = "-.--";
    charToMorseMap['Z'] = "--..";
    charToMorseMap['0'] = "-----";
    charToMorseMap['1'] = ".----";
    charToMorseMap['2'] = "..---";
    charToMorseMap['3'] = "...--";
    charToMorseMap['4'] = "....-";
    charToMorseMap['5'] = ".....";
    charToMorseMap['6'] = "-....";
    charToMorseMap['7'] = "--...";
    charToMorseMap['8'] = "---..";
    charToMorseMap['9'] = "----.";
    charToMorseMap[' '] = "/";  // Space is represented by '/'
}

// Global map to store reverse mapping of Morse code to characters
unordered_map<string, char> morseToCharMap;

// Function to set up the morseToCharMap with reverse mapping
void initializeMorseToCharMap() {
    for (auto& pair : charToMorseMap) {
        morseToCharMap[pair.second] = pair.first;
    }
}

// Function to convert a given text to Morse code
string textToMorse(const string& text) {
    stringstream morseCode;
    for (char c : text) {
        c = toupper(c);  // Convert the character to uppercase
        if (charToMorseMap.find(c) != charToMorseMap.end()) {
            morseCode << charToMorseMap[c] << " ";  // Append Morse code to stringstream
        } else {
            morseCode << " ";  // If character is not in the map, append a space
        }
    }
    return morseCode.str();
}

// Function to convert Morse code to text
string morseToText(const string& morseCode) {
    stringstream text;
    istringstream iss(morseCode);
    string token;
    while (iss >> token) {
        if (morseToCharMap.find(token) != morseToCharMap.end()) {
            text << morseToCharMap[token];  // Append character to stringstream
        } else {
            text << '?';  // If Morse code is not in the map, append a question mark
        }
    }
    return text.str();
}

int main() {
    initializeCharToMorseMap();  // Call the function to set up charToMorseMap
    initializeMorseToCharMap();  // Call the function to set up morseToCharMap

    string morseCode, text, result = "";
    int choice;

    while (true) {
        // Display menu for user choices
        cout << "Enter choice:\n 1: Convert Text to MorseCode \n 2: Convert MorseCode to Text \n 3: Exit" << endl;
        cout << "Choice:";
        cin >> choice;

        if (choice == 1) {
            // User wants to convert text to Morse code
            cout << "Enter Text: ";
            cin.ignore();
            getline(cin, text);
            result = textToMorse(text);
            cout << text << " in Morse code is: " << result << endl;
        } else if (choice == 2) {
            // User wants to convert Morse code to text
            cout << "Enter Morse code: ";
            cin.ignore();
            getline(cin, morseCode);
            result = morseToText(morseCode);
            cout << morseCode << " in Text is: " << result << endl;
        } else if (choice == 3) {
            // User wants to exit the program
            break;
        } else {
            // User entered an invalid choice
            cout << "Invalid Input" << endl;
            break;
        }
    }

    return 0;
}
