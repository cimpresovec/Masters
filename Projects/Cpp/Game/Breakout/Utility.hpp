#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <cmath>
#include <raylib.h>

Vector2 normalizeVector2(const Vector2& vec);

float vector2Length(const Vector2& vec);

Vector2 operator+(const Vector2& a, const Vector2& b);

Vector2 operator*(const Vector2& a, const float k);

#endif // UTILITY_HPP
