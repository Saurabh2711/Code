// Author : Abhisar Singhal
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <stack>
#include <cctype>
#include <utility>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <string>
#include <sstream>
#include <utility>
#include <ctime>
#include <cassert>
#include <fstream>
using namespace std;
 
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> II;
typedef vector<long long> VLL;
typedef vector<bool> VB;
 
#define SZ(A) ((int)A.size())
#define LEN(A) ((int)A.length())
#define MS(A) memset(A, 0, sizeof(A))
#define MSV(A,a) memset(A, a, sizeof(A))
#define MAX(a,b) ((a >= b) ? (a) : (b))
#define MIN(a,b) ((a >= b) ? (b) : (a))
#define ABS(a) (((a) > 0) ? (a) : (-a))
#define MP make_pair
#define X first
#define Y second
#define PB push_back
#define FOUND(A, x) (A.find(x) != A.end())
#define getcx getchar_unlocked
#define INF (int(1e9))
#define INFL (LL(1e18))
#define EPS 1e-12
 
#define chkbit(s, b) (s & (1<<b))
#define setbit(s, b) (s |= (1<<b))
#define clrbit(s, b) (s &= ~(1<<b))
 
#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)
#define FORALL(itr, c) for(itr = (c).begin(); itr != (c).end(); itr++)
#define ALL(A) A.begin(), A.end()
#define LLA(A) A.rbegin(), A.rend()
//int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
//int dx[] = {1, 1, 1, 0, 0, -1, -1, -1}, dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
inline void inp( int &n ) {
n=0; int ch = getcx(); int sign = 1;
while(ch < '0' || ch > '9') { if(ch == '-') sign=-1; ch = getcx(); }
while(ch >= '0' && ch <= '9') { n = (n << 3) + (n << 1) + ch - '0', ch = getcx(); }
n = n * sign;
}
 
const int N = 100009;
 
char str[N];
 
struct SegmentTreeNode {
LL ans;
LL pre[3];
LL suf[3];
bool isNull;
int fullMod;
SegmentTreeNode() {
ans = 0;
MS(pre);
MS(suf);
isNull = false;
fullMod = 0;
}
};
 
void print(SegmentTreeNode node) {
cout << node.ans << endl;
REP (i, 3) {
cout << node.pre[i] << " ";
}
cout << endl;
REP (i, 3) {
cout << node.suf[i] << " ";
}
cout << endl;
cout << node.fullMod << endl;
 
}
 
 
SegmentTreeNode tree[4 * N];
 
SegmentTreeNode merge(SegmentTreeNode a, SegmentTreeNode b) {
if (a.isNull && b.isNull) {
SegmentTreeNode ret;
ret.isNull = true;
return ret;
}
if (a.isNull) return b;
if (b.isNull) return a;
 
SegmentTreeNode ret;
ret.ans = a.ans + b.ans;
REP (i, 3) {
ret.ans += a.suf[i] * b.pre[(3 - i) % 3];
}
 
REP (i, 3) {
ret.pre[i] += a.pre[i];
ret.suf[i] += b.suf[i];
}
 
REP (i, 3) {
ret.pre[(i + a.fullMod) % 3] += b.pre[i];
ret.suf[(i + b.fullMod) % 3] += a.suf[i];
}
ret.fullMod = (a.fullMod + b.fullMod) % 3;
return ret;
}
 
void build(int node, int tl, int tr) {
if (tl > tr) return;
if (tl == tr) {
int val = str[tl] - '0';
val %= 3;
REP (i, 3) {
tree[node].pre[i] = tree[node].suf[i] = (val == i);
}
tree[node].ans = (val == 0);
tree[node].fullMod = val;
return;
}
build(2 * node, tl, (tl + tr) / 2);
build(2 * node + 1, (tl + tr) / 2 + 1, tr);
tree[node] = merge(tree[2 *node], tree[2 * node + 1]);
}
 
 
SegmentTreeNode query(int node, int tl, int tr, int l, int r) {
if (tl > tr || tl > r || tr < l) {
SegmentTreeNode node;
node.isNull = true;
return node;
}
if (tl >= l && tr <= r) {
return tree[node];
}
SegmentTreeNode ans1 = query(node << 1, tl, (tl + tr) >> 1, l, r);
SegmentTreeNode ans2 = query((node << 1) + 1, ((tl + tr) >> 1) + 1, tr, l, r);
return merge(ans1, ans2);
}
 
void update(int node, int tl, int tr, int pos, int val) {
if (tl > tr || pos < tl || pos > tr) return;
if (tl == pos && tr == pos) {
val %= 3;
REP (i, 3) {
tree[node].pre[i] = tree[node].suf[i] = (val == i);
}
tree[node].ans = (val == 0);
tree[node].fullMod = val;
return;
}
update(2 * node, tl, (tl + tr) / 2, pos, val);
update(2 * node + 1, (tl + tr) / 2 + 1, tr, pos, val);
tree[node] = merge(tree[2 *node], tree[2 * node + 1]);
}
 
int main() {
std::ios_base::sync_with_stdio(false);
int n, q;
inp(n), inp(q);
scanf("%s", str);
build(1, 0, n - 1);
REP (i, q) {
int x, y, z;
inp(x), inp(y), inp(z);
if (x == 1) {
y --;
update(1, 0, n - 1, y, z);
} else {
y --, z --;
printf("%lld\n", query(1, 0, n-1, y, z).ans);
}
}
return 0;
}