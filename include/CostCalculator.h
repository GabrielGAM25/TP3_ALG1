#ifndef CostCalculator_H
#define CostCalculator_H

#include <iostream>
#include <vector>

#include "Stopover.h"

using namespace std;

class CostCalculator {
private:
  static vector<Stopover> stopovers;
  static vector<double> discounts;
  static int maxStopovers;
  static int maxDiscountTime;
  static int stopoversCount;
  static double** costs;
  static double getMinFromCol(int col);

public:
  CostCalculator() {};
  static void initialize(vector<Stopover> stopovers, vector<double> discounts, int maxStopovers, int maxDiscountTime, int stopoversCount);
  static double getMinCost();
};

#endif
