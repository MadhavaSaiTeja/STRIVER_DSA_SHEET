#include <bits/stdc++.h>
using namespace std;

//structure for the Node of a linked list
class Node {
    public:
    int data;
    Node *next;

    public:
    Node(int data1,Node* next1){
        data = data1;
        next = next1;
    }
    public:
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

//Length of the linked list
int lengthOfLL(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != nullptr){
        length++;
        temp = temp -> next;
    }
    return length;
}



int main(){

    vector<int>arr = {12,5,8,7};
    //Never ever tamper the head of the linked list
    Node* head = convertArr2LL(arr);
    traverseLL(head);
    cout<<lengthOfLL(head)<<endl;
}