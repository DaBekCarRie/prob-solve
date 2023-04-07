#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> list1;
    int m,a;
    char c;
    cin >>m;
    list<int>::iterator it;
    for(int i=0;i<m;i++){
        cin >> c >> a;
        list<int>::iterator it = list1.begin();

        if(c=='I'){
            if(list1.size()==0)
                list1.assign(1,a);
            else
                list1.insert(it,a);
        }

        else if(c=='D'){
            a=a-1;
            int size=list1.size();
            advance(it,a);
            //cout << list1.size() << '\n';
            if(size==1 && a==0){
                list1.clear();
            }
            else{
            if(a<list1.size())
                list1.erase(it);
                
            }
        }
        else if(c=='A'){
            list1.push_back(a);
        }
    }
    it=list1.begin();
    for(;it!=list1.end();++it)
        cout << *it << '\n';
    cout << endl;

    return 0;
}