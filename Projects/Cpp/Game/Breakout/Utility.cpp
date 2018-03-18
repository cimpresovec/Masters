#include "Utility.hpp"

Vector2 normalizeVector2(const Vector2& vec)
{
    float len = sqrtf(vec.x * vec.x + vec.y * vec.y);
    return Vector2{vec.x / len, vec.y / len};
}

float vector2Length(const Vector2& vec)
{
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

Vector2 operator+(const Vector2& a, const Vector2& b)
{
    return Vector2{a.x + b.x, a.y + b.y};
}

Vector2 operator*(const Vector2& a, float k)
{
    return Vector2{a.x * k, a.y * k};
}
