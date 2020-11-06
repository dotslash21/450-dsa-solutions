/**
 * @file water_connection_problem.cpp
 * @author Arunangshu Biswas (arunangshubsws@gmail.com)
 * @brief https://www.geeksforgeeks.org/water-connection-problem/
 * @version 0.1
 * @date 2020-11-06
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <bits/stdc++.h>
using namespace std;

struct House {
    int number;
    House* in;
    House* out;
    int outDiameter;

    House(int n) {
        number = n;
        in = NULL;
        out = NULL;
        outDiameter = -1;
    }
};

void explore(House* house) {
    House* ptr = house;
    int minDiameter = INT_MAX;
    while (ptr->out != NULL)
    {
        minDiameter = min(minDiameter, ptr->outDiameter);
        ptr = ptr->out;
    }
    cout << house->number << " " << ptr->number << " " << minDiameter << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<House*> houseList(n);
        for (int i = 0; i < n; i++) {
            House* house = new House(i + 1);
            houseList[i] = house;
        }
        for (int i = 0; i < p; i++) {
            int a, b, d;
            cin >> a >> b >> d;
            houseList[a-1]->out = houseList[b-1];
            houseList[b-1]->in = houseList[a-1];
            houseList[a-1]->outDiameter = d;
        }
        vector<House*> tanks;
        for (int i = 0; i < n; i++) {
            if (houseList[i]->in == NULL && houseList[i]->out != NULL) {
                tanks.push_back(houseList[i]);
            }
        }
        cout << tanks.size() << "\n";
        for (House* tank : tanks) {
            explore(tank);
        }
    }
}
