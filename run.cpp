#include <bits/stdc++.h>
#include "include/TimerClock.h"
using namespace std;
ofstream logg("log\\log.log");
bool CE() {
    ifstream test("std\\std.exe");
    return (test ? 0 : 1);
}
string Jduge(int i) {
    bool bbb;
    system("cd std");
    bbb = system("std.exe");
    if (bbb) {
        // logg << "RE\n";
        return "RE";
    }
    ifstream ans("data\\out" + to_string(i) + ".out");
    while (1) {
        char ch, ch2;
        while (ans >> ch) {
            cin >> ch2;
            if (ch2 != ch) {
                
            }
        }
    }
}
int main() {
	ios::sync_with_stdio(false);
    TimerClock TC;
    int num;
    ifstream fin("config\\number.txt");
    fin >> num;
    system("g++ std\\std.cpp -o std\\std.exe");
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
        logg << Jduge(i) << " on #" << i << "\n";
    }
	return 0;
}