/**
 * @file job_sequencing_problem.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/job-sequencing-problem/
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct Job {
    int number;
    int deadline;
    int profit;
};

bool compare(Job& a, Job& b) {
    return a.profit > b.profit;
}

int main() {
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Job> jobs(n);
        for (int i = 0; i < n; i++) {
            cin >> jobs[i].number >> jobs[i].deadline >> jobs[i].profit;
        }

        sort(jobs.begin(), jobs.end(), compare);

        int numJobs = 0;
        int totalProfit = 0;
        bool slot[n];
        memset(slot, false, sizeof(slot)/sizeof(bool));
        for (Job job : jobs) {
            for (int i = min(n, job.deadline) - 1; i > -1; i--) {
                if (slot[i] == false) {
                    slot[i] = true;
                    numJobs++;
                    totalProfit += job.profit;
                    break;
                }
            }
        }

        cout << numJobs << " " << totalProfit << "\n";
    }

    return 0;
}
