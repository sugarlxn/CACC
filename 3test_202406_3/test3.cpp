#pragma GCC optimize(2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
using i64 = long long;
using ui64 = unsigned long long;
#define inf (int)0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f 
#define yn(n) cout << (x ? "yes" : "no") << endl
#define Yn(n) cout << (x ? "Yes" : "No") << endl
#define YN(n) cout << (x ? "YES" : "NO") << endl
#define mem(x,i) memset(x,i,sizeof(x))
#define cinarr(a,n) for(int _=1; _<=n; _++) cin >> a[_]
#define cinstl(a,n) for(auto& _ : a) cin >> _
#define coutarr(a,n) for(int _=1; _<=n; _++) cout << a[_] << " \n"[_==n]
#define coutstl(a,n) for(const auto& _ : a) cout << _ << " "; cout << endl
#define all(x) (x).begin(), (x).end()
#define md(x,mod) (((x)%mod + mod)%mod)

#define LOCAL 
#define DEBUG 1

namespace lxn{
//递归打印可变参数列表
void log(){
#if DEBUG
    cout << endl;
#endif
}   
//variadic template
template<typename T, typename... Args>
void log(T firstArg, Args... args){
#if DEBUG
    cout << firstArg << " ";
    log(args...);
#endif
}
};

///write down your code here:[begin] 
// global var
const int N = 2e5+5;
int a[N];
int n,m,t,k,q;

vector<vector<int>> v;
vector<int> cnt;
vector<string> ans;

struct node{
    int id1,id2,cnt,vis; 
    bool operator < (const node& t) const{
        if(cnt != t.cnt) return cnt < t.cnt;
        if(ans[id1].length() != ans[t.id1].length()){
            return ans[id1].length() > ans[t.id1].length();
        }
        if(ans[id1].length() != ans[t.id1].length()){
            return ans[id1].length() > ans[t.id1].length();
        }
        return ans[id1] + ans[id2] > ans[t.id1] + ans[t.id2];
    }
};
//优先级队列
priority_queue<node> pq;


void solution(){

};

///write down your code here:[end]

int main(int argc, char * argv[]){

#ifdef LOCAL
    freopen("/home/lxn/CACC/3test_202406_3/data.in","r",stdin);
    freopen("/home/lxn/CACC/3test_202406_3/data.out","w",stdout);
#endif

    int iterations = 1;
    while(iterations--){
        solution();
    }

    return 0;
}