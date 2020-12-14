/**
 * @file customer_simulation.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/function-to-find-number-of-customers-who-could-not-get-a-computer/
 * @version 0.1
 * @date 2020-12-14
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

int runCustomerSimulation(int n, string seq)
{
    vector<int> cafe(26, 0);
    queue<char> waiting;

    int count = 0;
    for (char p : seq)
    {
        // Exit
        if (cafe[p - 'A'] == 1 || cafe[p - 'A'] == 2)
        {
            if (cafe[p - 'A'] == 2)
            {
                count++;
                n--;
            }

            cafe[p - 'A'] = 0;
            n++;

            while (!waiting.empty() && n > 0)
            {
                char w = waiting.front();
                waiting.pop();

                if (cafe[w - 'A'] == 2)
                {
                    cafe[w - 'A'] = 1;
                    n--;
                }
            }
        }

        // Entry
        else if (n > 0)
        {
            cafe[p - 'A'] = 1;
            n--;
        }
        else
        {
            cafe[p - 'A'] = 2;
            waiting.push(p);
        }
    }

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string seq;
        cin >> seq;
        cout << runCustomerSimulation(n, seq) << "\n";
    }

    return 0;
}