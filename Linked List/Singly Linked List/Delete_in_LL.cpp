//Deleting in a linked list

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
        next1 = next;
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

//Removing the head of the linked list
Node* removeHead(Node* head){
    if(head == nullptr)return head;
    Node* temp = head;
    head = head -> next;
    delete temp;
    return head;
}

//Removing the tail of the linked list
Node* removeTail(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    
    Node* temp = head;
    while(temp -> next -> next != nullptr){
        temp = temp -> next;
    }
    delete temp -> next;
    temp -> next = nullptr;
    
    return head;
}

//Removing the kth node from the linked list
Node* removeK(Node* head,int k){
    if(head == nullptr)return head;
    if(k == 1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

//Removing the given element from the linked list
Node* removeEl(Node* head,int el){
    if(head == nullptr)return head;
    if(head -> data == el){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){
        if(temp -> data == el){
            prev -> next = prev -> next -> next;
            free(temp);
            break;
        }
        prev = temp;
        temp = temp -> next;
    }
    return head;
}

int main(){

    vector<int>arr = {12,5,8,7};
    Node* head = convertArr2LL(arr);
    
}