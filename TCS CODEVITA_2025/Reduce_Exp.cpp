#include <bits/stdc++.h>
using namespace std;

struct Term {
    int coef;
    string var;
    Term(int c, string v) {
        coef = c;
        var = v;
    }
};

vector<Term> parse_expression(string s) {
    vector<Term> terms;
    int n = s.size();
    int i = 0;

    while (i < n) {
        int sign = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sign = -1;
            i++;
        }

        int coef = 0;
        bool hasCoef = false;
        while (i < n && isdigit(s[i])) {
            coef = coef * 10 + (s[i] - '0');
            i++;
            hasCoef = true;
        }

        string var = "";
        while (i < n && isalpha(s[i])) {
            var += s[i];
            i++;
        }

        if (!hasCoef) coef = 1;
        coef *= sign;
        terms.push_back(Term(coef, var));
    }

    return terms;
}

void combine_terms(vector<Term>& terms) {
    unordered_map<string, int> mp;
    for (auto &t : terms) {
        mp[t.var] += t.coef;
    }

    terms.clear();
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        string v = it->first;
        int c = it->second;
        if (c != 0)
            terms.push_back(Term(c, v));
    }
}

string to_string_expr(vector<Term> terms) {
    string ans = "";
    for (auto &t : terms) {
        if (t.coef > 0 && ans != "")
            ans += "+";
        if (t.coef == -1 && t.var != "")
            ans += "-";
        else if (t.coef != 1 || t.var == "")
            ans += to_string(t.coef);
        ans += t.var;
    }
    if (ans == "")
        ans = "0";
    return ans;
}

string simplify_expression(string expr) {
    vector<Term> terms = parse_expression(expr);
    combine_terms(terms);
    sort(terms.begin(), terms.end(), [](Term &a, Term &b) {
        return a.var < b.var;
    });
    return to_string_expr(terms);
}

int main() {
    string expr;
    cin >> expr;
    cout << simplify_expression(expr) << endl;
    return 0;
}
