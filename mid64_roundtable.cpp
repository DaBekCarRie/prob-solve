#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> list1,list2;
    int n,a,max=0;
    list<int>::iterator it;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        //list1.push_back(a);
        list2.push_back(a);

    }
    
    for(int i=0;i<n;i++){
        int v=list2.back();
        list2.pop_back();
        list2.push_front(v);
        //cout << v << " " << i << "\n";
        //cout list
        /*cout << "print list2 \n";
        for(it=list2.begin();it!=list2.end();++it){
            cout << *it << " ";
        }
        cout << endl;*/
        /////////////////////////////////////////
        int index=1,count=0;
        for(it=list2.begin();it!=list2.end();++it){
            //cout << *it << " " <<index<<'\n';
            if(*it==index)
                count++;
            index++;
        }
        if(count>max)
            max=count;
    }
    /*//cout list
    
    for(it=list1.begin();it!=list1.end();++it)
        cout << *it << '\n';
        */
    cout << max;

}