# DictionarySearch – Software Developer SD I Assignment

## 📖 Assignment Objective
Design a **dictionary data structure** in C++ that:
- Allows searching of any entered word
- Returns the relevant result if the word is found
- If not found, it suggests:
  - Words starting with the same prefix
  - Closest match (spelling correction)

## ✨ Special Requirements
- Used meaningful function and variable names
- Included optimized searching
- Handled edge cases (like typos or empty input)
- Included time and space complexity analysis

## 💡 Features Implemented
- `searchExact(word)`: O(1) lookup using unordered_set
- `searchByPrefix(prefix)`: Suggests all words starting with the same prefix
- `suggestSimilar(word)`: Finds the closest word based on character mismatches

## 📂 Project Folder Structure
```
DictionarySearch/
├── data/
│   └── list.txt         # Word list file
├── src/
│   ├── Dictionary.h     # Dictionary logic
│   └── main.cpp         # Program entry point
├── README.md            # This file
```

## 🧪 How to Run (VS Code / Linux / Windows / Mac)
```bash
cd src
g++ main.cpp -o dictsearch
./dictsearch
```

Make sure `list.txt` is in the `data/` folder and accessible by relative path (`../data/list.txt`).

## 🔍 Example
```
Enter a word: abandon
✅ Word found in dictionary.

Enter a word: abandonn
❌ Word not found.
🔎 Suggestions:
  - abandon
  - abandoned
✨ Did you mean: abandon?
```

## 📊 Time and Space Complexity
| Function              | Time Complexity   | Space Complexity |
|-----------------------|-------------------|------------------|
| loadFromFile          | O(N)              | O(N)             |
| searchExact           | O(1) (average)    | O(1)             |
| searchByPrefix        | O(N × L)          | O(1)             |
| suggestSimilar        | O(N × L)          | O(1)             |

- N = number of words in the file
- L = average length of the words

---

> Submitted by: Priyashi Barnwal  
> Position Applied: Software Developer – SD I
