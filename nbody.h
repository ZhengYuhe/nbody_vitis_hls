#include <iostream>
#include "ap_fixed.h"

#define INPUT_LENGTH (100)
typedef ap_fixed<16, 8, > fixed_t;

extern "C"
{
  // void nBodySimulation2D(float *particles);
  void nBodySimulation2D(float *particles, float *temp);
}
