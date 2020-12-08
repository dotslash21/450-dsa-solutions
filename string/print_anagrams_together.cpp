/**
 * @file print_anagrams_together.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/k-anagrams-1/0
 * @version 0.1
 * @date 2020-12-08
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &string_list);

//User function Template for C++

vector<vector<string>> Anagrams(vector<string> &string_list)
{
    unordered_map<string, vector<string>> groups;

    for (string str : string_list)
    {
        string sorted = str;
        sort(sorted.begin(), sorted.end());
        groups[sorted].push_back(str);
    }

    vector<vector<string>> result;
    for (auto it : groups)
    {
        result.push_back(it.second);
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin >> string_list[i];
        vector<vector<string>> result = Anagrams(string_list);
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}