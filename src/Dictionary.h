#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <bits/stdc++.h>
#include <fstream>
using namespace std;

class Dictionary {
private:
    unordered_set<string> wordSet;
    vector<string> wordList;

    int countDifferences(const string& a, const string& b) {
        int differences = 0;
        int len = min(a.length(), b.length());
        for (int i = 0; i < len; i++) {
            if (a[i] != b[i]) differences++;
        }
        differences += abs((int)a.length() - (int)b.length());
        return differences;
    }

public:
    void loadFromFile(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Could not open file '" << filename << "'\n";
            exit(1);
        }
        string word;
        while (file >> word) {
            wordSet.insert(word);
            wordList.push_back(word);
        }
        file.close();
    }

    bool searchExact(const string& word) {
        return wordSet.find(word) != wordSet.end();
    }

    vector<string> searchByPrefix(const string& prefix) {
        vector<string> suggestions;
        for (const string& word : wordList) {
            if (word.substr(0, prefix.length()) == prefix) {
                suggestions.push_back(word);
            }
        }
        return suggestions;
    }

    string suggestSimilar(const string& input) {
        int minDiff = numeric_limits<int>::max();
        string closest;
        for (const string& word : wordList) {
            int diff = countDifferences(input, word);
            if (diff < minDiff) {
                minDiff = diff;
                closest = word;
            }
        }
        return closest;
    }
};
