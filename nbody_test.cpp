/*
# Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: X11
*/

#include "nbody.h"

// ********************************************************
int main() {
    float particles[75];
    float original_particles[75];
    float a;
    float b;
    float c;
    float d;
    float e;


    for (int i = 0; i < 75; i += 5){
        a = 0.1f * i;
        b = 0.2f * i;
        c = 0.3f * i;
        d = 0.4f * i;
        e = 0.5f * i;

        particles[i] = a;
        particles[i+1] = b;
        particles[i+2] = c;
        particles[i+3] = d;
        particles[i+4] = e;

        original_particles[i] = a;
        original_particles[i+1] = b;
        original_particles[i+2] = c;
        original_particles[i+3] = d;
        original_particles[i+4] = e;
    }

    nBodySimulation2D(particles);


    bool passed = false;
	for (int i = 0; i < 75; i ++){
        if (original_particles[i] != particles[i]){
            passed = true;
        }
    }

    if (passed){
        printf("Nbody ran through successfully!\n");
    }else{
        printf("Nbody failed!\n");
    }
    
    return 0;
}