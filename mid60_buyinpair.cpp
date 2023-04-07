#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long int countPairs(vector<long long int>& nums, long long int A, long long int B) {
    sort(nums.begin(), nums.end());
    long long int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        long long int target1 = A - nums[i];
        long long int target2 = B - nums[i];
        auto upper = upper_bound(nums.begin() + i + 1, nums.end(), target2);
        auto lower = lower_bound(nums.begin() + i + 1, nums.end(), target1);
        count += (upper - lower);
    }
    return count;
}

int main() {
    long long int N, A, B;
    cin >> N >> A >> B;
    vector<long long int> nums(N);
    for(int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    long long int ans = countPairs(nums, A, B);
    cout << ans << endl;

    return 0;
}