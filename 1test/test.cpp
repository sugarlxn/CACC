#pragma GCC optimize(2, 3, "Ofast", "inline")
#include <bits/stdc++.h>
// #include <iostream>
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

namespace lxn{
//递归打印可变参数列表
void log(){
    cout << endl;
}   
//variadic template
template<typename T, typename... Args>
void log(T firstArg, Args... args){
    cout << firstArg << " ";
    log(args...);
}
};

const int N = 2e5 + 5;

int i,j,m,n;
int a[N];

void work(){
    cin >> i >> j >> m >> n;
    lxn::log(i,j,m,n);
    for(int k = 0; k < i*j; k++) cin >> a[k];
    for(int k = 0; k < m*n; k++) cout << a[k] << " \n"[k % n == n-1];
}

int main(int argc, char * argv[]){


#ifdef LOCAL
    freopen("/home/lxn/CACC/1test/data.in","r",stdin);
    freopen("/home/lxn/CACC/1test/data.out","w",stdout);
#endif

    int data = 1;
    while(data--){
        work();
    }
    return 0;
}