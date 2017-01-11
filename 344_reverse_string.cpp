#include <iostream>
#include <string>

using namespace std;

class Solution{
	public:
		string reverseString(string s){
			int len = s.length();
			char temp;
			for(int i=0; i<len/2; i++){
				temp = s[i];
				s[i] = s[len - 1 -i];
				s[len - 1 -i] = temp;
			}
			return s;
			}
};

class Solution2{
	public:
		char *reverseString(char *p){
			return p;
		}
};
int main(void){
	Solution solution;
	cout << solution.reverseString("123") << endl;
	return 0;
}
