#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int m = nums1.size();
            int n = nums2.size();
            int total = m + n;
            if(total & 0x1)
                return findKth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1) * 1.0;
            else
                return (findKth(nums1.begin(), m, nums2.begin(), n, total / 2) + findKth(nums1.begin(), m, nums2.begin(), n, total / 2 + 1)) / 2.0;
                                    
            return 0;
        }
    private:
        int findKth(vector<int>::iterator a, int m, vector<int>::iterator b, int n, int k){
            if (m == 0)
                return *(b + k - 1);
            if (m > n)
                return findKth(b, n, a, m, k);
            if (k == 1)
                return min(*a, *b);
            int ia = min(k / 2, m);
            int ib = k - ia;
            if (*(a + ia - 1) < *(b + ib - 1))
                return findKth(a + ia, m - ia, b, n, ib);
            else if(*(a + ia - 1) > *(b + ib - 1))
                return findKth(a, m, b + ib, n - ib, ia);
            else
                return *(a + ia - 1);
                // return a[ia - 1];

            

        }

          
};

int main(){
    Solution sol;
    return 0;
}
