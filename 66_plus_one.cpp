#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
    public:
          void plusOne(vector<int>& digits){
              vector<int>::iterator iter;
              for(int i=digits.size() -1; i>=0; i--){
                  if(digits[i] == 9){
                      digits[i] = 0;
                  }
                  else{
                      digits[i] += 1;
                      return;
                  }
              }
              digits[0] = 1;
              digits.push_back(0);
              return;
          }
};

int main(){
    Solution sol;
    vector<int> input{1, 1, 9};
    sol.plusOne(input);
    for(int i =0; i < input.size(); i++)
        cout << input[i] << endl; 
    return 0;
}
