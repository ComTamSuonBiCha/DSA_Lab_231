#include<iostream>
#include<string>
using namespace std;
void reverseWord(std::string& word, int start, int end) {
    while (start < end) {
        // Swap characters at start and end positions
        char temp = word[start];
        word[start] = word[end];
        word[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse a sentence using recursion
std::string reverseSentence(const std::string& s) {
    // Base case: If the input string is empty, return an empty string.
    if (s.empty()) {
        return "";
    }

    // Find the position of the first space character.
    size_t spacePos = s.find(' ');

    // If there are no spaces left, the entire string is a single word.
    if (spacePos == std::string::npos) {
        return s;
    }

    // Extract the first word and the rest of the string.
    std::string firstWord = s.substr(0, spacePos);
    std::string restOfSentence = s.substr(spacePos + 1);

    // Recursively reverse the rest of the sentence and append the first word.
    std::string reversedRest = reverseSentence(restOfSentence);

    // Concatenate the reversed rest with the first word, separated by a space.
    return reversedRest + " " + firstWord;
}