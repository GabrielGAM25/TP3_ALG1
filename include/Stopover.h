#ifndef Point_H
#define Point_H

class Stopover {
private:
  int time;
  int price;

public:
  Stopover() {};
  Stopover(int time, int price);
  int getTime();
  double getPrice(double discount);
};

#endif
