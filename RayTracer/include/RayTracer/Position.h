#pragma once

#include <Eigen/Core>
#include "Direction.h"

class Position
{
public:
    Position(float x, float y, float z);

    float X() const;
    float Y() const;
    float Z() const;

    float Dot(const Position& other);
    float Dot(const Direction& direction);

    Direction ToDirection() const;

    Position operator+(const Position& other) const;
    Position operator+(const Direction& direction) const;
    Position operator-(const Position& other) const;
private:
    Position(const Eigen::Vector3f& position);

    Eigen::Vector3f _position;
};