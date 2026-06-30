#include <bits/stdc++.h>
using namespace std;
// Trie Data Structure for Prefix Search
struct TrieNode {
    unordered_map<char,TrieNode*> children;
    bool isEnd=false;
};
struct Trie {
    TrieNode* root=new TrieNode();
    void insert(const string& word){
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->children.count(c)) cur->children[c]=new TrieNode();
            cur=cur->children[c];
        }
        cur->isEnd=true;
    }
    bool search(const string& word){
        TrieNode* cur=root;
        for(char c:word){
            if(!cur->children.count(c)) return false;
            cur=cur->children[c];
        }
        return cur->isEnd;
    }
    bool startsWith(const string& prefix){
        TrieNode* cur=root;
        for(char c:prefix){
            if(!cur->children.count(c)) return false;
            cur=cur->children[c];
        }
        return true;
    }
};
int main(){
    Trie t;
    int n; cin>>n;
    while(n--){
        string op,w; cin>>op>>w;
        if(op=="insert") t.insert(w);
        else if(op=="search") cout<<(t.search(w)?"yes":"no")<<"\n";
        else cout<<(t.startsWith(w)?"yes":"no")<<"\n";
    }
}
