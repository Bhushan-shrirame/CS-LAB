#include<bits/stdc++.h>
using namespace std;
class custom_stack{
    int arr[100];
    int top_index;
    int size;
    public:
    custom_stack(){
        size = 0;
        top_index = 99;
    }

    void push(int x){
        if(size == 99){
            cout<<"Stack Full";
            return;
        }
        if(top_index == 0){
            top_index = 100;
        }
        top_index--;
        size++;
        arr[top_index] = x;
    }
    int top(){
        return arr[top_index];
    }
    int pop(){
        if(size == 0){
            cout<<"Stack Empty";
            return -1;
        }
        int y = arr[top_index];
        if(top_index == 99){
            top_index = -1;
        }
        top_index++;
        size--;
        return y;
    }

};
int main(){
    custom_stack s;
    string inp;
    getline(cin,inp);
    for(int i=0;i<inp.size();i++)
    {
        if(inp[i]==' ')
            continue;
        else if(isdigit(inp[i]))
        {
            int num=0;
            while(isdigit(inp[i]))
            {
                num=num*10+(int)(inp[i]-'0');
                i++;
            }
            i--;
            s.push(num);
        }
        else{
            if(inp[i] == '+'){
                int t1 = s.pop();
                int t2 = s.pop();
                s.push(t2+t1);
            }else if(inp[i] == '-'){
                int t1 = s.pop();
                int t2 = s.pop();
                s.push(t2-t1);
            }else if(inp[i] == '/'){
                int t1 = s.pop();
                int t2 = s.pop();
                s.push(t2/t1);
            }else if(inp[i] == '*'){
                int t1 = s.pop();
                int t2 = s.pop();
                s.push(t2*t1);
            }else if(inp[i] == '%'){
                int t1 = s.pop();
                int t2 = s.pop();
                s.push(t2%t1);
            }else continue;
        }
    }
    cout<<s.pop();
}