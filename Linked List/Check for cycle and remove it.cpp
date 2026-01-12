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

int getLength(Node* head){
    int ans = 0;
    while(head != NULL){
        head = head->next;
        ans++;
    }
    return ans;
}

Node* removeHead(Node* &head){
    if(head == NULL){
        return head;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    return head;
}

bool cyclicLinkedList(Node* &head){
    if(head == NULL){
        return false;
    }
    Node* s = head;
    Node* f = head;
    while(f != NULL && f->next != NULL){
        s = s->next;
        f = f->next->next;
        if(f == s){
            return true;
        }
    }
    return false;
}

Node* removeCycle(Node* &head){
    if(head == NULL){
        return head;
    }
    Node* s = head;
    Node* f = head;
    bool found = false;
    while(f != NULL && f->next != NULL){
        s = s->next;
        f = f->next->next;
        if(f == s){
            found = true;
            break;
        }
    }
    if(!found){
        return head;
    }
    f = head;
    while(f->next != s->next){
        f = f->next;
        s = s->next;
    }
    s->next = NULL;
    return head;

}

int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(6);
    // l1.head->next->next->next->next->next->next = l1.head->next->next;
    // l1.display();
    cout<<cyclicLinkedList(l1.head)<<endl;
    removeCycle(l1.head);
    l1.display();
}

