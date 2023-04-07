#include<iostream>
#include<string>
#include<string.h>
#include<list>

using namespace std;
int main (){
    string word;
    list<int> ic;
    int n,a;
    list<int>:: iterator it;
    cin >>n;
    for(int i=0;i<n;i++){
        cin >>word;
        int size=ic.size();
        if(word=="ri"){
            cin >>a;
            ic.push_back(a);
        }
        else if(word=="li"){
            cin >>a;
            ic.push_front(a);
        }
        else if(word=="lr" && size!=0){
            int value=ic.front();
            ic.pop_front();
            ic.push_back(value);
        }
        else if(word=="rr"&& size!=0){
            int value=ic.back();
            ic.pop_back();
            ic.push_front(value);
        }
    
    }
    for(list<int>:: iterator it=ic.begin();
    it!=ic.end();++it){
        cout << *it << '\n';
    }
}