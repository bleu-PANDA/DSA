#include <bits/stdc++.h>
using namespace std;
// Reverse Linked List
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v): val(v), next(nullptr){}
};
ListNode* reverse(ListNode* head){
    ListNode* prev=nullptr;
    while(head){
        ListNode* nxt=head->next;
        head->next=prev;
        prev=head;
        head=nxt;
    }
    return prev;
}
int main(){
    int n; cin>>n;
    ListNode* head=nullptr, *tail=nullptr;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        ListNode* node=new ListNode(x);
        if(!head) head=tail=node;
        else { tail->next=node; tail=node; }
    }
    head=reverse(head);
    for(ListNode* cur=head;cur;cur=cur->next) cout<<cur->val<<" ";
}
