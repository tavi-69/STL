#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

void demo1() {
   
}

int main()
{
    ifstream inFile("input.txt");
    stack<pair<string, string>> pacienti;
    map<string, string> doctori;
    vector<string> pac, cauza; 
    string doctoriiii;


    int no_problems, no_doctors;
    string name, speciality;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        // pacienti.push(make_pair(name, speciality));

        pac.push_back(name);
        cauza.push_back(speciality);

        /*cout << name << ' ' << speciality << '\n';*/
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        // doctori[speciality] = name;

        doctoriiii += speciality;
        //cout << name << ' ' << speciality << '\n';
    }

    /*while (!pacienti.empty()) {
        string cauza = pacienti.top().second;
        if (!doctori[cauza].empty()) {
            cout << pacienti.top().first << " Acceptat\n";
        }
        else {
            cout << pacienti.top().first << " Respins\n";
        }
        pacienti.pop();
    }*/

    for (auto it = 0; it < cauza.size(); ++it) {
        
        if (doctoriiii.find(cauza[it]) != string::npos) {
            cout << pac[it] << " Acceptat\n";
        }
        else{
            cout << pac[it] << " Respins\n";
        }
    }





    return 0;
}