/**
 * @file rearrange_characters.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/rearrange-characters/0
 * @version 0.1
 * @date 2020-12-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct CharCount
{
    char character;
    int count;

    CharCount(char ch, int c)
    {
        character = ch;
        count = c;
    }

    bool operator<(const CharCount &c) const
    {
        return count < c.count;
    }
};

int canRearrange(string str)
{
    int n = str.size();

    // Count the frequencies of all characters in the string.
    int count[26] = {0};
    for (int i = 0; i < n; i++)
        count[str[i] - 'a']++;

    // Push the character frequency struct to the priority queue.
    priority_queue<CharCount> pq;
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > 0)
            pq.push(CharCount('a' + i, count[i]));
    }

    // Store the rearranged string.
    string rearranged = "";

    // Keep track of previously popped character count.
    CharCount prev{'#', -1};

    // Traverse the queue
    while (!pq.empty())
    {
        // Pop the top element of the queue and add to rearranged string.
        CharCount charCount = pq.top();
        pq.pop();
        rearranged += charCount.character;

        // Check if count of previous character is zero.
        // If zero then it's usless to push it back.
        if (prev.count > 0)
            pq.push(prev);

        // Decrease the count of the current character by one.
        charCount.count--;
        // Make the current character as the previous.
        prev = charCount;
    }

    // If length of the resultant string is not equal to original
    // then no such string can be made.
    if (!(rearranged.size() == n))
        return 0;
    else
        return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << canRearrange(s) << "\n";
    }

    return 0;
}