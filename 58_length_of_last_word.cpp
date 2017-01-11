#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution{
    public:
        int lengthOfLastWord(string s){
            int cnt = 0;
            int i = s.length() - 1;
            while(i >= 0 && s.at(i) == ' ') i--;
            while(i >= 0 && s.at(i) != ' '){
                cnt++;
                i--;
            }
            return cnt;
        }
          
};
int main(){
    Solution sol;
    string s("hello world");
    return 0;
}
