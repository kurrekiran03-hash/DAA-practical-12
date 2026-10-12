
#include <iostream>
#include <climits>
using namespace std;

int cost[10][10];
bool visited[10];
int n;
int minCost = INT_MAX;

void tsp(int city, int count, int currentCost) {
    if (count == n) {
        if (cost[city][0] != 0) {
            int totalCost = currentCost + cost[city][0];

            if (totalCost < minCost) {
                minCost = totalCost;
            }
        }
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[city][i] != 0) {
            visited[i] = true;

            tsp(i, count + 1, currentCost + cost[city][i]);

            visited[i] = false;
        }
    }
}

int main() {
    cout << "Enter number of cities: ";
    cin >> n;

    cout << "Enter cost matrix:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    visited[0] = true;
    tsp(0, 1, 0);

    if (minCost == INT_MAX)
        cout << "No complete tour exists.\n";
    else
        cout << "Minimum tour cost = " << minCost << endl;

    return 0;
}
