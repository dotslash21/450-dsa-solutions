/**
 * @file print_sentence_from_word_list.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/recursively-print-all-sentences-that-can-be-formed-from-list-of-word-lists/
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<string>> &mat, int idx, vector<string> &result) {
    if (idx == mat.size()) {
        for (string s : result) {
            cout << s << " ";
        }
        cout << "\n";
        
        return;
    }

    for (int i = 0; i < mat[idx].size(); i++) {
        result.push_back(mat[idx][i]);
        print(mat, idx + 1, result);
        result.pop_back();
    }
}

void print(vector<vector<string>> &mat) {
    vector<string> result;
    print(mat, 0, result);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r , c;
        cin >> r >> c;
        vector<vector<string>> mat(r, vector<string>(c));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> mat[i][j];
            }
        }
        print(mat);
    }
}