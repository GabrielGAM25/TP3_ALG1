#include "Stopover.h"

Stopover::Stopover(int time, int price) {
  this->time = time;
  this->price = price;
}

int Stopover::getTime() {
  return time;
}

float Stopover::getPrice(float discount) {
  float floatPrice = (float) price;
  float priceWithDiscount = floatPrice - (floatPrice * discount);

  return priceWithDiscount;
}
