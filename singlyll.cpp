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


    // destructor 

    ~node(){
        int value=this->data;
        if(this->next=NULL)
{
delete next;
this->next=NULL;    
}    }
};


// insertion in linked list--------------------------------------------------------------------
void insertathead(node *&head, int data)
{
    node *node1 = new node(data);
    node1->next = head;
    head = node1;

}

void insertattail(node *&tail, int d)
{

    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}

// without tail
// node* insertatend(node * head ,int data){
//    node *newnode=new node(data);
//    node*ptr=head;
//    while(ptr->next!=NULL)
// {
//     ptr=ptr->next;
// }
// ptr->next=newnode;
// newnode->next=NULL;
// return head;

// }

void insertinbetween(node*&tail,node *&head, int data, int index)
{
    if(index == 0) {
        insertathead(head, data);
        return;
    }
    node *newnode = new node(data);

    node *ptr = head;

    int i = 0;
    while (index - 1 != i)
    {
        ptr = ptr->next;

        i++;
    }
//inserting at Last Position
    if(ptr -> next == NULL) {
        insertattail(tail,data);
        return ;
    }
    node *ptr1 = ptr->next;
    newnode->next = ptr->next;
    ptr->next = newnode;

   
}
// deletion in linked list -----------------------------------------------------------------

void deletenode(int position ,node*head){
    if(position==1){
    node *temp = head;
    head = head->next;
    temp->next=NULL;
    delete temp;
    // as we have allocate the memeory in heap so we have to construct a destructor to deallocate the memory 
    }
    else{
        node *curr=head;
         node*prev=NULL;
         int cnt=1;
         while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
         }
          prev -> next = curr -> next;
        curr -> next  = NULL;   //due to our code of destruvtor we have delete connection of the deleted node to next object  that we are going to detete
        delete curr;  


    }
    

}





void printll(node * &head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{

    // insertion in linked list
    node *node1 = new node(12);

    node *head = node1;
    node *tail = node1;

    insertathead(head, 13);
    insertathead(head, 19);
    // insertatend(node1,43);
    insertattail(tail, 43);
    insertinbetween(tail,head,32,2);
    // printll(node1);

    // deletion in linked list
    deletenode(2,head);
    printll(head);





}
