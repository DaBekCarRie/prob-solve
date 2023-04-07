#include <iostream>
#include <algorithm>

const int MAXN = 1010;

struct Job {
    int start, end, weight;
};

Job jobs[MAXN];
int dp[MAXN], prev_job[MAXN], job_count[MAXN];

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> jobs[i].start >> jobs[i].end >> jobs[i].weight;
    }
    std::sort(jobs, jobs + n, [](const Job& j1, const Job& j2) {
        return j1.end < j2.end;
    });
    dp[0] = jobs[0].weight;
    prev_job[0] = -1;
    job_count[0] = 1;
    for (int i = 1; i < n; i++) {
        int max_weight = jobs[i].weight;
        int prev = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (jobs[j].end <= jobs[i].start) {
                if (max_weight < dp[j] + jobs[i].weight) {
                    max_weight = dp[j] + jobs[i].weight;
                    prev = j;
                }
            }
        }
        if (prev != -1) {
            dp[i] = max_weight;
            prev_job[i] = prev;
            job_count[i] = job_count[prev] + 1;
        } else {
            dp[i] = std::max(dp[i - 1], jobs[i].weight);
            if (dp[i] == jobs[i].weight) {
                job_count[i] = 1;
            } else {
                job_count[i] = job_count[i - 1];
            }
            prev_job[i] = (dp[i] == dp[i - 1]) ? prev_job[i - 1] : i - 1;
        }
    }
    std::cout << dp[n - 1] << '\n';
    int j = n - 1;
    while (j >= 0 && prev_job[j] != -1) {
        if (prev_job[j] == j - 1 && dp[j] == dp[j - 1]) {
            j--;
        } else {
            std::cout << j + 1 << ' ';
            j = prev_job[j];
        }
    }
    if (j == 0) {
        std::cout << "1\n";
    } else {
        std::cout << '\n';
    }
    return 0;
}