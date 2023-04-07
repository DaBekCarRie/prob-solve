#include<bits/stdc++.h>
using namespace std;


int parent[100100];
int n,m,k;

int find(int now){
	if (parent[now] == now){
		return now;
	}
	return parent[now] = find(parent[now]);
}

int main(){
	cin >> n >> m >> k;
	for(int i=1;i<=n;i++){
		parent[i] = i;
	}
	for (int i=0;i<m;i++){
		int start,end;
		cin >> start >> end;
		start = find(start);
		end = find(end);
		parent[end] = start;
	}
	for (int i=0;i<k;i++){
		int start,end;
		cin >> start >> end;
		start = find(start);
		end = find(end);
		
		if (start == end){
			printf("%d\n",1);
		}else{
			printf("%d\n",0);
		}
		
	}
	
	
}