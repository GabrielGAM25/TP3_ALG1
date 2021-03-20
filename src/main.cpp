#include <iostream>
#include <vector>
#include <iomanip>

#include "Stopover.h"

using namespace std;

double getMinFromCol(double** costs, int col, int rowsCount) {
  if (col < 0) return 0;

  double min = costs[0][col];
  for (int row = 1; row < rowsCount; row++) {
    double cost = costs[row][col];
    if (cost < min && cost > 0) {
      min = cost;
    }
  }

  return min;
}

void buildCostsRow(int stopoversCount, int maxStopovers, int discountTime, vector<Stopover> stopovers, vector<double> discounts, int start, int end, double** costs) {
  int currentTime = 0;
  double currentDiscount = 0;
  int stopoversInInterval = 0;
  double prevCost = getMinFromCol(costs, start - 1, stopoversCount);

  for (int j = start; j < end; j++) {
    Stopover stopover = stopovers.at(j);

    if (stopoversInInterval < maxStopovers) {
      currentDiscount += discounts.at(stopoversInInterval);
    }
    else {
      currentDiscount = 0;
    }

    costs[start][j] = prevCost + stopover.getPrice(currentDiscount / 100);
    prevCost = costs[start][j];
    stopoversInInterval++;
    currentTime += stopover.getTime();

    if (currentTime >= discountTime) {
      currentDiscount = 0;
      currentTime = 0;
      stopoversInInterval = 0;
    }
  }
}

int main() {
  int stopoversCount = 0;
  int maxStopovers = 0;
  int discountTime = 0;

  cin >> stopoversCount >> maxStopovers >> discountTime;

  vector<double> discounts;

  for (int i = 0; i < maxStopovers; i++) {
    int discount;
    cin >> discount;

    discounts.push_back(discount);
  }

  vector <Stopover> stopovers;

  for (int i = 0; i < stopoversCount; i++) {
    int time;
    int price;

    cin >> time >> price;

    stopovers.push_back(Stopover(time, price));
  }

  double** costs = (double**)malloc(stopoversCount * sizeof(double));
  for (int i = 0; i < stopoversCount; i++) {
    costs[i] = (double*)malloc(stopoversCount * sizeof(double));
  }

  for (int i = 0; i < stopoversCount; i++) {
    buildCostsRow(stopoversCount, maxStopovers, discountTime, stopovers, discounts, i, stopoversCount, costs);
  }

  cout << endl;
  for (int i = 0; i < stopoversCount; i++) {
    for (int j = 0; j < stopoversCount; j++) {
      cout << setw(8) << setfill(' ') << costs[i][j] << "   ";
    }

    cout << endl;
  }

  double minCost = getMinFromCol(costs, stopoversCount - 1, stopoversCount);
  cout << fixed << setprecision(2) << minCost << endl;

  return 0;
}