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

Node* kRotations(Node* &head, int k){
    //O(n) = k * length of LL
    if(head == NULL || head->next == NULL){
        return head;
    }
    k = k % (getLength(head));
    while(k--){
        Node* curr = head;
        while(curr->next->next != NULL){
            curr = curr->next;
        }
        //Now curr has second last pos
        curr->next->next = head;
        head = curr->next;
        curr->next = NULL;
    }
    return head;
}

Node* kRotations2(Node* &head, int k){
    if(head== NULL || head->next == NULL){
        return head;
    }
    int l = getLength(head);
    Node* ptr2 = head;
    k %= l;
    int dec = l - k - 1;
    while(dec--){
        ptr2 = ptr2->next;
    }
    Node* ptr1 = ptr2->next; 
    ptr2->next = NULL;
    Node* new_head = ptr1;
    while(ptr1->next){
        ptr1 = ptr1->next;
    }
    ptr1->next = head;
    head = new_head;
    return head;
}

Node* oddThenEven(Node* &head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* second = head->next;
    Node* od = head , *ev = head->next;
    while(od->next && od->next->next){
        od->next = od->next->next;
        od = od->next;
        ev->next = ev->next->next;
        ev = ev->next;
    }
    od->next = second;
    return head;
}

int main(){
    LinkedList l1;
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtTail(4);
    l1.insertAtTail(5);
    // l1.insertAtTail(6);
    // l1.insertAtTail(4);
    // l1.display();
    // int k;
    // cin >> k;
    // // l1.head = kRotations(l1.head,k);
    // l1.head = kRotations2(l1.head,k);
    l1.display();
    oddThenEven(l1.head);
    l1.display();
}

