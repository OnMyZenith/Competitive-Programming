/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

// #ifndef asr_debug
// #pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
// Can casuse floating point errors, assumes associativeness for instance

#pragma GCC target("avx2")
#pragma GCC target("popcnt,lzcnt,bmi,bmi2,tune=native")
// #pragma GCC target("avx,fma")
// #pragma GCC target("sse4.2,fma")
// run custom tests with stuff like assert(__builtin_cpu_supports("avx2"))
// or use avx instead of sse4.2, leave fma in as it was covered in avx2
// #endif

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

template <class T> bool ckmin(T &x, const T &y) { return (y < x) ? (x = y, 1) : 0; }
template <class T> bool ckmax(T &x, const T &y) { return (y > x) ? (x = y, 1) : 0; }

struct project{
    string name; int days, score, best_bef, roles_cnt;
    // unordered_map<string, int> skills_req;
    vector<pair<string, int>> skills_req;
};

struct contributer{
    string name; int skills_cnt, free_from;
    unordered_map<string, int> skills_poss;
};


int main(int argc, char **argv) {
    (void)argc;
    vamos;

    int n, m; cin >> n >> m;

    vector<contributer> emp(n);
    vector<project> proj(m);

    unordered_map<string, int> skill_max;

    for (int i = 0; i < n; i++) {
        emp[i].free_from = 0;
        cin >> emp[i].name >> emp[i].skills_cnt;
        for (int j = 0; j < emp[i].skills_cnt; j++) {
            string _n; int x; cin >> _n >> x;
            emp[i].skills_poss[_n] = x;
            ckmax(skill_max[_n], x);
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> proj[i].name >> proj[i].days >> proj[i].score >> proj[i].best_bef >> proj[i].roles_cnt;
        for (int j = 0; j < proj[i].roles_cnt; j++) {
            string _n; int x; cin >> _n >> x;
            proj[i].skills_req.push_back({_n, x});
            skill_max[_n];
        }
    }

    sort(proj.begin(), proj.end(), [&](auto i, auto j){return i.score > j.score;});
    // // sort(proj.begin(), proj.end(), [&](auto i, auto j){return i.best_bef < j.best_bef;});
    // sort(emp.begin(), emp.end(), [&](auto i, auto j){
    //     auto iti = i.skills_poss.begin();
    //     auto itj = j.skills_poss.begin();
    //     return (*iti).second < (*itj).second;
    // });

    vector<pair<string, vector<string>>> planned;
    int sc = 0, best_sc = 0;
    for (int i = 0, curr_day = 0; i < m; i++) {
        auto &[name_of_proj, days, score, best_bef, roles_cnt, skills_req] = proj[i];
        bool done = 1;
        vector<string> poss;
        auto tmp_emp = emp;
        auto tmp_skill_max = skill_max;
        for (auto &[skill_name, lvl] : skills_req) {
            bool found = 0;
            for (int j = 0; j < n; j++) {
                // if(emp[j].free_from <= curr_day && (emp[j].skills_poss[skill_name] >= lvl || (emp[j].skills_poss[skill_name] + 1 == lvl && skill_max[skill_name] >= lvl))) {
                if(emp[j].free_from <= curr_day && emp[j].skills_poss[skill_name] >= lvl) {
                    emp[j].free_from = curr_day + days;
                    if(emp[j].skills_poss[skill_name] == lvl) {
                        emp[j].skills_poss[skill_name]++;
                        // ckmax(skill_max[skill_name], emp[j].skills_poss[skill_name]);
                    }
                    poss.push_back(emp[j].name);
                    found = 1; break;
                }
            }
            if(!found){done = 0; emp = tmp_emp; skill_max = tmp_skill_max; break;}
        }
        if(done) {
            sc += score;
            planned.push_back({name_of_proj, poss});
        }
        cerr << sc << '\n';
        if(ckmax(best_sc, sc)){
            freopen(argv[1], "w", stdout);
            cout << (int)planned.size() << '\n';
            for (auto &[name, assignments] : planned) {
                cout << name << '\n';
                int num = (int)assignments.size();
                for (int ii = 0; ii < num; ii++) {
                    cout << assignments[ii];
                    if(ii == num - 1) cout << endl;
                    else cout << " ";
                }
            }
            fclose(stdout);
        }
    }
    // cout << (int)planned.size() << '\n';
    // for (auto &[name, assignments] : planned) {
    //     cout << name << '\n';
    //     int num = (int)assignments.size();
    //     for (int i = 0; i < num; i++) {
    //         cout << assignments[i] << " \n"[i == num - 1];
    //     }
    // }
    return 0;
}