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

bool operator==(LinkedList l1,LinkedList l2){
    bool ans = true;
    Node* c1 = l1.head,*c2 = l2.head;
    while(c1 == NULL && c2 == NULL){
        if(c1->data != c2->data){
            ans = false;
            break;
        }
        c1 = c1->next;
        c2 = c2->next;
    }
    if(c1 != NULL || c2 != NULL){
            return false;
        }
    return ans;
}

int main(){
    LinkedList l1,l2;
    int a , b;
    cin >> a;
    int x;
    while(a--){
        cin >> x;
        l1.insertAtTail(x);
    }
    cin >> b;
    while(b--){
        cin >> x;
        l2.insertAtTail(x);
    }
    l1.display();
    l2.display();
    if(l1 == l2){
        cout<<"Equal\n";
    }
    else cout<<"Not Equal\n";
}

