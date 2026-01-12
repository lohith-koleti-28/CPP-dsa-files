#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x=0){
        data = x;
        next = NULL;
    }
};

class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head = NULL;
    }
    LinkedList(Node* &ptr){
        head = ptr;
    }
    
    void insertAtTail(int x){
        Node* new_node = new Node (x);
        if(head == NULL){
            head = new_node;
            new_node->next = NULL;
            return;
        }
        Node * temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = NULL;
    }

    void insertAtHead(int x){
        Node *new_node = new Node(x);
        new_node->next = head;
        head = new_node;
    }

    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

void deleteAlternate(Node* &head){
    Node *current = head;
    while(current != NULL && current->next != NULL){
        Node* temp = current->next;
        current->next = current->next->next;
        current = current->next;
        free(temp);
    }
}

void deleteDuplicates(Node* &head){
    Node * current = head;
    while(current != NULL && current->next != NULL){
        if(current->data == current->next->data){
            Node *temp = current->next;//to be deleted
            current->next = current->next->next;
            delete temp;
        }
        else{
            current = current->next;
        }
    }
    return;
}

LinkedList reverseLinkedList(Node* &head){
    LinkedList ans;
    ans.head = NULL;
    Node* current = head;
    while(current != NULL){
        ans.insertAtHead(current->data);
        current = current->next;
    }
    return ans;
}

void revPrint(Node* head){
    if(head == NULL){
        cout<<"NULL";
        return;
    }
    revPrint(head->next);
    cout<<"<-"<<head->data;
}

void analyse(Node* head){
    int i=0;
    Node* current = head;
    while(current != NULL){
        cout<<i<<" "<<current->data<<" Self Adress: "<<current<<" Next adress: "<<current->next<<endl;
        i++;
        current = current->next;
    }
}

Node* reversingLL(Node* &head){
    Node *current = head,*prev = NULL;
    if(head == NULL) return NULL;
    while(current->next != NULL){
        Node *temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
    }
    return current;
}

Node* reversingLLRec(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* temp = reversingLLRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

Node* reversingKLL(Node* &head,int k){
    Node* current = head,*prev = NULL;
    int counter = 0;
    while(current !=NULL && counter < k){
        Node* nextptr = current->next;
        current->next = prev;
        prev = current;
        current = nextptr;
        counter++;
    }
    if(current != NULL){
        Node * new_head = reversingKLL(current,k);
        head->next = new_head;
    }
    return prev;
}

int main(){
    LinkedList l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);
    l.display();
    int k;
    cin >> k;
    l.head = reversingKLL(l.head,k);
    l.display();
}