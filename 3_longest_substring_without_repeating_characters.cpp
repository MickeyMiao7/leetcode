#include <string>
#include <iostream>
#include <unordered_map>
#include <algorithm>


int main(void){
    std::string s("pwwkew");
    std::unordered_map<char, int> record;
    int longest = 0;
    for(int i = 0; i < s.length(); i++){
        if(record.find(s[i]) == record.end()){
            record.insert(std::pair<char, int>(s[i], i));
        }
        else{
            int k = record[s[i]];
            record[s[i]] = i;
            for(std::unordered_map<char, int> ::iterator it = record.begin(); it != record.end(); )
                if(it->second < k)
                    record.erase(it++);
                else
                    it++;
        }
        longest = std::max(longest, (int)record.size());
    }
    std::cout << longest << std::endl;

    return 0;
}

