// ──────────────────────────────────────────────────
// Problem  : 1169. Invalid Transactions
// Difficulty: Medium
// Tags     : Array, Hash Table, String, Sorting
// Link     : https://leetcode.com/problems/invalid-transactions/
// Runtime  : 31 ms (beats 35%)
// Memory   : 17524000 (beats 70%)
// Language : cpp
// Copyright: (c) 2026 Srisakthi61. All rights reserved.
// Synced by: leetie
// ──────────────────────────────────────────────────

class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        struct Transaction {
            string name;
            int time;
            int amount;
            string city;
            string original;
            int index;
        };

        int n = transactions.size();
        vector<Transaction> txs(n);
        vector<bool> invalid(n, false);

        for (int i = 0; i < n; ++i) {
            stringstream ss(transactions[i]);
            string name, timeStr, amountStr, city;
            getline(ss, name, ',');
            getline(ss, timeStr, ',');
            getline(ss, amountStr, ',');
            getline(ss, city, ',');

            txs[i] = {name, stoi(timeStr), stoi(amountStr), city, transactions[i], i};
            
            if (txs[i].amount > 1000) {
                invalid[i] = true;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (txs[i].name == txs[j].name && txs[i].city != txs[j].city) {
                    if (abs(txs[i].time - txs[j].time) <= 60) {
                        invalid[i] = true;
                        invalid[j] = true;
                    }
                }
            }
        }

        vector<string> result;
        for (int i = 0; i < n; ++i) {
            if (invalid[i]) {
                result.push_back(txs[i].original);
            }
        }

        return result;
    }
};