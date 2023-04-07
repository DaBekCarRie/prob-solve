#include<iostream>
#include<cmath>
using namespace std;
int check(int faceing,int direction){
    int count =0; int turn;
    while(1){
        if(faceing==direction)
            break;
        faceing++;
        faceing=faceing%4;
        count++;
    }
    //cout << "check turn ";
    if(count==1){
        cout << "R";turn=1;
    }
    else if(count==2){
        cout << "RR";turn=2;
    }
    else if(count==3){
        cout << "RRR";turn=3;
    }
    else
        turn=0;
    //cout << ' ' << turn;
    return turn;
}
int main(){
    int sum=0,x=0,y=0,turn=0;
    char word;
    word=getchar();
    while(word!='\n'){
        turn=turn%4;
        switch(word){
            case 'N': turn+=check(turn,0);cout << "F";break;
            case 'S': turn+=check(turn,2);cout << "F";break;
            case 'E': turn+=check(turn,1);cout << "F";break;
            case 'W': turn+=check(turn,3);cout << "F";break;
            case 'Z': turn=0;cout << "Z";break;
        }
       //cout << '\n';
        word=getchar();
    }
}