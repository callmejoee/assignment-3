#include <bits/stdc++.h>
using namespace std;

// vector to store the dictionary words
vector<string> dictionaryVector;

// function to check if the word is included in the dictionary
void load_vector() {
    // load the words in the dictionary
    ifstream dictionaryFile("dictionary.txt");
    string words;
    while (dictionaryFile >> words) {
        dictionaryVector.push_back(words);
    }
}
int wordIncluded(string& word){
    // check if the word is included in the dictionary
    for (int i = 0; i < dictionaryVector.size(); i++){
        if (dictionaryVector[i] == word){
            return 1;
        }
    }
    return 0;
}

// function to break the word
void wordBreak(string word, int n , string result = ""){
    for (int i = 1; i <= n; i++){
        string prefix = word.substr(0, i);
        if (wordIncluded(prefix)){
            if (i == n){
                result += prefix;
                cout << result << endl;
                return;
            }
            wordBreak(word.substr(i, n - i), n - i, result + prefix + " ");
        }
    }
}

void wordBreakProgram(string word){
    int n = word.length();
    wordBreak(word, n);
}

int main(){
    load_vector();
    wordBreakProgram(word);
    wordBreakProgram(example);
    return 0;
}