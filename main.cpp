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
};

int main()
{
    ifstream inFile("input4_bonus.txt");
    vector<doctor> doctors;
    vector<pacient> pacienti;

    int no_problems, no_doctors;
    ll time;
    string name, speciality;

    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        inFile >> time;
        pacienti.push_back({name, speciality, time});
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        doctors.push_back({name, speciality});
    }

    for(const auto& it : pacienti) {
        auto index = find_if(begin(doctors), end(doctors), [&it](doctor& a) {
            return it.specializare == a.specializare && a.time + it.timp <= 8;
        });

        if(index != doctors.end()) {
            index->probleme.push_back(it.problema);
            index->time += it.timp;
        }
    }

    for(const auto& it : doctors) {
        cout << it.id << " " << it.probleme.size() << " ";
        for(const auto& prob : it.probleme) cout << prob << " ";
        cout << endl;
    }

    return 0;
}