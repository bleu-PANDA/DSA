#include <bits/stdc++.h>
using namespace std;
// Stack - Valid Parentheses
bool isValid(const string& s){
    stack<char> st;
    for(char c:s){
        if(c=='('||c=='['||c=='{') st.push(c);
        else {
            if(st.empty()) return false;
            char top=st.top(); st.pop();
            if(c==')'&&top!='(') return false;
            if(c==']'&&top!='[') return false;
            if(c=='}'&&top!='{') return false;
        }
    }
    return st.empty();
}
int main(){
    string s; cin>>s;
    cout<<(isValid(s)?"YES":"NO")<<"\n";
}
