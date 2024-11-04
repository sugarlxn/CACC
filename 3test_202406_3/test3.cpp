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
vector<int> cnt; //存储词汇出现频率
vector<string> ans; //存储词汇表

struct node{ // node 的数据成员有四个 int 类型的 id1, id2, cnt, vis
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
struct Info{
    multiset<int> posi; //允许相同的键插入 集合set
    int cnt, vis;
};
map<pair<int,int>, Info> mpInfo;
Info& getInfo(int id1, int id2){
    if(mpInfo.count({id1,id2})) return mpInfo[{id1,id2}]; //map.count Returns the number of elements with key `key`
    else return mpInfo[{id1,id2}] = {multiset<int>(),0,0};
}

void solution(){
    cin >> n >> m; //n 行 最长词汇表m
    vector<string> s(n); //存储词汇表 词汇
    vector<int> vis(26,0);//vis 存储26个字母
    v.resize(n), cnt.resize(n);
    for(int i=0; i<n; i++){
        cin >> s[i] >> cnt[i]; //s[i] 为vector<string> 存储词汇，cnt[i]: vector<int> 存储出现频率
        for(auto& ch : s[i]) vis[ch - 'a'] = 1;  //统计出现的字母
    }

    for(int i=0; i<26; i++){
        if(vis[i]){
            ans.emplace_back(string(1, 'a' + i)); //将字母存入词汇表
        }
        if(i) vis[i] += vis[i-1]; // ？ 
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].length();j++){
            v[i].emplace_back(vis[s[i][j]- 'a'] - 1);
            if(j){
                Info& info = getInfo(v[i][j-1], v[i][j]);
                info.posi.emplace(i), info.cnt += cnt[i], ++info.vis;
                pq.emplace((node){v[i][j-1], v[i][j], info.cnt, info.vis}); //优先级队列
            }
        }
    }
    while (ans.size() < m) { 
        while (pq.size() && pq.top().vis != mpInfo[{pq.top().id1, pq.top().id2}].vis) pq.pop();
        if (pq.empty()) break;
        if (pq.top().cnt == 0) break;

        int id1 = pq.top().id1, id2 = pq.top().id2;
        lxn::log(id1, id2);
        Info& info = getInfo(id1, id2);
        pq.pop();
        ans.emplace_back(ans[id1] + ans[id2]);

        for (auto i : info.posi) {
            int p = -1;
            for (int j = 0; j < v[i].size() - 1; j++)
                if (v[i][j] == id1 && v[i][j + 1] == id2) {
                    p = j;
                    break;
                }
            if (p == -1) continue;

            // lampda 表达式 [capture list] (parameter list) -> return type { function body }
            // remove 函数从posi 集合中删除一个元素并更新 cnt 和 vis，然后将一个新的 node 对象添加到优先队列中
            auto remove = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.erase(tem.posi.find(idx));
                tem.cnt -= cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };
            // add 函数向 posi 集合中添加一个元素并更新 cnt 和 vis，然后将一个新的 node 对象添加到优先队列中
            auto add = [&] (int id1, int id2, int idx) {
                Info& tem = getInfo(id1, id2);
                if (&tem.posi == &info.posi) return;
                tem.posi.emplace(idx);
                tem.cnt += cnt[idx], ++tem.vis;
                pq.emplace((node){id1, id2, tem.cnt, tem.vis});
            };

            if (p) remove(v[i][p - 1], v[i][p], i);
            if (p + 2 < v[i].size()) remove(v[i][p + 1], v[i][p + 2], i);

            v[i].erase(v[i].begin() + p + 1);
            v[i][p] = ans.size() - 1;

            if (p) add(v[i][p - 1], v[i][p], i);
            if (p + 1 < v[i].size()) add(v[i][p], v[i][p + 1], i);
        }

        info.posi.clear();
        info.cnt = 0, ++info.vis;
        pq.emplace((node){id1, id2, info.cnt, info.vis});
    }

    for (auto& str : ans) cout << str << endl;
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