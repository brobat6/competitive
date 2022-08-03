#include <bits/stdc++.h>
using namespace std;
#define int long long

int c, p; // no of contri, no of projects

map<string, int> skill_to_id;
map<int, string> id_to_skill;
int skill_count = 1;
map<string, int> cont_to_id;
map<int, string> id_to_cont;
map<string, int> project_to_id;
map<int, string> id_to_project;

vector<vector<string>> final_answer;

struct Skill {
    string name;
    int id, level;
};

struct Contributor {
    string name;
    int id;
    int n; // number of skills
    // vector<Skill> z_skills;
    map<int, int> level; // m[skill_id] = level of that skill, for ease.
};

struct Project {
    string name;
    int id;
    int days;
    int score;
    int best;
    int n; // number of roles
    vector<Skill> roles;
};

Contributor def{"0", -1, -1, {}};

vector<Contributor> conts;
vector<Project> projs;
map<int, int> in_use; // is the contributor in use right now, or not!
int current_day = 0;
set <pair<int, int>> dates; // dates to check {date of ending, project_id}
vector<vector<Contributor>> skills(1E5); // m[skill] = list of contributors that can provide the skill

vector<Contributor> find_assignable_roles(int project_id) {
    map<int, int> highest_level; // m[skill_id] = highest level achieved so far in the entire group (for mentorship)
    vector<Contributor> empty_list; // return in case of non-assignable configuration
    vector<Contributor> answer(projs[project_id].n, def);
    int n = projs[project_id].n;
    int cnt = 0;
    vector<int> assigned(n, 0); 
    map<int, int> temp_assigned; // if we have temporarily assigned this contributor.
    while(cnt < n) {
        // Find best assignable skill, assign it, and move to the next iteration.
        // If no contributor is found for any skill, return FALSE
        bool left = true;
        for(int i = 0; i < n; i++) {
            if(assigned[i] == 1) continue;
            Skill role = projs[project_id].roles[i];
            int level_needed = role.level;
            if(highest_level[role.id] >= role.level) {
                level_needed--;
            }
            // POSSIBLE IN THE FUTURE, SORT BY INCREASING ORDER OF SKILLS. WOULD BE REALLY GREAT FOR F TEST SET.
            for(auto aspirant : skills[role.id]) {
                if(in_use[aspirant.id] || temp_assigned[aspirant.id]) continue;
                // If aspirant's skill level is less, continue.
                // cout << aspirant.id << " " << role.id << ";";
                // cout << aspirant.level[role.id] << " " << level_needed << ";";
                if(aspirant.level[role.id] < level_needed) continue;
                assigned[i] = 1;
                cnt++;
                answer[i] = aspirant;
                temp_assigned[aspirant.id] = 1;
                left = false;
                highest_level[role.id] = max(highest_level[role.id], aspirant.level[role.id]);
                break;
            }
        }
        if(left) {
            // cerr << "F";
            return empty_list;
        }
    }
    // Assign answer???
    return answer;
}

void first_approach() {
    vector<vector<Contributor>> assigned_contributors(p);
    int learn_debugging = 0;
    while(true) {
        while(!dates.empty()) {
            // cout << -(learn_debugging++) << endl;
            pair<int, int> f = *dates.begin();
            for(auto contributor : assigned_contributors[f.second]) {
                in_use[contributor.id] = false; // REMEMBER TO LEVEL UP IN CASE THEY WERE MENTORS!!!!!!!!
            }
            dates.erase(dates.begin());
            if(dates.empty()) break;
            pair<int, int> f2 = *dates.begin();
            if(f2.first != f.first) break;
            current_day = f.first;
        }
        // cout << (learn_debugging++) << endl;
        // Now dates have been emptied. Check for current day.
        vector<Project> remaining;
        for(int i = 0; i < p; i++) {
            if(assigned_contributors[i].size() == 0) {
                remaining.push_back(projs[i]);
            }
        }
        sort(remaining.begin(), remaining.end(), [&](Project a, Project b) {
            return a.score > b.score; // HORRIBLE COMPARATOR, CHANGE IT PLEASE
        });
        bool something_was_assigned = false;
        for(auto curr_proj: remaining) {
            auto possible = find_assignable_roles(curr_proj.id);
            if(possible.size() == 0) continue;
            vector<string> transfer;
            transfer.push_back(curr_proj.name);
            for(auto contri : possible) {
                in_use[contri.id] = true;
                transfer.push_back(contri.name);
            }
            final_answer.push_back(transfer);
            dates.insert({current_day + curr_proj.days, curr_proj.id});
            assigned_contributors[curr_proj.id] = possible;
            something_was_assigned = true;
        }
        if(something_was_assigned == false) {
            break;
        }
    }
    cout << (int)final_answer.size() << endl;
    for(int i = 0; i < (int)final_answer.size(); i++) {
        cout << final_answer[i][0] << endl;
        for(int j = 1; j < final_answer[i].size(); j++) {
            cout << final_answer[i][j] << " ";
        }
        cout << endl;
    }
}

void take_input() {
    cin >> c >> p;
    Contributor tc;
    Skill ts;
    Project tp;
    int t1, t2, t3, t4;
    for(int i = 0; i < c; i++) {
        cin >> tc.name;
        tc.id = i;
        cont_to_id[tc.name] = tc.id;
        id_to_cont[tc.id] = tc.name;
        cin >> tc.n;
        // tc.skills.clear();
        tc.level.clear();
        // tc.skills.clear();
        vector <Skill> temp_skills;
        for(int j = 0; j < tc.n; j++) {
            cin >> ts.name >> ts.level;
            if(skill_to_id[ts.name] >= 1 && skill_to_id[ts.name] <= skill_count) {
                ts.id = skill_to_id[ts.name];
            } else {
                ts.id = skill_count++;
                skill_to_id[ts.name] = ts.id;
                id_to_skill[ts.id] = ts.name;
            }
            tc.level[ts.id] = ts.level;
            temp_skills.push_back(ts);
            // skills[ts.id].push_back(tc);
            // tc.skills.push_back(ts);
        }
        for(auto sk : temp_skills) {
            skills[sk.id].push_back(tc);
            // skills[sk.id].push_back(tc);
        //     tc.level[sk.id] = sk.level;
        }
        conts.push_back(tc);
        // for(auto sk : conts[i].skills) {
        //     conts[i].level[sk.id] = sk.level;
        // }
    }
    for(int i = 0; i < p; i++) {
        cin >> tp.name;
        tp.id = i;
        project_to_id[tp.name] = tp.id;
        id_to_project[tp.id] = tp.name;
        cin >> tp.days >> tp.score >> tp.best >> tp.n;
        tp.roles.clear();
        for(int j = 0; j < tp.n; j++) {
            cin >> ts.name >> ts.level;
            if(skill_to_id[ts.name] >= 1 && skill_to_id[ts.name] <= skill_count) {
                ts.id = skill_to_id[ts.name];
            } else {
                ts.id = skill_count++;
                skill_to_id[ts.name] = ts.id;
                id_to_skill[ts.id] = ts.name;
            }
            tp.roles.push_back(ts);
        }
        projs.push_back(tp);
    }
}



int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("f_find_great_mentors.in.txt", "r", stdin);
    freopen("1-6.txt", "w", stdout);
    
    take_input();
    // test_input();
    first_approach();
    
    return 0;
}