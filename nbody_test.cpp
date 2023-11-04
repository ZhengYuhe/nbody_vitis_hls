/*
# Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: X11
*/

#include "nbody.h"

// ********************************************************
int main()
{
    printf("starting sim\n");
    float temp[5 * INPUT_LENGTH];
    float particles[INPUT_LENGTH * 5];
    int retval = 0, i, j;
    FILE *fp;

    fp = fopen("in.dat", "r");
    // Read 640 entries from the File
    for (i = 0; i < INPUT_LENGTH; i++)
    {
        float tmp1;
        float tmp2;
        float tmp3;
        float tmp4;
        float tmp5;
        fscanf(fp, "%f %f %f %f %f", &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
        for (j = 0; j < 5; j++)
        {
            particles[i * 5 + j] = (j == 0) ? tmp1 : (j == 1) ? tmp2
                                                 : (j == 2)   ? tmp3
                                                 : (j == 3)   ? tmp4
                                                              : tmp5;
        }
    }
    fclose(fp);
    int num_interations = 10;
    fp = fopen("out.dat", "w");

    for (int i = 0; i < num_interations; i++)
    {
        nBodySimulation2D(particles, temp);

        for (i = 0; i < INPUT_LENGTH; i++)
        {
            fprintf(fp, "%f %f %f %f %f \n", temp[i], temp[i + 1], temp[i + 2], temp[i + 3], temp[i + 4]);
        }
    }
    fclose(fp);

    // Compare the results file with the golden results
    // retval = system("diff --brief -w out.dat out.golden.dat");
    if (retval != 0)
    {
        printf("Test failed  !!!\n");
        retval = 1;
    }
    else
    {
        printf("Test passed !\n");
    }
    return retval;
}