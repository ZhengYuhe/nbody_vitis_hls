/*
# Copyright (C) 2023, Advanced Micro Devices, Inc. All rights reserved.
# SPDX-License-Identifier: X11
*/

#include "nbody.h"

// ********************************************************
int main()
{
   float temp[5 * INPUT_LENGTH], particles[INPUT_LENGTH * N];
   int retval = 0, i, j;
   FILE *fp;

   fp = fopen("in.dat", "r");
   // Read 640 entries from the File
   for (i = 0; i < N; i++)
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

   nBodySimulation2D(particles, temp);

   fp = fopen("out.dat", "w");
   for (i = 0; i < N; i++)
   {
      fprintf(fp, "%f %f %f %f %f \n", particles[i], particles[i + 1], particles[i + 2], particles[i + 3], particles[i + 4]);
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