// q1
#include <iostream>
using namespace std;

int top = -1;
int stackk[5];

bool isempty(){
    return (top == -1);
}

bool isfull(){
    return (top == 4);
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
    int choice, value;
    
    while(true) {
        cout << "1 push \n2 pop \n3 isempty \n4 isfull \n5 display \n6 peek \n7 exit\n" << endl;
        cin >> choice;

        switch(choice){
            case 1:
                cout << "enter value to push : " << endl;
                cin >> value;
                push(value);
                break;
            
            case 2:
                pop();
                break;
            
            case 3:
                cout << (isempty() ? "stackk is empty\n" : "stackk is not empty\n");
                break;
            
            case 4:
                cout << (isfull() ? "stackk is full\n" : "stackk is not full\n");
                break;
            
            case 5:
                display();
                break;
            
            case 6: {
                int topValue = peek();
                if(topValue != -1)
                    cout << "Top element: " << topValue << endl;
                break;
            }
            
            case 7:
                cout << "Exiting program.\n";
                return 0;
            
            default:
                cout << "Invalid choice! Try again.\n";
                break;
        }
    }

    return 0;
}