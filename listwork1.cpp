#include<iostream>
#include<list>

using namespace std;

int main(){
    list<int> list1;
    int m,a;
    char c;
    cin >> m;
    for(int i =0;i<m;i++){
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
        
    }
    for (list<int>::iterator i = list1.begin();
         i != list1.end();
         i++)
        cout << *i << "\n";
    cout << endl;
    return 0;

}