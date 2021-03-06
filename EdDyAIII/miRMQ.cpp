//Given an array, RMQ finds the minimun element in an interval.
//Memory O(nlogn)
//Time:
//  Query O(1)* Depends on the complexity of log()
//  Build O(nlogn) 
//  Update *No update allowed so it requires building again.

#include <bits/stdc++.h>
using namespace std;
const int mxN = 1e4;
int m[mxN][15], x[mxN];
int query(int a, int b){
  int k = log2(b - a + 1);
  int vu = m[a][k], vd = m[b - (1 << k) + 1][k];
  return min(x[vu], x[vd]);
}
int main(){
  int n, q;
  cin >> n >> q;
  for(int i = 0; i < n; cin >> x[i++]);
  for(int i = 0; i < n; i++) m[i][0] = i;
  for(int j = 1; (1 << j) <= n; j++){
    int s = 1 << (j - 1);
    for(int i = 0; i + (1 << j) - 1 < n; i++){
      if(x[m[i][j - 1]] < x[m[i + s][j - 1]]) m[i][j] = m[i][j - 1];
      else m[i][j] = m[i + s][j - 1];
    }
  }
  for(int i = 0, a, b; i < q; i++)
    cin >> a >> b, cout << query(a, b) << endl;
  return 0;
}
