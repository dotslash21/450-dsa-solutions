/**
 * @file max_rectangle.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://practice.geeksforgeeks.org/problems/max-rectangle/1
 * @version 0.1
 * @date 2020-11-19
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int maxArea(int M[MAX][MAX], int n, int m);
int main()
{
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--)
    {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}

int maxAreaUnderHistogram(vector<int> &histograms, int n)
{
    int area = 0;
    int maxArea = 0;
    stack<int> st;

    int i = 0;
    while (i < n)
    {
        if (st.empty() || histograms[st.top()] <= histograms[i])
        {
            st.push(i++);
        }
        else
        {
            int top = st.top();
            st.pop();

            if (st.empty())
            {
                area = histograms[top] * i;
            }
            else
            {
                area = histograms[top] * (i - st.top() - 1);
            }

            maxArea = max(maxArea, area);
        }
    }

    while (!st.empty())
    {
        int top = st.top();
        st.pop();

        if (st.empty())
        {
            area = histograms[top] * i;
        }
        else
        {
            area = histograms[top] * (i - st.top() - 1);
        }

        maxArea = max(maxArea, area);
    }

    return maxArea;
}

/*You are required to complete this method*/
int maxArea(int M[MAX][MAX], int n, int m)
{
    int maxArea = 0;
    vector<int> histograms(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            histograms[j] = (M[i][j] == 0) ? 0 : histograms[j] + 1;
        }

        int area = maxAreaUnderHistogram(histograms, m);
        maxArea = max(maxArea, area);
    }

    return maxArea;
}