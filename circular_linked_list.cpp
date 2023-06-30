#include <iostream>
using namespace std;


class node
{

public:
    int data;
    node *next;

    node(int data)
    { // constructor

        this->data = data;
        this->next = NULL;
    }
    ~node() {
        int value = this->data;
        if(this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }


};



void insertNode(node*&tail,int element,int data){
    if(tail==NULL){      
        node *newnode=new node(data);
       tail=newnode;
        newnode->next=newnode;
         
    }
    else{
    node *ptr=tail;
   
    while(ptr->data!=element){
        ptr=ptr->next;
    }
    node *newnode=new node(data);
    newnode->next=ptr->next;
    ptr->next=newnode;
    }
}


void deletion(node*&tail,int element){
    if(tail==NULL){
        cout<<"no element"<<endl;
    }
    // for deleting one node

    node *ptr=tail->next;
    node*ptr1=ptr->next;
    while(ptr1->data!=element){
        ptr=ptr->next;
    }
    // ptr1 is to be deleted
    if(ptr==ptr1){
        tail=NULL;
    }
    ptr->next=ptr1->next;
    ptr1->next=NULL;
    delete(ptr1);


}
void printll(node*& tail) {
    node* ptr = tail;
    if (tail == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    do {
        cout << ptr->data << endl;
        ptr = ptr->next;
    } while (tail != ptr);
}

int main(){
node *tail=NULL;
insertNode(tail, 5, 3); 
/* insertNode(tail, 5, 3); 
   insertNode(tail, 3, 5);
    insertNode(tail, 5, 7);
    insertNode(tail, 5, 2);
    printll(tail);
*/


deletion(tail,3);
printll(tail);

}
