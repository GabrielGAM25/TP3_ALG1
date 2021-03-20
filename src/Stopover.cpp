#include "Stopover.h"

Stopover::Stopover(int time, int price) {
  this->time = time;
  this->price = price;
}

int Stopover::getTime() {
  return time;
}

double Stopover::getPrice(double discount) {
  double floatPrice = (double) price;
  double priceWithDiscount = floatPrice - (floatPrice * discount);

  return priceWithDiscount;
}
