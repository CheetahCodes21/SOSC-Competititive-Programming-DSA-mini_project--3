# SOSC-Competititive-Programming-DSA-mini_project--3
# Morse Code Converter 🔑

## Overview

This C++ program helps you convert text to Morse code and vice versa. Morse code is a way to represent letters and numbers using dots (.) and dashes (-). This program uses a simple menu to let you choose between converting regular text to Morse code or Morse code back to text.

## How It Works

### Morse Code to Text

1. **Mapping Characters to Morse Code:**
   - The program has a list of letters, numbers, and some special characters with their corresponding Morse code. For example, 'A' is represented as ".-", 'B' as "-...", and so on.
   - The mappings are stored in a special list called a "map."

2. **Converting Text to Morse Code:**
   - When you choose the option to convert text to Morse code, you enter some text (like "HELLO").
   - The program looks at each letter in your text and finds its Morse code from the map.
   - It then combines these Morse codes into a single string, representing the input text in Morse code.

### Text to Morse Code

1. **Mapping Morse Code to Characters:**
   - The program also knows how to go in the reverse direction. It has a map that tells it what letter or number corresponds to a particular Morse code. For example, ".-" corresponds to 'A', "-..." to 'B', and so on.

2. **Converting Morse Code to Text:**
   - When you choose the option to convert Morse code to text, you enter some Morse code (like ".--. .-. --- .-- .-.. -..").
   - The program breaks the Morse code into individual codes for each letter.
   - It then looks up each Morse code in the map to find the corresponding letter and combines these letters into a single string, representing the decoded text.

### Running the Program

1. **Menu:**
   - The program starts by showing you a menu with options to convert text to Morse code, Morse code to text, or exit.

2. **User Input:**
   - You choose an option by entering a number.
   - If you choose to convert text to Morse code, you enter some text. If you choose to convert Morse code to text, you enter Morse code.

3. **Conversion:**
   - The program performs the conversion using the logic explained above.

4. **Result:**
   - The converted text or Morse code is displayed.

5. **Repeat or Exit:**
   - You can choose to convert more or exit the program.

## Note

- Uppercase and lowercase letters are treated the same.
- If you enter something the program doesn't understand, it might use '?' to represent that unknown character.

Feel free to explore, experiment, and learn from this simple Morse code converter!

## Code Implementation

This C++ program converts text to Morse code and vice versa using a simple menu-driven interface. The logic is implemented using two global unordered maps, `charToMorseMap` and `morseToCharMap`, to store mappings between characters and their Morse code representations.

#### 1. Morse Code Mapping

The Morse code representations for each character (including letters, numbers, and space) are initially set up in the `initializeCharToMorseMap` function:

```cpp
void initializeCharToMorseMap() {
    // Assign Morse code to each letter and number, also include space as '/'
    // ... (mapping details)
    charToMorseMap[' '] = "/";  // Space is represented by '/'
}
```

Each character is mapped to its corresponding Morse code. Spaces are represented by a forward slash ('/').

#### 2. Reverse Mapping

A reverse mapping is also established in the `initializeMorseToCharMap` function:

```cpp
void initializeMorseToCharMap() {
    for (auto& pair : charToMorseMap) {
        morseToCharMap[pair.second] = pair.first;
    }
}
```

This reverse mapping (`morseToCharMap`) is created by swapping the keys and values of `charToMorseMap`. It is used later to convert Morse code back to text.
Using `auto`, The `auto` keyword is like a shortcut that tells the computer, "Figure out what type of thing this is on your own." In this case, it's used in a loop to go through each pair without explicitly saying what type each pair is.

#### 3. Text to Morse Conversion
The `textToMorse` function converts a given text to Morse code:

```cpp
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
```

For each character in the input text, the program checks if it is present in the `charToMorseMap`. If yes, it appends the Morse code to a stringstream; otherwise, it appends a space.

#### 4. Morse to Text Conversion
The `morseToText` function uses `istringstream` to tokenize the Morse code string into individual Morse code sequences.
The `morseToText` function converts Morse code back to text:

```cpp
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
```

It uses a stringstream to build the resulting text. For each Morse code token, it checks if it is present in `morseToCharMap` and appends the corresponding character; otherwise, it appends a question mark.
The `istringstream iss(morseCode);` initializes an `istringstream` object with the Morse code string. The `while (iss >> token)` loop extracts individual Morse code tokens separated by spaces and processes each token.

#### 5. User Interface (main function)

The `main` function serves as the user interface. It continuously prompts the user with a menu to choose between converting text to Morse code, Morse code to text, or exiting the program. It uses the `textToMorse` and `morseToText` functions based on the user's choice.

```cpp
int main() {
    // ... (Initialization of maps)
    string morseCode, text, result = "";
    int choice;

    while (true) {
        // ... (Display menu and get user choice)
        if (choice == 1) {
            // ... (Convert text to Morse code)
        } else if (choice == 2) {
            // ... (Convert Morse code to text)
        } else if (choice == 3) {
            // ... (Exit the program)
        } else {
            // ... (Invalid input handling)
        }
    }

    return 0;
}
```

The program keeps running until the user chooses to exit, and it handles user inputs gracefully.

Overall, this C++ program provides a simple Morse code conversion tool with an easy-to-use command-line interface.

## Resources:

## STAGE 1: Introduction to Morse Code

1. **About Telegraph:**
- [Telegraph Overview Video](https://youtu.be/tzP7QOOAt4I?si=Y0lWkpP7iYycAq-W)
  This video provides insights into the history and functioning of the telegraph, offering context for Morse Code.

2. **How does Morse Code work:**
- [Morse Code Explanation Video](https://youtu.be/iy8BaMs_JuI?si=whz3HiPrGRBVOpce)
   This resource explains the fundamentals of Morse Code, providing a solid foundation for understanding the encoding and decoding processes.

---

## STAGE 2: Introduction to Hashing


1. **Implementing Hash Table in C:**
- [Hash Table Implementation in C Video](https://youtu.be/2Ti5yvumFTU?si=dPqtumxCLB5P9TXG)
  This video walks through the implementation of a hash table in the C programming language, offering practical insights into the data structure.

2. **Implementing Hash Table in C++:**
- a. [Hash Table Implementation in C++ (Part 1)](https://youtu.be/G87TuBjByts?si=FudLaEezJAAoNk3C)
- b. [Hash Table Implementation in C++ (Part 2)](https://youtu.be/7mUKGHznpfg?si=VDnrQlP7NWWNdVSb)
- c. [Hash Table Implementation in C++ (Part 3)](https://youtu.be/gUrfXZ0hqoA?si=wYyKeTVRrxY0Ot-L)
  These three videos provide a comprehensive guide to implementing a hash table in the C++ programming language, covering various aspects and functionalities.

## STAGE 3: Morse Code Implementation

1. [GeeksforGeeks - Morse Code Implementation](https://www.geeksforgeeks.org/morse-code-implementation/)
   This written evidence resource from GeeksforGeeks supplements the video content and provides more information on Morse Code implementation. It can be used as    a reference or complement to your programme development.

---

The above resources are the once I have used feel free to explore more and if you find any additional informative resources to update this part of the file.

---




