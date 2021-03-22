#include "CostCalculator.h"

vector<Stopover> CostCalculator::stopovers;
vector<double> CostCalculator::discounts;
int CostCalculator::maxStopovers;
int CostCalculator::maxDiscountTime;
int CostCalculator::stopoversCount;
double** CostCalculator::costs;

void CostCalculator::initialize(vector<Stopover> stopovers, vector<double> discounts, int maxStopovers, int maxDiscountTime, int stopoversCount) {
  CostCalculator::stopovers = stopovers;
  CostCalculator::discounts = discounts;
  CostCalculator::maxStopovers = maxStopovers;
  CostCalculator::maxDiscountTime = maxDiscountTime;
  CostCalculator::stopoversCount = stopoversCount;

  costs = (double**)malloc(stopoversCount * sizeof(double));
  for (int i = 0; i < stopoversCount; i++) {
    costs[i] = (double*)malloc(stopoversCount * sizeof(double));
  }
}

double CostCalculator::getMinFromCol(int col) {
  if (col < 0) return 0;

  double min = costs[0][col];
  for (int row = 1; row <= col; row++) {
    double cost = costs[row][col];
    if (cost < min && cost > 0) {
      min = cost;
    }
  }

  return min;
}

double CostCalculator::getMinCost() {
  for (int i = 0; i < stopoversCount; i++) {
    int currentTime = 0;
    int stopoversInInterval = 0;
    double currentDiscount = 0;
    double prevCost = getMinFromCol(i - 1);

    for (int j = i; j < stopoversCount; j++) {
      Stopover stopover = stopovers.at(j);

      currentDiscount += discounts.at(stopoversInInterval);
      costs[i][j] = prevCost + stopover.getPrice(currentDiscount / 100);

      prevCost = costs[i][j];
      stopoversInInterval++;
      currentTime += stopover.getTime();

      if (currentTime >= maxDiscountTime || stopoversInInterval >= maxStopovers) {
        currentDiscount = 0;
        currentTime = 0;
        stopoversInInterval = 0;
      }
    }
  }

  return getMinFromCol(stopoversCount - 1);
}
