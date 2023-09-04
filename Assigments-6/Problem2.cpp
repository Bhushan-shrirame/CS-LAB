#include <bits/stdc++.h>
using namespace std;


void constructResults(const string& startWord, const string& currentWord, const unordered_map<string, vector<string>>& parentMap, vector<string>& path, vector<vector<string>>& results) {
    if (currentWord == startWord) {
        path.push_back(startWord);
        vector<string> temp = path;
        reverse(temp.begin(), temp.end()); // Reverse the path to get the correct order
        results.push_back(temp);
        path.pop_back();
        return;
    }
    
    path.push_back(currentWord);
    
    for (const string& parent : parentMap.at(currentWord)) {
        constructResults(startWord, parent, parentMap, path, results);
    }
    
    path.pop_back();
}
vector<vector<string>> findLadders(string startWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    vector<vector<string>> results;
    
    if (wordSet.find(endWord) == wordSet.end()) {
        return results; // endWord is not in the wordList, no transformation possible
    }
    
    queue<string> bfsQueue;
    bfsQueue.push(startWord);
    
    unordered_map<string, vector<string>> parentMap;
    parentMap[startWord] = vector<string>();
    
    bool foundEndWord = false;
    
    while (!bfsQueue.empty() && !foundEndWord) {
        int currentSize = bfsQueue.size();
        unordered_set<string> currentLevelWords;
        
        for (int i = 0; i < currentSize; i++) {
            string word = bfsQueue.front();
            bfsQueue.pop();
            
            for (int j = 0; j < word.length(); j++) {
                string newWord = word;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newWord[j] = ch;
                    
                    if (wordSet.find(newWord) != wordSet.end()) {
                        if (newWord == endWord) {
                            foundEndWord = true;
                        }
                        
                        if (parentMap.find(newWord) == parentMap.end()) {
                            bfsQueue.push(newWord);
                            currentLevelWords.insert(newWord);
                            parentMap[newWord] = {word};
                        } else {
                            parentMap[newWord].push_back(word);
                        }
                    }
                }
            }
        }
        
        // Remove words at the current level from wordSet to avoid revisiting them
        for (const string& word : currentLevelWords) {
            wordSet.erase(word);
        }
    }
    
    if (foundEndWord) {
        vector<string> path;
        constructResults(startWord, endWord, parentMap, path, results);
    }
    
    return results;
}



int main() {
    string startWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    
    vector<vector<string>> sequences = findLadders(startWord, endWord, wordList);
    
    if (sequences.empty()) {
        cout << "No transformation sequences found." << endl;
    } else {
        cout << "Shortest transformation sequences:" << endl;
        for (const vector<string>& sequence : sequences) {
            for (const string& word : sequence) {
                cout << word << " -> ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
