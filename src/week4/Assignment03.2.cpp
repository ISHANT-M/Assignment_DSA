//q2
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
char stackk[MAX_SIZE];
int top = -1;

bool isempty() {
    return (top == -1);
}

bool isfull() {
    return (top == MAX_SIZE - 1);
}

void push(char c) {
    if (isfull()) {
        cout << "stackk overflow! Cannot push '" << c << "'\n";
    } else {
        stackk[++top] = c;
    }
}

char pop() {
    if (isempty()) {
        cout << "stackk underflow!\n";
        return '\0';  
    } else {
        return stackk[top--];
    }
}

int main() {
    string input;
    cout << "Enter a string (max " << MAX_SIZE << " chars): ";
    getline(cin, input);

    
    for (int i = 0; i < (int)input.length(); i++) {
        push(input[i]);
    }

    cout << "Reversed string: ";

    
    while (!isempty()) {
        cout << pop();
    }
    cout << endl;

    return 0;
}

