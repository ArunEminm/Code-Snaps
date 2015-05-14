#include<iostream>
#include <vector>
using namespace std;

int main()
{
  int N, T;
  cin >> N >> T;
  vector <int> width(N);
  for(int i = 0; i < (int)N; ++i) {
    cin >> width[i];
  }

  for(int i = 0; i < (int)T; ++i) {
    int l, r;
    cin >> l >> r;

    int ans = width[l];
    while(l <= r) {
      ans = min(ans, width[l]);
      l++;
    }
    cout << ans << "\n";
  }

  return 0;
}