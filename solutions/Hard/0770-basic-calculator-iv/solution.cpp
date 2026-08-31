// ──────────────────────────────────────────────────
// Problem  : 770. Basic Calculator IV
// Difficulty: Hard
// Tags     : Hash Table, Math, String, Stack, Recursion
// Link     : https://leetcode.com/problems/basic-calculator-iv/
// Runtime  : 0 ms (beats 0%)
// Memory   : 9064000 (beats 0%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

class Solution {
    class Term {
    public:
        int coeff;
        vector<string> vars;

        Term(int c = 0, vector<string> v = {}) : coeff(c), vars(v) {}

        bool operator<(const Term& other) const {
            if (vars.size() != other.vars.size()) {
                return vars.size() > other.vars.size();
            }
            return vars < other.vars;
        }
    };

    class Poly {
    public:
        map<vector<string>, int> terms;

        Poly(int c = 0, const string& name = "") {
            if (c != 0) {
                terms[{}] = c;
            } else if (!name.empty()) {
                terms[{name}] = 1;
            }
        }

        Poly add(const Poly& other) const {
            Poly res = *this;
            for (auto& pair : other.terms) {
                res.terms[pair.first] += pair.second;
                if (res.terms[pair.first] == 0) {
                    res.terms.erase(pair.first);
                }
            }
            return res;
        }

        Poly sub(const Poly& other) const {
            Poly res = *this;
            for (auto& pair : other.terms) {
                res.terms[pair.first] -= pair.second;
                if (res.terms[pair.first] == 0) {
                    res.terms.erase(pair.first);
                }
            }
            return res;
        }

        Poly mul(const Poly& other) const {
            Poly res;
            for (auto& p1 : terms) {
                for (auto& p2 : other.terms) {
                    int c = p1.second * p2.second;
                    if (c == 0) continue;
                    vector<string> v = p1.first;
                    v.insert(v.end(), p2.first.begin(), p2.first.end());
                    sort(v.begin(), v.end());
                    res.terms[v] += c;
                    if (res.terms[v] == 0) {
                        res.terms.erase(v);
                    }
                }
            }
            return res;
        }

        vector<string> toList() const {
            vector<Term> vec;
            for (auto& pair : terms) {
                if (pair.second != 0) {
                    vec.push_back(Term(pair.second, pair.first));
                }
            }
            sort(vec.begin(), vec.end());
            vector<string> res;
            for (auto& t : vec) {
                string s = to_string(t.coeff);
                for (auto& v : t.vars) {
                    s += "*" + v;
                }
                res.push_back(s);
            }
            return res;
        }
    };

    Poly parseToken(const string& token) {
        if (isdigit(token[0]) || token[0] == '-') {
            return Poly(stoi(token));
        }
        return Poly(0, token);
    }

public:
    vector<string> basicCalculatorIV(string expression, vector<string>& evalvars, vector<int>& evalints) {
        map<string, int> evalMap;
        for (int i = 0; i < evalvars.size(); ++i) {
            evalMap[evalvars[i]] = evalints[i];
        }

        vector<string> tokens;
        string token;
        for (int i = 0; i < expression.length(); ) {
            if (expression[i] == ' ') {
                i++;
                continue;
            }
            if (expression[i] == '(' || expression[i] == ')' || expression[i] == '+' || expression[i] == '-' || expression[i] == '*') {
                tokens.push_back(string(1, expression[i]));
                i++;
            } else {
                int j = i;
                while (j < expression.length() && expression[j] != ' ' && expression[j] != '(' && expression[j] != ')' && expression[j] != '+' && expression[j] != '-' && expression[j] != '*') {
                    j++;
                }
                tokens.push_back(expression.substr(i, j - i));
                i = j;
            }
        }

        vector<Poly> operands;
        vector<char> operators;

        auto precedence = [](char op) {
            if (op == '*') return 2;
            if (op == '+' || op == '-') return 1;
            return 0;
        };

        auto applyOp = [](const Poly& a, const Poly& b, char op) {
            if (op == '+') return a.add(b);
            if (op == '-') return a.sub(b);
            return a.mul(b);
        };

        for (int i = 0; i < tokens.size(); ++i) {
            string t = tokens[i];
            if (t == "(") {
                operators.push_back('(');
            } else if (t == ")") {
                while (!operators.empty() && operators.back() != '(') {
                    Poly b = operands.back(); operands.pop_back();
                    Poly a = operands.back(); operands.pop_back();
                    char op = operators.back(); operators.pop_back();
                    operands.push_back(applyOp(a, b, op));
                }
                operators.pop_back();
            } else if (t == "+" || t == "-" || t == "*") {
                char op = t[0];
                while (!operators.empty() && precedence(operators.back()) >= precedence(op)) {
                    Poly b = operands.back(); operands.pop_back();
                    Poly a = operands.back(); operands.pop_back();
                    char opTop = operators.back(); operators.pop_back();
                    operands.push_back(applyOp(a, b, opTop));
                }
                operators.push_back(op);
            } else {
                if (evalMap.count(t)) {
                    operands.push_back(Poly(evalMap[t]));
                } else {
                    operands.push_back(parseToken(t));
                }
            }
        }

        while (!operators.empty()) {
            Poly b = operands.back(); operands.pop_back();
            Poly a = operands.back(); operands.pop_back();
            char op = operators.back(); operators.pop_back();
            operands.push_back(applyOp(a, b, op));
        }

        Poly result = operands.empty() ? Poly(0) : operands.back();
        return result.toList();
    }
};