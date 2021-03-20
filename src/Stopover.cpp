#include "Stopover.h"

Stopover::Stopover(int time, int price) {
  this->time = time;
  this->price = price;
}

int Stopover::getTime() {
  return time;
}

double Stopover::getPrice(double discount) {
  double doublePrice = (double) price;
  double priceWithDiscount = doublePrice - (doublePrice * discount);

  return priceWithDiscount;
}
