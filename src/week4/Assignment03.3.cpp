//q3
#include <iostream>
using namespace std;

int top = -1;
char stackk[50];

bool isempty(){
    return (top == -1);
}

bool isfull(){
    return (top == 49);
}

void push(int value){
    if(isfull()){
        cout << "stackk overflow! \n";
    }
    else{
        stackk[++top] = value;
    }
}

int pop(){
    if(isempty()){
        cout << "stackk underflow! \n";
        return -1;
    }
    else{
        cout << "Popped element: " << stackk[top] << endl;
        return stackk[top--];
    }
}

int peek(){
    if(isempty()){
        cout << "stackk underflow! \n";
        return -1;
    }
    else{
        return stackk[top];
    }
}

void display(){
    if(isempty()){
        cout << "stackk underflow! \n";
    }
    else{
        cout << "stackk elements : \n";
        for(int i = top; i >= 0; i--){
            cout << stackk[i] <<"   ";
        }
        cout << endl;
    }
}

int main() {

    cout << "do not Try programiz.pro \n\n\n";
    string input;
    cout << "Enter a string (max " << 50 << " chars): ";
    getline(cin, input);

    for (int i = 0; i < (int)input.length(); i++) {
        if(input[i] == '(') push(input[i]);
        else if(input[i] == ')') {
            if(isempty()) {
                cout << "unbalanced \n";
                return 0;
            }
            pop();
        }
    }
    if (isempty()) {
        cout << "balanced \n";
    }
    else{
        cout << "unbalanced \n";
    }
    return 0;
}