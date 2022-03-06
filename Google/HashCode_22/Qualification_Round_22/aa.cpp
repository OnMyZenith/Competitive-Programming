/* Author: OnMyZenith - https://github.com/OnMyZenith */
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using ll = long long;

#define vamos ios_base::sync_with_stdio(false), cin.tie(nullptr), cout << setprecision(15) << fixed;
#ifdef asr_debug
#include "dbg.hpp"
#else
#define dbg(...) 007
#endif

struct splitmix64_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template <class T, class U, typename Hash = splitmix64_hash> using hash_map = gp_hash_table<T, U, Hash>;
template <class T, typename Hash = splitmix64_hash> using hash_set = hash_map<T, null_type, Hash>;

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


int main() {
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

    // sort(proj.begin(), proj.end(), [&](auto i, auto j){return i.score > j.score;});
    sort(proj.begin(), proj.end(), [&](auto i, auto j){return i.best_bef < j.best_bef;});
    sort(emp.begin(), emp.end(), [&](auto i, auto j){
        auto iti = i.skills_poss.begin();
        auto itj = j.skills_poss.begin();
        return (*iti).second < (*itj).second;
    });

    vector<pair<string, vector<string>>> planned;
    int sc = 0;
    for (int i = 0, curr_day = 0; i < m; i++) {
        auto &[name_of_proj, days, score, best_bef, roles_cnt, skills_req] = proj[i];
        bool done = 1;
        vector<string> poss;
        auto tmp_emp = emp;
        auto tmp_skill_max = skill_max;
        for (auto &[skill_name, lvl] : skills_req) {
            bool found = 0;
            for (int j = 0; j < n; j++) {
                if(emp[j].free_from <= curr_day && (emp[j].skills_poss[skill_name] >= lvl || (emp[j].skills_poss[skill_name] + 1 == lvl && skill_max[skill_name] >= lvl))) {
                    emp[j].free_from = curr_day + days;
                    if(emp[j].skills_poss[skill_name] == lvl || emp[j].skills_poss[skill_name] + 1 == lvl) {
                        emp[j].skills_poss[skill_name]++; ckmax(skill_max[skill_name], emp[j].skills_poss[skill_name]);
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
        dbg(sc);
    }
    // dbg(planned);
    dbg(sc);
    cout << (int)planned.size() << '\n';
    for (auto &[name, assignments] : planned) {
        cout << name << '\n';
        int num = (int)assignments.size();
        for (int i = 0; i < num; i++) {
            cout << assignments[i] << " \n"[i == num - 1];
        }
    }
    return 0;
}