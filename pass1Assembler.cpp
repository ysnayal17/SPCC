#include <bits/stdc++.h>
#define print(n) cout << n << endl
#define pb push_back
#define f first
#define s second
using namespace std;
map<string, int> sym;
int symCounter = 0;
int startAddress = -1;
int ind = -1;

map<int, vector<string>> passTwo;

map<string, pair<string, string>> MOT;

bool onlyNum(string s)
{
    for (auto it : s)
    {
        if (it >= '0' && it <= '9')
        {
            continue;
        }
        return false;
    }
    return true;
}

string eval(vector<string> &vs)
{
    string ans = "";
    int n = vs.size();
    bool pass2Flag = false;
    for (int i = 0; i < n; i++)
    {
        // print("ITR "<<vs[i]);
        ans += "[ ";
        if (onlyNum(vs[i]))
        {
            ans += "c ";
            ans += (vs[i]);
        }
        else if (vs[i] == "START")
        {
            ans += MOT[vs[i]].f;
            ans += " ";
            ans += MOT[vs[i]].s;
            startAddress = stoi(vs[i + 1]);
        }
        else if (MOT.find(vs[i]) != MOT.end())
        {
            ans += MOT[vs[i]].f;
            ans += " ";
            ans += MOT[vs[i]].s;
            if (MOT[vs[i]].f == "IS")
            {
                pass2Flag = true;
                passTwo[ind].pb(MOT[vs[i]].s);
                if (vs.size() == 2)
                {
                    passTwo[ind].pb("00");
                }
                ans += " ] ";
                continue;
            }
            if (pass2Flag)
            {
                passTwo[ind].pb(MOT[vs[i]].s);
            }
        }
        else
        {
            ans += "S";
            ans += " ";
            if (sym.find(vs[i]) != sym.end())
            {
                ans += to_string(sym[vs[i]]);
            }
            else
            {
                sym[vs[i]] = symCounter;
                ans += to_string(sym[vs[i]]);
                symCounter++;
            }

            if (pass2Flag)
            {
                passTwo[ind].pb(to_string(startAddress + sym[vs[i]]));
            }
        }
        ans += " ] ";
        // print(i<<" itr "<<ans);
    }
    // print("RETURN: "<<ans);
    //  if (strstr(ans.c_str(),"IS")){

    // }
    return ans;
}
int main()
{
    MOT["STOP"] = {"IS", "00"};
    MOT["ADD"] = {"IS", "01"};
    MOT["SUB"] = {"IS", "02"};
    MOT["MUL"] = {"IS", "03"};
    MOT["MOVER"] = {"IS", "04"};
    MOT["MOVEM"] = {"IS", "05"};
    MOT["COMP"] = {"IS", "06"};
    MOT["BC"] = {"IS", "07"};
    MOT["DIV"] = {"IS", "08"};
    MOT["READ"] = {"IS", "09"};
    MOT["PRINT"] = {"IS", "10"};

    MOT["START"] = {"AD", "01"};
    MOT["END"] = {"AD", "02"};
    MOT["ORIGIN"] = {"AD", "03"};
    MOT["EQU"] = {"AD", "04"};
    MOT["LTORG"] = {"AD", "05"};

    MOT["DS"] = {"DL", "01"};
    MOT["DC"] = {"DL", "02"};

    MOT["AREG"] = {"RG", "01"};
    MOT["BREG"] = {"RG", "02"};
    MOT["CREG"] = {"RG", "03"};

    MOT["LT"] = {"CC", "01"};
    MOT["LE"] = {"CC", "02"};
    MOT["EQ"] = {"CC", "03"};
    MOT["GT"] = {"CC", "04"};
    MOT["GE"] = {"CC", "05"};
    MOT["ANY"] = {"CC", "06"};
    print("Enter Number of Lines: ");
    int n;
    cin >> n;
    print("Enter " << n << " Lines of Code: ");
    vector<vector<string>> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        if (i == 0)
            getline(cin, s);
        getline(cin, s);
        // print(s);
        string tmp = "";
        vector<string> tv;
        for (auto it : s)
        {
            if (it == ' ')
            {
                tv.pb(tmp);
                tmp = "";
                continue;
            }
            tmp += it;
        }
        tv.pb(tmp);
        v.pb(tv);
    }
    print("PASS-1 Table:");
    print("LC \t Intermediate Code");
    // for (auto it: v){
    //     for (auto x: it){
    //         cout<<x<<" ";
    //     }
    //     cout<<endl;
    // }
    for (auto it : v)
    {
        string pass1 = eval(it);
        if (ind >= 0)
            cout << (startAddress + ind);
        cout << (" \t ");
        print(pass1);
        ind++;
    }
    print("PASS-2 Table:");
    print("LC \t Machine Code");
    for (int j = -1; j < ind; j++)
    {
        if (j >= 0)
            cout << (startAddress + j);
        cout << " \t ";
        if (passTwo.find(j) != passTwo.end())
        {
            for (auto x : passTwo[j])
            {
                cout << x << " ";
            }
            // cout<<" \t "<<j;
        }
        else
        {
            cout << (" ___ ");
        }
        cout << endl;
    }
    print("Symbol Table: ");
    for (auto it : sym)
    {
        if (it.f.size() == 1)
        {
            cout << it.f << " " << (501 + it.s) << endl;
        }
    }
    return 0;
}
