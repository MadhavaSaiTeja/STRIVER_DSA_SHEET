//Inserting in LL

#include <bits/stdc++.h>
using namespace std;

//structure for the Node of a linked list
class Node {
    public:
    int data;
    Node *next;

    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

//Converting an Array into a linked list
Node* convertArr2LL(vector<int>&arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        mover -> next = temp;
        mover = temp;
    }
    return head;
}

//Traversing in the linked list
void traverseLL(Node* head){
    Node* temp = head;
    while(temp){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

//Inserting at the head of the linked list
Node* insertHead(Node* head,int val){
    return new Node(val,head);
}

//Inserting at the tail of the linked list
Node* insertTail(Node* head,int val){
    if(head == nullptr){
        return new Node(val);
    }
    Node* temp = head;
    while(temp -> next){
        temp = temp -> next;
    }
    temp -> next = new Node(val);
    return head;
}

//Inserting at a particular position in the linked list
Node* insertPosition(Node* head,int el,int k) {
    if (head == nullptr) {
        if (k == 1) {
            return new Node(el);
        } else {
            return head;
        }
    }
    if (k == 1) {
        return new Node(el, head);
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != nullptr) {
        cnt++;
        if (cnt == (k - 1)) {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

//Inserting before a particular value in the linked list
Node* insertBeforeValue(Node* head,int el,int val) {
    if (head == nullptr) {
        return nullptr;
    }
    if (head->data == val) {
        return new Node(el, head);
    }
    Node *temp = head;
    while (temp->next != nullptr) {
        if (temp->next->data == val) {
            Node *x = new Node(el, temp->next);
            temp->next = x;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main(){

    vector<int>arr = {12,5,8,7};
    //Never ever tamper the head of the linked list
    Node* head = convertArr2LL(arr);
    traverseLL(head);

}


