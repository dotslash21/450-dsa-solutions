/**
 * @file rabin_karp.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

class RollingHash
{
public:
    string text;
    int wordSize;
    int hash;
    int windowStart;
    int windowEnd;

    RollingHash(string const &t, int const &s)
    {
        text = t;
        wordSize = s;
        hash = 0;

        for (int i = 0; i < wordSize; i++)
        {
            hash += (text[i] - 'a' + 1) * pow(26, wordSize - i - 1);
        }

        windowStart = 0;
        windowEnd = wordSize;
    }

    void moveWindow()
    {
        if (windowEnd < text.size())
        {
            hash -= (text[windowStart] - 'a' + 1) * pow(26, wordSize - 1);
            hash *= 26;
            hash += text[windowEnd] - 'a' + 1;
            windowStart++;
            windowEnd++;
        }
    }

    string windowText()
    {
        return text.substr(windowStart, wordSize);
    }
};

vector<int> rabinKarp(string const &text, string const &word)
{
    int m = text.size();
    int n = word.size();

    if (n == 0 || m == 0 || n > m)
        return {};

    RollingHash rollingHash(text, n);
    RollingHash wordHash(word, n);

    vector<int> occurrences;
    for (int i = 0; i < m - n + 1; i++)
    {
        if (rollingHash.hash == wordHash.hash &&
            word.compare(rollingHash.windowText()) == 0)
        {
            occurrences.push_back(i);
        }

        rollingHash.moveWindow();
    }

    return occurrences;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string text, pattern;
        cin >> text;
        cin >> pattern;

        vector<int> occurrences = rabinKarp(text, pattern);
        for (int i = 0; i < occurrences.size(); i++)
        {
            cout << occurrences[i] << " ";
        }
        cout << "\n";
    }
}