#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<list>
#include<unordered_map>
#include<map>
#include<stack>
#include<functional>
using namespace std;
const int mod = 998244353;
typedef pair<int, int> Pair;
typedef unsigned long long ull;
typedef long long ll;
const ull INF = 0x3f3f3f3f3f3f3f;
const int MAXN = 25;
int dp[MAXN][MAXN], path[MAXN][MAXN];
stack<int>sta;
void find_LCS(int X[], int Y[], int n, int m){
if (!n || !m) return;
if (path[n][m] == 1)
find_LCS(X, Y, n - 1, m);
else if (path[n][m] == 2)
find_LCS(X, Y, n, m - 1);
else if (path[n][m] == 3){
sta.push(X[n - 1]);
find_LCS(X, Y, n - 1, m - 1);
}
}
void LCS(int X[], int Y[], int n, int m)
{
memset(dp, 0, sizeof(dp));
memset(path, 0, sizeof(path));
for (int i = 1; i <= n; i++)
for (int j = 1; j <= m; j++){
if (X[i - 1] == Y[j - 1]){
dp[i][j] = dp[i - 1][j - 1] + 1;
path[i][j] = 3;
}
else{
if (dp[i - 1][j] > dp[i][j - 1]){
dp[i][j] = dp[i - 1][j];
path[i][j] = 1;
}
else{
dp[i][j] = dp[i][j - 1];
path[i][j] = 2;
}
}
}
printf("最长公共子序列的长度=%d\n", dp[n][m]);
find_LCS(X, Y, n, m);
while (!sta.empty()){
printf("%d\t", sta.top());
sta.pop();
}
}
int main(){
int X[] = { 3,2,5,7,1 }, Y[] = { 2,7,9,1,4 };
LCS(X, Y, 5, 5);
return 0;
}
