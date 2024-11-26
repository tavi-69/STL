#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct doctor {
    string id;
    string specializare;
    // bool ocupat = false;
    ll time = 0;
    vector<string> probleme;
};

struct pacient {
    string problema;
    string specializare;
    ll timp;
    ll priority;

    pacient(string p, string s, ll t, ll pr) : problema(p), specializare(s), timp(t), priority(pr) {}
};
struct compare_pacienti {
    bool operator()(const pacient &p1, const pacient &p2) {
        return p1.priority < p2.priority;
    }
};

int main()
{
    ifstream inFile("C:\\Users\\Thavian\\CLionProjects\\STL\\input.txt");
    vector<doctor> doctors;
//    vector<pacient> pacienti;
    priority_queue<pacient, vector<pacient>, compare_pacienti> pacienti;

    int no_problems, no_doctors;
    ll time, prio;
    string name, speciality;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        inFile >> time;
        inFile >> prio;
        pacienti.emplace(name, speciality, time, prio);
    }

//    sort(begin(pacienti), end(pacienti), [](pacient& a, pacient &b) {
//       return a.priority > b.priority;
//    });

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctors.push_back({name, speciality});
    }

    while(!pacienti.empty()) {
        auto it = pacienti.top();
        auto index = find_if(begin(doctors), end(doctors), [&it](doctor& a) {
            return it.specializare == a.specializare && a.time + it.timp <= 8;
        });

        if(index != doctors.end()) {
            index->probleme.push_back(it.problema);
            index->time += it.timp;
        }
        pacienti.pop();
    }

    for(const auto& it : doctors) {
        if(it.probleme.empty()) continue;
        cout << it.id << " " << it.probleme.size() << " ";
        for(const auto& prob : it.probleme) cout << prob << " ";
        cout << endl;
    }

    return 0;
}