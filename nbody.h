#include <iostream>
#include "ap_fixed.h"

#define INPUT_LENGTH (10000)
// typedef ap_fixed<16,8,  AP_RND, AP_WRAP> fixed_t;
typedef ap_fixed<32, 16> fixed_t;
extern "C"
{
  // void nBodySimulation2D(float *particles);
  void nBodySimulation2D(float *particles, float *temp);
  // void nBodySimulation2D(fixed_t *particles, fixed_t *temp);
}
