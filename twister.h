//
// Created by victor on 10/02/17.
//

#ifndef PROJET_MOPSI_TWISTER_H
#define PROJET_MOPSI_TWISTER_H


class twister {

};
#include <stdint.h>

// Define MT19937 constants (32-bit RNG)
uint32_t ExtractU32();
static void Twist();
void Initialize(const uint32_t  seed);

#endif //PROJET_MOPSI_TWISTER_H
