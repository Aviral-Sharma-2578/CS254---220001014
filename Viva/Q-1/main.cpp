#include <bits/stdc++.h>
using namespace std;

int main()
{
  // vector<int> a = {15, 17, 20, 25, 32, 16, 7, 5, 1};
  vector<int> a = {-15, -13, -5, -2};
  int n = a.size(), ans = INT_MIN;
  int low = 0, high = n - 1;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    int x = a[mid];
    ans = max(ans, x);
    if (mid + 1 < n and x <= a[mid + 1])
      low = mid + 1;
    else
      high = mid - 1;
  }
  cout << ans;
}