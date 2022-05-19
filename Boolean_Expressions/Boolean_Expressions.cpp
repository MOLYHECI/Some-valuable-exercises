#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int priority(char op){
    switch (op){
        case '|': return 1;
        case '&': return 2;
        case '!': return 3;
        case '(': return 4;
        default : return 0;
    }
}
queue<char> infix_to_postfix(string infix){
    queue<char> q;
    stack<char> s;
    for(int i=0;i<infix.size();++i){
        if(infix[i]==' ') continue;
        if(infix[i]=='F'||infix[i]=='V') q.push(infix[i]);
        else if(s.empty()||infix[i]=='(') s.push(infix[i]);
        else if(infix[i]==')'){
            while(s.top()!='('){
                q.push(s.top());
                s.pop();
            }
            s.pop();
        }
        else{
           while(priority(s.top())>=priority(infix[i])&&s.top()!='('){
               q.push(s.top());
               s.pop();
           }
           s.push(infix[i]);
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    return q;
}
bool getValue(queue<char> postfix){
    stack<bool> s;
    while(!postfix.empty()){
        switch(postfix.front()){
            case 'F':{
                s.push(false);
                break;
            }
            case 'V':{
                s.push(true);
                break;
            }
            case '|':{
                bool t1 = s.top();
                s.pop();
                bool t2 = s.top();
                s.pop();
                s.push(t1||t2);
                break;
            }
            case '&':{
                bool t1 = s.top();
                s.pop();
                bool t2 = s.top();
                s.pop();
                s.push(t1&&t2);
                break;
            }
            case '!':{
                bool t = s.top();
                s.pop();
                s.push(!t);
            }
        }
        postfix.pop();
    }
    return s.top();
}
int main(){
    string s;
    while(cin >> s){
        queue<char> postfix = infix_to_postfix(s);
        cout << getValue(postfix)?'V':'F' << endl;
    }
}