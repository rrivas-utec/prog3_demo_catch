//
// Created by rudri on 6/9/2024.
//

#include "demo.h"

uint32_t factorial( uint32_t number ) {
  uint32_t result = 1;
  for (int i = 1; i <= number; ++i)
    result *= i;
  return result;
}