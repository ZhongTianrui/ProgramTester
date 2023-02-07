#include <bits/stdc++.h>
#include "include/TimerClock.h"
// #include "include/GetPid.h"
#include <windows.h>
using namespace std;
ofstream logg("log\\log.log");
bool CE() {
    ifstream test("std\\std.exe");
    return (test ? 0 : 1);
}
string fun(string s) {
    for (int i = s.size() - 1; i >= 0; i --) {
        if (s[i] != ' ') return s.substr(0, i);
    }
    return "";
}
string Jduge(int i) {
    bool bbb;
    // TimerClock TC;
    /*
    对于TLE的判定有待开发，现在TLE也会判定到WA上
    */
    // system("cd std");
    bbb = system("std.exe");
    Sleep(1000);
    system("tskill std.exe");
    if (bbb) {
        // logg << "RE\n";
        return "RE on #" + to_string(i) + "\n";
    }
    ifstream ans("data\\out" + to_string(i) + ".out");
    // while (1) {
        string ch, ch2;
        while (getline(ans, ch)) {
            getline(cin, ch2);
            ch = fun(ch); ch2 = fun(ch2);
            if (ch2 != ch) {
                return "WA on #" + to_string(i) + "\n";
            }
        }
    // }
    return "AC on #" + to_string(i) + "\n";
}
int main() {
	ios::sync_with_stdio(false);
    int num;
    ifstream fin("config\\number.txt");
    fin >> num;
    system("g++ std.cpp -o std.exe");
    if (CE()) {
        // cout << "CE!";
        logg << "CE\n";
        return 0;
    }
    for (int i = 1; i <= num; i ++) {
        string sys = "data\\in" + to_string(i)+ ".in";
        freopen(sys.c_str(), "r", stdin);
        sys = "ans\\out" + to_string(i)+ ".out";
        freopen(sys.c_str(), "w", stdout);
        logg << Jduge(i) << "\n";
    }
	return 0;
}