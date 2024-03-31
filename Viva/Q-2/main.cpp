#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll n = 3000000000;
const ll m = 126;

ll f(ll x)
{
  if (x <= m)
    return x * x;
  return (-1) * x * x;
}

int main()
{
  ll ans_idx = -1;
  ll ans = LLONG_MIN;
  ll low = 0, high = n;
  while (low <= high)
  {
    ll mid = low + (high - low) / 2;
    ll y = f(mid);
    if (y > ans)
    {
      ans_idx = mid;
      ans = y;
    }
    if (y <= f(mid + 1))
      low = mid + 1;
    else
      high = mid - 1;
  }
  cout << "Index at which maximum occurs: " << ans_idx << "\n";
  cout << ans;
}