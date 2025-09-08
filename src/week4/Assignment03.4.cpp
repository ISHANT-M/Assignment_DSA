// q4
#include <iostream>
#include <cctype> // for isalnum()
using namespace std;

int top = -1;
char stackk[50];

bool isempty(){
    return (top == -1);
}

bool isfull(){
    return (top == 49);
}

void push(char value){
    if(isfull()){
        cout << "stackk overflow! \n";
    }
    else{
        stackk[++top] = value;
    }
}

char pop(){
    if(isempty()){
        cout << "stackk underflow! \n";
        return -1;
    }
    else{
        return stackk[top--];
    }
}

char peek(){
    if(isempty()){
        return -1;
    }
    else{
        return stackk[top];
    }
}


int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}

bool isRightAssociative(char op) {
    return (op == '^'); // only ^ is right associative
}

int main() {
    string infix, postfix = "";
    cout << "Enter infix expression: ";
    getline(cin, infix);

    for(int i = 0; i < (int)infix.length(); i++) {
        char ch = infix[i];

        // 1. If operand → add to postfix
        if(isalnum(ch)) {
            postfix += ch;
        }
        // 2. If '(' → push
        else if(ch == '(') {
            push(ch);
        }
        // 3. If ')' → pop until '('
        else if(ch == ')') {
            while(!isempty() && peek() != '(') {
                postfix += pop();
            }
            pop(); // remove '('
        }
        // 4. If operator → check precedence
        else {
            while(!isempty() && peek() != '(' && 
                  (precedence(peek()) > precedence(ch) || 
                   (precedence(peek()) == precedence(ch) && !isRightAssociative(ch)))) {
                postfix += pop();
            }
            push(ch);
        }
    }

    // 5. Pop remaining operators
    while(!isempty()) {
        postfix += pop();
    }

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}