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

// global var
const int N = 2e5+5;
int a[N];
int n,m,t;

void solution(){
    cin >> n >> m >> t;
    lxn::log("nmt",n,m,t);
    for(int i=0; i<n*m; i++) cin >> a[i];    
    while(t--){
        int op,x,y;
        if(op==1){n=x;m=y;}
        else if(op==2){
            
        }
        
    }
}

int main(int argc, char * argv[]){

#ifdef LOCAL
    freopen("/home/lxn/CACC/2test/data.in","r",stdin);
    freopen("/home/lxn/CACC/2test/data.out","w",stdout);
#endif

    int iterations = 1;
    while(iterations--){
        solution();
    }

    return 0;
}