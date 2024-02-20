#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1,Node* next1,Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }

};

Node* convertArr2DLL(vector<int> arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev->back = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* deleteHead(Node* head){
    
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* prev = head;
    head = head->next;

    head -> back = nullptr;
    prev -> next = nullptr;

    delete prev;
    return head;
}

Node* deleteTail(Node* head){
    if(head == nullptr || head->next == nullptr){
        return nullptr;
    }

    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }

    Node* newTail = tail->back;
    newTail->next = nullptr;
    tail->back = nullptr;
    delete tail;
    return head;   
}

Node* removeKthElement(Node* head,int k){
    if(head == nullptr){
        return nullptr;
    }
    int cnt = 0;
    Node* kNode = head;
    while(kNode != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        kNode = kNode->next;
    }
    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == nullptr && front == nullptr){
        return nullptr;
    }
    else if(prev == nullptr){
        return deleteHead(head);
    }
    else if(front == nullptr){
        return deleteTail(head);
    }
    prev -> next = front;
    front -> back = prev;

    kNode -> next = nullptr;
    kNode -> back = nullptr;
    delete kNode;
    return head;
}

void deleteNode(Node* temp){
    Node* prev = temp->back;
    Node* front = temp -> next;

    if(front == nullptr){
        prev -> next = nullptr;
        temp -> back = nullptr;
        free(temp);
        return;
    }
    prev -> next = front;
    front -> back = prev;

    temp-> next = temp -> back = nullptr;
    free(temp);    
}

Node* insertBeforeHead(Node* head,int val){
    Node* newHead = new Node(val,head,nullptr);
    head -> back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head,int val){
    if(head -> next == nullptr){
        return insertBeforeHead(head,val);
    }
    Node* tail = head;
    while(tail->next != nullptr){
        tail = tail->next;
    }
    Node* prev = tail -> back;
    Node* newNode = new Node(val,tail,prev);
    prev -> next = newNode;
    tail -> back = newNode;
    return head;
}

Node* insertBeforeKthElement(Node* head,int k,int val){
    if(k == 1){
        return insertBeforeHead(head,val);
    }
    Node* temp = head;
    int cnt = 0;
    while(temp != nullptr){
        cnt++;
        if(cnt == k){
            break;
        }
        temp = temp->next;
    }
    Node* prev = temp -> back;
    Node* newNode = new Node(val,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;
    return head;
}

void insertBeforeNode(Node* temp,int val){
    Node* prev = temp -> back;
    Node* newNode = new Node(val,temp,prev);
    prev -> next = newNode;
    temp -> back = newNode;
}

int main(){

    vector<int> arr = {12,5,8,7};
    Node* head = convertArr2DLL(arr);
    print(head);
    return 0;
}