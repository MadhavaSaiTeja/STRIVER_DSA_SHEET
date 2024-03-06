#include <bits/stdc++.h>
using namespace std;

#define ll long long 

class KarpRabin{
    public:
    int PRIME = 101;

    ll calculateHash(string str){
        ll hash = 0;
        for(int i=0;i<str.length();i++){
            hash += (str[i] * pow(PRIME,i));
        }
        return hash;
    }

    ll updateHash(ll prevHash,char oldChar,char newChar,int patternLength){
        ll newHash = (prevHash - oldChar) / PRIME;
        newHash += (newChar * pow(PRIME,patternLength-1));
        return newHash;
    }

    void search(string text,string pattern){
        int n = text.length();
        int m = pattern.length();
        ll patternHash = calculateHash(pattern);
        ll textHash = calculateHash(text.substr(0,m));
        for(int i=0;i<=n-m;i++){
            if(textHash == patternHash){
                if(text.substr(i,m) == pattern){
                    cout << "Pattern found at index " << i << endl;
                }
            }
            if(i < n-m){
                textHash = updateHash(textHash,text[i],text[i+m],m);
            }
        }
    }
};

int main(){

    KarpRabin karpRabin;
    string text = "AABAACAADAABAABA";
    string pattern = "AABA";
    karpRabin.search(text,pattern);
    return 0;

}