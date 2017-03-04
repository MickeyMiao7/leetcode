#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution{
    void addNextWords(string word, unordered_set<string> &wordList, queue<string> &q){
        wordList.erase(word);
        for(int p = 0; (int)p < word.length(); p++){
            char letter = word[p];
            for(char k = 'a'; k <= 'z'; k++){
                word[p] = k;
                if(wordList.find(word) != wordList.end()){
                    q.push(word);
                    wordList.erase(word);
                } 
            }
            word[p] = letter;   
        }
    }

public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        wordList.insert(endWord);
        queue<string> q;
        addNextWords(beginWord, wordList, q);
        int dist = 2;
        while(!q.empty()){
            int num = q.size();
            for(int i = 0; i < num; i++){
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return dist;
                addNextWords(word, wordList, q);
            }
            dist++;
        }        
        return 0;
    }
    
          
};

int main(){
    Solution sol;
    unordered_set<string> wordList;
    wordList.insert("hit");
    wordList.insert("hot");
    wordList.insert("dot");
    wordList.insert("dog");
    wordList.insert("lot");
    wordList.insert("log");
    string beginWord = "hit";
    string endWord = "cog";
    int i = sol.ladderLength(beginWord, endWord, wordList);
    cout << i << endl;
    return 0;
}
