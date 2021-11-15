#include "Math.h"

// C++20 recommends using bit_cast but this is too beautiful to change
float Math::InvSqr(float y) {
    long i;
    float x2 = y*0.5f;

    i = *(long*)&y;             // "Evil bit level hack" aka. type punning float to integer
    i = 0x5F3759DF - (i >> 1);  // "What the fuck" aka. approximation of log2(x)
    y = *(float*)&i;

    //Newton's method
    const float threehalfs = 1.5f;
    y *= (threehalfs - x2 * y * y);

    return y;
}
