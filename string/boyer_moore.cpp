/**
 * @file boyer_moore.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/boyer-moore-algorithm-for-pattern-searching/
 * @version 0.1
 * @date 2020-12-01
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#define NO_OF_CHARS 256
using namespace std;

// The preprocessing function for Boyer Moore's
// bad character heuristic
void fillBadCharTable(string pattern, int badCharTable[NO_OF_CHARS])
{
    // Initialize all occurrences as -1
    for (int i = 0; i < NO_OF_CHARS; i++)
        badCharTable[i] = -1;

    // Fill the actual value of last occurrence
    // of a character
    for (int i = 0; i < pattern.size(); i++)
        badCharTable[(int)pattern[i]] = i;
}

/* A pattern searching function that uses Bad
Character Heuristic of Boyer Moore Algorithm */
void searchBadCharHeuristic(string text, string pattern)
{
    int n = text.size(), m = pattern.size();

    // Check for edge cases
    if (n < m)
        return;

    int badCharTable[NO_OF_CHARS];

    /* Fill the bad character array by calling
    the preprocessing function fillBadCharTable()
    for given pattern */
    fillBadCharTable(pattern, badCharTable);

    int shift = 0; // shift of the pattern with respect to text
    while (shift <= (n - m))
    {
        int j = m - 1;

        /* Keep reducing index j of pattern while
        characters of pattern and text are
        matching at this shift s */
        while (j > -1 && pattern[j] == text[shift + j])
            j--;

        if (j == -1)
        {
            cout << "Pattern found at: " << shift << "\n";

            /* Shift the pattern so that the next
            character in text aligns with the last
            occurrence of it in pattern.
            The condition s+m < n is necessary for
            the case when pattern occurs at the end
            of text */
            shift += (shift + m < n) ? m - badCharTable[text[shift + m]] : 1;
        }
        else
        {
            /* Shift the pattern so that the bad character
            in text aligns with the last occurrence of
            it in pattern. The max function is used to
            make sure that we get a positive shift.
            We may get a negative shift if the last
            occurrence of bad character in pattern
            is on the right side of the current
            character. */
            shift += max(1, j - badCharTable[text[shift + j]]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string text, pattern;
        cin >> text >> pattern;

        searchBadCharHeuristic(text, pattern);
    }
}