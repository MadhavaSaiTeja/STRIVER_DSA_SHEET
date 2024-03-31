#include <bits/stdc++.h>
using namespace std;

class Heap{
public:
    vector<int>arr;

    int parent(int index){
        return (index-1)/2;
    }

    int left(int index){
        return (2*index)+1;
    }

    int right(int index){
        return (2*index)+2;
    }

    void insert(int data){
        arr.push_back(data);
        int index = arr.size()-1;
        upheap(index);
    }

    void upheap(int index){
        if(index == 0){
            return;
        }
        int p = parent(index);
        if(arr[p] > arr[index]){
            swap(arr[p], arr[index]);
            upheap(p);
        }
    }

    void remove(){
        if(arr.size() == 0){
            //cout<<"nothing to delete"<<endl;
            return;
        }
        swap(arr[0], arr[arr.size()-1]);
        arr.pop_back();
        downheap(0);
    }

    void downheap(int index){
        int l = left(index);
        int r = right(index);
        int min = index;
        if(l < arr.size() && arr[l] < arr[min]){
            min = l;
        }
        if(r < arr.size() && arr[r] < arr[min]){
            min = r;
        }
        if(min != index){
            swap(arr[min], arr[index]);
            downheap(min);
        }
    }

    void print(){
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    vector<int> heapsort(){
        vector<int>sorted;
        while(arr.size() > 0){
            sorted.push_back(arr[0]);
            remove();
        }
        return sorted;
    }

};

int main(){

    Heap h;
    h.insert(34);
    h.insert(45);
    h.insert(22);
    h.insert(89);
    h.insert(76);

    //Performing heap sort
    vector<int>sorted = h.heapsort();
    for(int i=0; i<sorted.size(); i++){
        cout<<sorted[i]<<" ";
    }
    h.remove();
    h.remove();
    h.insert(23);
    h.remove();
    //Printing the heap array
    h.print();

    return 0;

}