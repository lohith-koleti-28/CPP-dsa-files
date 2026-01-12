#include<iostream>
#include<cassert>
using namespace std;

class Node{
    public:
    int data;
    Node* prev , *next;

    Node(int x = 0){
        prev = NULL;
        next = NULL;
        data = x;
    }
    ~Node(){
        delete this;
    }
};

class doublyLinkedList{
    public:
    Node* head;
    Node* tail;

    doublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    int length(){
        int ans = 0;
        Node* curr = head;
        while(curr != NULL){
            ans++;
        }
        return ans;
    }

    void insertAtHead(int x){
        Node* new_node = new Node(x);
        if(head == NULL){
            head = new_node;
            tail = new_node;
            return; 
        }
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }   

    void insertAtTail(int x){
        Node* new_node = new Node(x);
        if(tail == NULL){
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    }

    void insertAtKthPos(int k , int x){
        if(k == 1){
            insertAtHead(x);
            return;
        }
        Node* new_node = new Node(x);
        Node* temp = head;
        while(k-2){
            temp = temp->next;
            k--;
        }
        if(temp->next == NULL){
            temp->next = new_node;
            new_node->prev = temp;
            tail = new_node;
            return;
        }
        //Now temp points to k-1th node
        Node* after = temp->next;
        //Aligning next pointers
        temp->next = new_node;
        new_node->next = after;
        //prev pointers
        new_node->prev = temp;
        after->prev = new_node;
    }

    void display(){
        Node* temp = head;
        cout<<"NULL->";
        while(temp != NULL){
            cout<<temp->data<<"<->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }

    void deleteHead(){

        //Use free() instead of delete
        //as delete leads to seg fault
        if(head == NULL){
            return;
        }
        else if(head->next == NULL){
            free(head);
            head = NULL;
            tail = NULL;
            return;
        }
        Node* temp = head;
        head = temp->next;
        head->prev = NULL;
        free(temp);
        temp  = NULL;
    }

    void deleteTail(){
        if(tail == NULL){
            return;
        }
        else if(tail->prev == NULL){
            free(tail);
            tail = NULL;
            head = NULL;
            return;
        }
        Node* temp = tail;
        tail = temp->prev;
        tail->next = NULL;
        free(temp);
    }

    void deleteKthPos(int k){
        if(k == 1){
            deleteHead();
            return;
        }
        Node* curr = head;
        while(k-2){
            curr = curr->next;
            k--;
        }
        //curr is on k-1th node
        Node* del = curr->next;
        Node* after = del->next;
        curr->next = after;
        if(after != NULL){
            after->prev = curr;
        }
        free(del);
    }

};

void reverseDLL(Node* &head, Node* &tail){
    if(head == tail){
        return;
    }
    else if(head == NULL){
        return;
    }
    Node* curr = head;
    while(curr != NULL){
        Node* nextptr = curr->next;
        curr->next = curr->prev;
        curr->prev = nextptr;
        curr = nextptr;
    }
    Node* temp = head;
    head = tail;
    tail = temp;
}

bool isPalindrome(Node* head, Node* tail){

    if(head == NULL){
        return true;
    }
    else if(head == tail){
        return true;
    }

    while((head != tail) && (tail != head->prev)){
        if(head->data != tail->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }

    return true;
}

int main(){
    doublyLinkedList dll;
    dll.insertAtHead(1);
    dll.insertAtTail(2);
    dll.insertAtTail(3);
    dll.insertAtTail(4);
    dll.insertAtTail(1);
    dll.display();
    cout<<isPalindrome(dll.head,dll.tail)<<"\n";
}