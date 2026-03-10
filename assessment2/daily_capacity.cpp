#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool canFinish(vector<long long>& workloads, int D, long long capacity) {
    long long currentLoad = 0;
    int days = 1;

    for (long long work : workloads) {
        if (currentLoad + work > capacity) {
            days++;
            currentLoad = work;
        } else {
            currentLoad += work;
        }
    }
    return days <= D;
}

int main() {
    int N, D;
    cin >> N >> D;

    vector<long long> workloads(N);

    long long maxWork = 0, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> workloads[i];
        maxWork = max(maxWork, workloads[i]);
        sum += workloads[i];
    }

    long long left = maxWork;
    long long right = sum;
    long long ans = sum;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        if (canFinish(workloads, D, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << ans;

    return 0;
}