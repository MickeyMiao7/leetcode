#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode* reverseBetween(ListNode* head, int m, int n) {
            ListNode* res = new ListNode(-1);
            res->next = head;
            ListNode *first, *temp, *start;
            first = res;
            n -= m;
            while(m--)
                first = first->next;

            start = first->next;
            while(--n){
                temp = start->next;
                start->next = temp->next;
                temp->next = first->next;
                first->next = temp;
            }
            return res->next;
        }
};

int main(){
    Solution sol;
    ListNode a(1);
    ListNode b(2);
    ListNode c(3);
    ListNode d(4);
    ListNode e(5);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    ListNode *p = &a;
    ListNode *res = sol.reverseBetween(p, 2, 4);
    while(res){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}
