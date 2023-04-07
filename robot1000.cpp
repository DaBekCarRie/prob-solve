#include<iostream>
using namespace std;
int main(){
    int sum=0,x=0,y=0;
    char word;
    do{
        word=getchar();
        if(word=='\n'){
            break;
        }
        switch(word){
        case 'N':
            y+=1;
            break;
        case 'S':
            y-=1;
            break;
        case 'W':
            x-=1;
            break;
        case 'E':
            x+=1;
            break;
        case 'Z':
            x=0;y=0;
            break;
        }
    }while(word!='\n');
    cout << x << ' ' << y;
    return 0;
}