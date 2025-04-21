#include "Dictionary.h"

int main() {
    Dictionary myDictionary;
    myDictionary.loadFromFile("../data/list.txt");

    string input;
    cout << "Enter a word: ";
    cin >> input;

    if (myDictionary.searchExact(input)) {
        cout << "Word found in dictionary." << endl;
    } else {
        cout << "Word not found.\n";

        vector<string> prefixMatches = myDictionary.searchByPrefix(input.substr(0, 2));
        if (!prefixMatches.empty()) {
            cout << "🔎 Suggestions with similar start:\n";
            for (const string& word : prefixMatches) {
                cout << "  - " << word << endl;
            }
        } else {
            string suggestion = myDictionary.suggestSimilar(input);
            cout << "Did you mean: " << suggestion << "?" << endl;
        }
    }
    return 0;
}
