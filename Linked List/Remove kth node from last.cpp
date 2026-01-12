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

Node* removeKthNode(Node* &head,int k){
    //Traverses the list 2 times
    //Using lenght of LinkedList
    int l = getLength(head);
    int dec = l - k - 1;
    if(dec <0){
        return removeHead(head);
    }
    Node* current = head;
    while(dec-- && current != NULL ){
        current = current->next;
    }
    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
    return head;
}

Node* removeKthNode2(Node* head,int k){
    //Some bug here for k = length of list
    //Two pointer approach
    //Implicit assumption that k is in its limits
    //i.e. 1<= k<= length
    //Single traversal of list
    Node* ptr1 = head,*ptr2 = head;
    while(k--){
        ptr2 = ptr2->next;
        //if k is equal to length
        if(ptr2 == NULL){
            return removeHead(head);
        }
    }
    while(ptr2->next != NULL){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    Node* temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    delete temp;
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
    l1.display();
    int k;
    cin >> k;
    removeKthNode(l1.head,k);
    l1.display();
    LinkedList l2;
    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(3);
    l2.insertAtTail(4);
    l2.insertAtTail(5);
    l2.insertAtTail(6);
    removeKthNode2(l2.head,k);
    l2.display();
}

