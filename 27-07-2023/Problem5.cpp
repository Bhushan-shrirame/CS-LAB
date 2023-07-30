#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int x) {
        data = x;
    }
};

class Stack{
    node* top;
    public:
    Stack(){
        top = NULL;
    }
    int show_top() {return top->data;}
    void push(int x){
        node* temp = new node(x);
        if(top){
            temp->next = top;
            top = temp;
        }
        else{
            temp->next = NULL;
            top = temp;
        }
    }

    int pop(){
        int x = top->data;
        if(top->next){
            node* temp = top;
            top = top->next;
            free(temp);  
        }else{
            free(top);
        }
        return x;
    }
};



int main(){
    Stack s;
    string postfix_expression;
    while(getline(cin,postfix_expression,' ')){
        if(!postfix_expression.compare("+")){
            int y = s.pop();
            int x = s.pop();
            int z = x+y;
            s.push(x+y);
        }else if(!postfix_expression.compare("-")){
            int y = s.pop();
            int x = s.pop();
            s.push(x-y);            
        }else if(!postfix_expression.compare("/")){
            int y = s.pop();
            int x = s.pop();
            s.push(x/y);
        }else if(!postfix_expression.compare("*")){
            int y = s.pop();
            int x = s.pop();
            s.push(x*y);
        }else if(!postfix_expression.compare("%")){
            int y = s.pop();
            int x = s.pop();
            s.push(x%y);
        }else{
            int x = stoi(postfix_expression);
            s.push(x);
        }
    }
    cout<<s.pop();
}