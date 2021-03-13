#include <iostream>
#include <vector>
#include <iomanip>

#include "Stopover.h"

using namespace std;

int main() {
  int stopoversCount = 0;
  int maxStopovers = 0;
  int discountTime = 0;

  cin >> stopoversCount >> maxStopovers >> discountTime;

  vector<float> discounts;

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

  int currentTime = 0;
  float currentDiscount = 0;
  int stopoversInInterval = 0;
  float cost = 0;

  for (int i = 0; i < stopoversCount; i++) {
    Stopover stopover = stopovers.at(i);

    if (stopoversInInterval < maxStopovers && stopoversInInterval > 0) {
      currentDiscount += discounts.at(stopoversInInterval - 1);
    } else {
      currentDiscount = 0;
    }

    cost += stopover.getPrice(currentDiscount / 100);
    stopoversInInterval++;
    currentTime += stopover.getTime();

    if (currentTime > discountTime) {
      currentDiscount = 0;
      currentTime = 0;
      stopoversInInterval = 1;
    }
  }

  cout << setprecision(2) << fixed << cost;
  return 0;
}