/**
 * @file isomorphic_strings.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1#
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin >> t;
    string s1, s2;
    while (t--)
    {
        cin >> s1;
        cin >> s2;
        cout << areIsomorphic(s1, s2) << endl;
    }

    return 0;
}

// This function returns true if str1 and str2 are ismorphic
// else returns false
bool areIsomorphic(string str1, string str2)
{
    if (str1.size() != str2.size())
    {
        return false;
    }

    char map1[MAX_CHARS];
    memset(map1, -1, sizeof(map1));
    char map2[MAX_CHARS];
    memset(map2, -1, sizeof(map2));

    for (int i = 0; i < str1.size(); i++)
    {
        if (map1[str1[i]] != -1 && map1[str1[i]] != str2[i])
            return false;
        
        map1[str1[i]] = str2[i];

        if (map2[str2[i]] != -1 && map2[str2[i]] != str1[i])
            return false;
        
        map2[str2[i]] = str1[i];
    }

    return true;
}