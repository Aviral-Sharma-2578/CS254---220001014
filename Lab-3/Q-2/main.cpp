#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum crossing the midpoint
int maxCrossingSum(const vector<int>& arr, int low, int mid, int high) {
    int leftSum = numeric_limits<int>::min();
    int sum = 0;
    for (int i = mid; i >= low; --i) {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    int rightSum = numeric_limits<int>::min();
    sum = 0;
    for (int i = mid + 1; i <= high; ++i) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}

// Function to find the maximum subarray sum using divide-and-conquer
int maxSubarraySum(const vector<int>& arr, int low, int high) {
    if (low == high)
        return arr[low];
    int mid = (low + high) / 2;
    return max(max(maxSubarraySum(arr, low, mid),
                   maxSubarraySum(arr, mid + 1, high)),
               maxCrossingSum(arr, low, mid, high));
}

int main() {
    int x; vector<int> arr;

    ifstream input("input.txt");
    while(input >> x) arr.push_back(x);
    input.close();
    
    int n = arr.size();
    int maxSum = maxSubarraySum(arr, 0, n - 1);
    cout << "The largest possible sum of a subarray is: " << maxSum << endl;
    return 0;
}
