#include<iostream>
using namespace std;

class node{
public:
    int data;
    node *next;
    node(){
        data = 0;
        next = nullptr;
    }
    node(int dat){
        data = dat;
        next = nullptr;
    }
};

class linkedlist{
    node *head;
public:
    linkedlist(){
        head = nullptr;
    }
    ~linkedlist(){
    while(head!=nullptr) deletehead();
}
    void display(){
        node *temp = head;
        if(head==nullptr){
            cout << "empty list!" << endl;
            return;
        }
        while(temp!=nullptr){
            cout << temp->data << " ";
            temp=temp->next;
        }
        cout << endl;
    }
    void insertathead(int data){
        node *temp = new node(data);
        temp->next = head;
        head = temp;
    }
    void insertatend(int data){
        node *temp = new node(data);
        if(head==nullptr){
            head = temp;
            return;
        }
        node *ptr=head;
        while(ptr->next!=nullptr) ptr=ptr->next;
        ptr->next=temp;
    }
    void insertbefore(int val,int data){
        if(head==nullptr) return;
        if(head->data==val){
            insertathead(data);
            return;
        }
        node *ptr=head;
        while(ptr->next!=nullptr && ptr->next->data!=val) ptr=ptr->next;
        if(ptr->next==nullptr) return;
        node *temp=new node(data);
        temp->next=ptr->next;
        ptr->next=temp;
    }
    void insertafter(int val,int data){
        node *ptr=head;
        while(ptr!=nullptr && ptr->data!=val) ptr=ptr->next;
        if(ptr==nullptr) return;
        node *temp=new node(data);
        temp->next=ptr->next;
        ptr->next=temp;
    }
    void deletehead(){
        if(head==nullptr) return;
        node *temp=head;
        head=head->next;
        delete temp;
    }
    void deleteend(){
        if(head==nullptr) return;
        if(head->next == nullptr){
            delete head;
            head=nullptr;
            return;
        }
        node *ptr=head;
        while(ptr->next->next!=nullptr) ptr=ptr->next;
        delete ptr->next;
        ptr->next=nullptr;
    }
    void deletenode(int val){
        if(head==nullptr) return;
        if(head->data==val){
            deletehead();
            return;
        }
        node *ptr=head;
        while(ptr->next!=nullptr && ptr->next->data!=val) ptr=ptr->next;
        if(ptr->next==nullptr) return;
        node *temp=ptr->next;
        ptr->next=ptr->next->next;
        delete temp;
    }
    void search(int val){
        node *ptr=head;
        int pos=1;
        while(ptr!=nullptr){
            if(ptr->data==val){
                cout<<"found at position "<<pos<<endl;
                return;
            }
            ptr=ptr->next;
            pos++;
        }
        cout<<"not found"<<endl;
    }
};

int main(){
    linkedlist l;
    int ch,val,x;
    do{
        cout<<"\n1.Insert at head\n2.Insert at end\n3.Insert before\n4.Insert after\n5.Delete head\n6.Delete end\n7.Delete node\n8.Search\n9.Display\n0.Exit\n";
        cin>>ch;
        switch(ch){
            case 1: cin>>val; l.insertathead(val); break;
            case 2: cin>>val; l.insertatend(val); break;
            case 3: cin>>x>>val; l.insertbefore(x,val); break;
            case 4: cin>>x>>val; l.insertafter(x,val); break;
            case 5: l.deletehead(); break;
            case 6: l.deleteend(); break;
            case 7: cin>>val; l.deletenode(val); break;
            case 8: cin>>val; l.search(val); break;
            case 9: l.display(); break;
        }
    }while(ch!=0);
    return 0;
}