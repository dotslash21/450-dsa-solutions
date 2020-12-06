/**
 * @file generate_valid_ips_from_string.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/
 * @version 0.1
 * @date 2020-12-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

bool is_segment_valid(string segment)
{
    if (segment.length() > 3 || stoi(segment) < 0 || stoi(segment) > 255)
        return false;

    if (segment.length() > 1 && stoi(segment) == 0)
        return false;

    if (segment.length() > 1 && stoi(segment) != 0 && segment[0] == '0')
        return false;

    return true;
}

void backtrack(string s, int start, vector<string> ip, vector<vector<string>> &ip_list)
{
    int n = s.size();

    if (start >= n && ip.size() == 4)
    {
        ip_list.push_back(ip);
    }

    if (start >= n || ip_list.size() == 4)
    {
        return;
    }

    for (int i = 1; i <= 3 && (start + i - 1) < n; i++)
    {
        string segment = s.substr(start, i);

        if (!is_segment_valid(segment))
        {
            continue;
        }

        ip.push_back(segment);
        backtrack(s, start + i, ip, ip_list);
        ip.pop_back();
    }
}

vector<string> generate(string s)
{
    vector<vector<string>> ip_list;
    backtrack(s, 0, {}, ip_list);

    vector<string> result(ip_list.size());
    for (int i = 0; i < result.size(); i++)
    {
        string ip = "";
        for (string segment : ip_list[i])
        {
            ip += segment + ".";
        }
        ip.pop_back();
        result[i] = ip;
    }

    return result;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        vector<string> ip_list = generate(s);
        for (string ip : ip_list)
        {
            cout << ip << "\n";
        }
    }
}