#include <bits/stdc++.h>
using namespace std;
// Anagram Check - Strings
bool isAnagram(string s, string t){
    if(s.size()!=t.size()) return false;
    int freq[26]={};
    for(char c:s) freq[c-'a']++;
    for(char c:t) freq[c-'a']--;
    for(int f:freq) if(f) return false;
    return true;
}
int main(){
    string s,t; cin>>s>>t;
    cout<<(isAnagram(s,t)?"YES":"NO")<<"\n";
}
