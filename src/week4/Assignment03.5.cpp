// q5
#include <iostream>
#include <cctype>
#include <cmath>  // for pow()
using namespace std;

int top = -1;
int stackk[50]; 

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
        return stackk[top--];
    }
}

int peek(){
    if(isempty()){
        return -1;
    }
    else{
        return stackk[top];
    }
}

int main() {
    string postfix;
    cout << "Enter postfix expression (operands as single digits): ";
    getline(cin, postfix);

    for(int i = 0; i < (int)postfix.length(); i++) {
        char ch = postfix[i];

        // 1. If operand (digit) → push as int
        if(isdigit(ch)) {
            push(ch - '0');  // convert char to int
        }
        // 2. If operator → pop 2 and apply
        else {
            int a = pop();  // second operand
            int b = pop();  // first operand
            int result;

            switch(ch) {
                case '+': result = b + a; break;
                case '-': result = b - a; break;
                case '*': result = b * a; break;
                case '/': result = b / a; break;
                case '^': result = pow(b, a); break;
                default: 
                    cout << "Invalid operator: " << ch << endl;
                    return 0;
            }
            push(result);
        }
    }

    cout << "Result of postfix evaluation: " << pop() << endl;

    return 0;
}