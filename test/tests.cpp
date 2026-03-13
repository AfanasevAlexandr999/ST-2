// Copyright 2025 UNN-CS Team

#include <gtest/gtest.h>
#include <cstdint>
#include <cmath>
#include "circle.h"
#include "tasks.h"

const double PI = 3.14159265358979323846;


TEST(CircleTest, ConstructorSetsRadius) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 5.0);
}

TEST(CircleTest, ConstructorCalculatesFerence) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * PI * 5.0);
}

TEST(CircleTest, ConstructorCalculatesArea) {
  Circle c(5.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 25.0);
}


TEST(CircleTest, SetRadiusUpdatesRadius) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 10.0);
}

TEST(CircleTest, SetRadiusRecalculatesFerence) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * PI * 10.0);
}

TEST(CircleTest, SetRadiusRecalculatesArea) {
  Circle c(1.0);
  c.setRadius(10.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 100.0);
}

TEST(CircleTest, SetFerenceUpdatesFerence) {
  Circle c(1.0);
  c.setFerence(2.0 * PI * 7.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * PI * 7.0);
}

TEST(CircleTest, SetFerenceRecalculatesRadius) {
  Circle c(1.0);
  c.setFerence(2.0 * PI * 7.0);
  EXPECT_NEAR(c.getRadius(), 7.0, 1e-10);
}

TEST(CircleTest, SetFerenceRecalculatesArea) {
  Circle c(1.0);
  c.setFerence(2.0 * PI * 7.0);
  EXPECT_NEAR(c.getArea(), PI * 49.0, 1e-10);
}

TEST(CircleTest, SetAreaUpdatesArea) {
  Circle c(1.0);
  c.setArea(PI * 16.0);
  EXPECT_NEAR(c.getArea(), PI * 16.0, 1e-10);
}

TEST(CircleTest, SetAreaRecalculatesRadius) {
  Circle c(1.0);
  c.setArea(PI * 16.0);
  EXPECT_NEAR(c.getRadius(), 4.0, 1e-10);
}

TEST(CircleTest, SetAreaRecalculatesFerence) {
  Circle c(1.0);
  c.setArea(PI * 16.0);
  EXPECT_NEAR(c.getFerence(), 2.0 * PI * 4.0, 1e-10);
}

TEST(CircleTest, UnitCircleValues) {
  Circle c(1.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * PI);
  EXPECT_DOUBLE_EQ(c.getArea(), PI);
}

TEST(CircleTest, LargeRadius) {
  Circle c(1000000.0);
  EXPECT_DOUBLE_EQ(c.getRadius(), 1000000.0);
  EXPECT_DOUBLE_EQ(c.getFerence(), 2.0 * PI * 1000000.0);
  EXPECT_DOUBLE_EQ(c.getArea(), PI * 1e12);
}

TEST(CircleTest, SmallRadius) {
  Circle c(0.001);
  EXPECT_DOUBLE_EQ(c.getRadius(), 0.001);
  EXPECT_NEAR(c.getFerence(), 2.0 * PI * 0.001, 1e-15);
  EXPECT_NEAR(c.getArea(), PI * 1e-6, 1e-18);
}

EST(RopeTaskTest, EarthRopeGap) {
  double gap = ropeGap(6378100.0, 1.0);
  EXPECT_NEAR(gap, 1.0 / (2.0 * PI), 1e-6);
}

TEST(RopeTaskTest, SmallCircleRopeGap) {
  double gap = ropeGap(1.0, 1.0);
  EXPECT_NEAR(gap, 1.0 / (2.0 * PI), 1e-10);
}

TEST(RopeTaskTest, ZeroAddedLength) {
  double gap = ropeGap(100.0, 0.0);
  EXPECT_NEAR(gap, 0.0, 1e-10);
}

TEST(PoolTaskTest, ConcreteCostStandard) {
  double cost = poolConcreteCost(3.0, 1.0, 1000.0);
  double expectedArea = PI * 16.0 - PI * 9.0;
  EXPECT_NEAR(cost, expectedArea * 1000.0, 1e-6);
}

TEST(PoolTaskTest, FenceCostStandard) {
  double cost = poolFenceCost(3.0, 1.0, 2000.0);
  double expectedFerence = 2.0 * PI * 4.0;
  EXPECT_NEAR(cost, expectedFerence * 2000.0, 1e-6);
}

TEST(PoolTaskTest, ConcreteCostDifferentParams) {
  double cost = poolConcreteCost(5.0, 2.0, 500.0);
  double expectedArea = PI * 49.0 - PI * 25.0;
  EXPECT_NEAR(cost, expectedArea * 500.0, 1e-6);
}