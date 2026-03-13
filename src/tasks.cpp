// Copyright 2025 UNN-CS
#include "tasks.h"
#include "circle.h"

double ropeGap(double earthRadius, double addedLength) {
  Circle earth(earthRadius);
  double oldRadius = earth.getRadius();
  earth.setFerence(earth.getFerence() + addedLength);
  return earth.getRadius() - oldRadius;
}

double poolConcreteCost(double poolRadius, double walkwayWidth,
                        double pricePerSqm) {
  Circle pool(poolRadius);
  Circle outer(poolRadius + walkwayWidth);
  double walkwayArea = outer.getArea() - pool.getArea();
  return walkwayArea * pricePerSqm;
}

double poolFenceCost(double poolRadius, double walkwayWidth,
                     double pricePerM) {
  Circle outer(poolRadius + walkwayWidth);
  return outer.getFerence() * pricePerM;
}
