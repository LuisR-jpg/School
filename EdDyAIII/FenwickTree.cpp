#include <bits/stdc++.h>
using namespace std;
void update(int i, int v){
  i++;
  while(i <= n){
    t[i] += v;
    i += (i & -i);
  }
}
int query(int i){
  int res = 0;
  i++;
  while(i > 0){
    res += t[i];
    i -= (i & -i);
  }
  return res;
}
void build(){
  for(int i = 0; i < n; i++)
    update(i, x[i]);
}
int main(){
  int n;
  cin >> n;
  int a[n+3];
  for(int i = 0; i < n; cin >> a[i++]);
  build();
  return 0;
}
