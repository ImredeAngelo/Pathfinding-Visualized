#pragma once

namespace Math {
    /// Returns 1/sqrt(x)
    float InvSqr(float x);

    template <typename T>
    T Abs(T x) {
        return x * ((x > 0 ) - (x < 0));
    }

    template <typename T>
    T Max(T a, T b) {
        return a * (a >= b) + b * (a < b);
    }

    template <typename T>
    T Min(T a, T b) {
        return a * (a <= b) + b * (a > b);
    }
}
