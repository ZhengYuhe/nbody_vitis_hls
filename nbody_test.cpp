/*
# Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: X11
*/

#include "nbody.h"
#include <cmath>

// ********************************************************
int main()
{
    printf("Starting Nbody sims....\n");
    fixed_t particles[150];
    fixed_t original_particles[150];
    fixed_t temp[150];
    fixed_t a;
    fixed_t b;
    fixed_t c;
    fixed_t d;
    fixed_t e;

    for (int i = 0; i < 150; i += 5)
    {
        a = 0.1 * i;
        b = 0.2 * i;
        c = 0.3 * i;
        d = 0.4 * i;
        e = 0.5 * i;

        particles[i] = a;
        particles[i + 1] = b;
        particles[i + 2] = c;
        particles[i + 3] = d;
        particles[i + 4] = e;

        original_particles[i] = a;
        original_particles[i + 1] = b;
        original_particles[i + 2] = c;
        original_particles[i + 3] = d;
        original_particles[i + 4] = e;
    }

    printf("Nbody Initialised particles!\n");
    nBodySimulation2D(particles, temp);

    bool passed = false;
    for (int i = 0; i < 150; i++)
    {
        if (original_particles[i] != particles[i])
        {
            passed = true;
        }
    }

    if (passed)
    {
        printf("Nbody ran through successfully!\n");
    }
    else
    {
        printf("Nbody failed!\n");
    }

    // Declare variables of the custom fixed-point type
    // fixed_t customValue1 = 2.5;
    // fixed_t customValue2 = 1.150;

    // // Perform arithmetic operations with custom fixed-point numbers
    // fixed_t customSum = customValue1 + customValue2;
    // fixed_t customProduct = customValue1 * customValue2;
    // double customSqrtValue = std::sqrt(customProduct.to_double());
    // fixed_t test = static_cast<fixed_t>(customSqrtValue);
    // // Convert custom fixed-point numbers to double for printing
    // double customValue1_double = customValue1.to_double();
    // double customValue2_double = customValue2.to_double();
    // double customSum_double = customSum.to_double();
    // double customProduct_double = customProduct.to_double();

    // // Print the results
    // std::cout << "customValue1 = " << customValue1_double << " (" << customValue1 << ")" << std::endl;
    // std::cout << "customValue2 = " << customValue2_double << " (" << customValue2 << ")" << std::endl;
    // std::cout << "customValue1 + customValue2 = " << customSum_double << " (" << customSum << ")" << std::endl;
    // std::cout << "customValue1 * customValue2 = " << customProduct_double << " (" << customProduct << ")" << std::endl;

    return 0;
}