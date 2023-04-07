#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    cin >> n;
    vector<int> lis;
    vector<int> last(n+1,0);
    int len = 0, endpos = -1;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
            last[i] = len;
            len++;
            endpos = i;
        } else {
            int j = it - lis.begin() + 1;
            last[i] = last[j-1];
            lis[j-1] = x;
        }
    }
    cout << len << "\n";
    vector<int> ans;
    while (endpos > 0) {
        ans.push_back(endpos);
        endpos = last[endpos];
    }
    for (int i=len-1;i>=0;i--){
        cout << lis[i] << " ";
    }
}