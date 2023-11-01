#include "nbody.h"
#include "hls_math.h"
#include "ap_fixed.h"
// #include "iostream.h"

void nBodySimulation2D(fixed_t particles[INPUT_LENGTH * 5], fixed_t temp[INPUT_LENGTH * 5])
{
    const fixed_t time_step = 0.01;
    const fixed_t G = 6.67430;
    const fixed_t min_cul_radius = 0.25;
#pragma HLS pipeline off
    for (int i = 0; i < INPUT_LENGTH; i += 5)
    {
#pragma HLS pipeline off

        fixed_t force_x = 0;
        fixed_t force_y = 0;

        for (int j = 0; j < INPUT_LENGTH; j += 5)
        {
            if (i != j)
            {
                // CalculateForce2D(particleData, i, j, force_x, force_y);
                fixed_t x1 = static_cast<fixed_t>(particles[i]);
                fixed_t y1 = static_cast<fixed_t>(particles[i + 1]);
                fixed_t x2 = static_cast<fixed_t>(particles[j]);
                fixed_t y2 = static_cast<fixed_t>(particles[j + 1]);
                fixed_t mass1 = static_cast<fixed_t>(particles[i + 4]);
                fixed_t mass2 = static_cast<fixed_t>(particles[j + 4]);
                // Calculate the distance between the two particles in 2D
                fixed_t dx = x2 - x1;
                fixed_t dy = y2 - y1;

                float distance_float = sqrt(dx.to_float() * dx.to_float() + dy.to_float() * dy.to_float());

                // Define gravitational constant
                // Calculate the gravitational force in 2D
                fixed_t distance = static_cast<fixed_t>(distance_float);
                if (distance <= min_cul_radius)
                {
                    fixed_t force_magnitude = (G * mass1 * mass2) / (distance * distance);
                    // Calculate force components in 2D
                    force_x += force_magnitude * (dx / distance);
                    force_y += force_magnitude * (dy / distance);
                }
                // UpdateVelocity2D(particleData, i, force_x, force_y, time_step);
            }
        }
        fixed_t x1 = particles[i];
        fixed_t y1 = particles[i + 1];
        fixed_t vx = particles[i + 2];
        fixed_t vy = particles[i + 3];
        fixed_t mass = particles[i + 4];

        // Calculate acceleration in 2D
        float ax = force_x.to_float() / mass.to_float();
        float ay = force_y.to_float() / mass.to_float();
        // Update velocity in 2D using the calculated acceleration and time step
        temp[i + 2] = vx + static_cast<fixed_t>(ax) * time_step;
        temp[i + 3] = vx + static_cast<fixed_t>(ay) * time_step;
        temp[i] = x1 + temp[i + 2] * time_step;
        temp[i + 1] = y1 + temp[i + 3] * time_step;
        temp[i + 4] = mass;
    }

    for (int i = 0; i < INPUT_LENGTH; i += 5)
    {
        particles[i] = temp[i];
        particles[i + 1] = temp[i + 1];
        particles[i + 2] = temp[i + 2];
        particles[i + 3] = temp[i + 3];
        particles[i + 4] = temp[i + 4];
    }
}