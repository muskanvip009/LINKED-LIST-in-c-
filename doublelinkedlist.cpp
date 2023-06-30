#include <iostream>
using namespace std;


class node{
    public:
    int data;
    node*prev;
    node*next;
    node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~node(){
        int val=this->data;
        if(next!=NULL){
            delete next;
            next=NULL;
        }
    }
};


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


void insertathead(node*&head,node*&tail,int data){
    if(head==NULL){
        node*temp=new node(data);
        tail=temp;
        head=temp;
    }
    
    node *node1=new node(data);
    head->prev=node1;
    node1->next=head;  
    node1->prev=NULL;
    head=node1;

}


void insertatend(node*&head,node*&tail,int data){
    if(tail==NULL){
        node*temp=new node(data);
        tail=temp;
        head=temp;  
    }
    node *temp=new node(data);
    tail->next=temp;
    temp->prev=tail;
    tail=temp;


}
void insertatposition(node *&head,node*&tail,int index,int data){
     if(index == 0) {
        insertathead(head,tail, data);
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
    if(ptr -> next == NULL) {
        insertatend(tail,tail,data);
        return ;
    }
    node *ptr1 = ptr->next;

    newnode->next = ptr->next;
    newnode->prev=ptr;
    ptr->next = newnode;
    ptr1->prev=newnode;

}
int getlength(node *head){
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        
    }
    node *temp = head;
    int len=0;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;printll(head);
    }
    return len;
}



void deletenode(int position ,node*head){
    if(position==1){
        node *temp=head;
    temp->next->prev=NULL;
    head=temp->next;
    
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
        curr->prev=NULL;
        prev -> next = curr -> next;
        

        curr -> next  = NULL;   //due to our code of destruvtor we have delete connection of the deleted node to next object  that we are going to detete
        delete curr;  


    }
    

}
int main(){
    node* head=NULL;
    node* tail=NULL;
insertathead(head,tail,11);
insertathead(head,tail,19);
insertathead(head,tail,11);
insertatend(head,tail,12);
insertatposition(head,tail,3,20);
insertatposition(head,tail,6,22);
// printll(head);

deletenode(7,head);
printll(head);
} 
