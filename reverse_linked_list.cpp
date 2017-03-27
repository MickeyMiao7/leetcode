#include <iostream>

using namespace std;

struct node{
    int val;
    node *next;
    node(int i): val(i), next(NULL){}
};

node* reverse(node* pHead){
    node *res = new node(-1);
    res->next = pHead;
    node *first = res->next;
    node *temp;
    while(first->next){
        temp = first->next;
        first->next = temp->next;
        temp->next = res->next;
        res->next = temp;
    }
    return res->next;
}
int main(void){
    node a(1);
    node b(2);
    node c(3);
    node d(4);
    a.next = &b;
    b.next = &c;
    c.next = &d;
    
    node *p = &a;
    node *s = reverse(p);
    while(s){
        cout << s->val << endl;
        s = s->next;
    }
    return 0;
}
