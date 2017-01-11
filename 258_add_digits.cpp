#include <iostream>
using namespace std;

class Solution{
	public:
		int addDigits(int num){
			int result = 0;
			while(num>0){
				result += num % 10;
				cout << result << endl;
				num = result / 10;
				cout << num << endl;
			}
			return result;
		}
};

int main(void){
	Solution so;
	int input;
	cin >> input;
	so.addDigits(input);
	// cout << so.addDigits(input) << endl;
	return 0;
}



