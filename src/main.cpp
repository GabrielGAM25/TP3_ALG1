#include <iostream>
#include <vector>
#include <iomanip>

#include "Stopover.h"
#include "CostCalculator.h"

using namespace std;

vector<double> readDiscounts(int maxStopovers) {
  vector<double> discounts;

  for (int i = 0; i < maxStopovers; i++) {
    int discount;
    cin >> discount;
    discounts.push_back(discount);
  }

  return discounts;
}

vector<Stopover> readStopovers(int stopoversCount) {
  vector <Stopover> stopovers;

  for (int i = 0; i < stopoversCount; i++) {
    int time, price;
    cin >> time >> price;
    stopovers.push_back(Stopover(time, price));
  }

  return stopovers;
}

int main() {
  int stopoversCount = 0;
  int maxStopovers = 0;
  int maxDiscountTime = 0;

  cin >> stopoversCount >> maxStopovers >> maxDiscountTime;

  vector<double> discounts = readDiscounts(maxStopovers);
  vector <Stopover> stopovers = readStopovers(stopoversCount);

  CostCalculator::initialize(stopovers, discounts, maxStopovers, maxDiscountTime, stopoversCount);
  cout << fixed << setprecision(2) << CostCalculator::getMinCost() << endl;

  return 0;
}