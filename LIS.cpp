#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// L(s) = L[j] + 1 if A[j] < A[i]

class Solution{
    public:
        int lis(int A[], int n){
            int res = 1;
            int *l = new int[n]; 
            for(int i = 0; i < n; i++){
                l[i] = 1;
                for(int j = 0; j < i; j++){
                    if(A[j] < A[i])
                        l[i] = max(l[i], l[j] + 1);
                }
                res = max(res, l[i]);
            }
            return res;
        }
          
};

int main(){
    Solution sol;
    int A[] = {
        5, 3, 4, 8, 6, 7
    };
    int res = sol.lis(A, 6);
    cout << res << endl;
    return 0;
}
