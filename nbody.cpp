#include "nbody.h"
#include "hls_math.h"
void nBodySimulation2D(float particles[INPUT_LENGTH * 5], float temp[INPUT_LENGTH * 5])
{
    const float time_step = 0.01;
    const float G = 6.67430e-11f;
    const float min_cul_radius = 0.25;
// fixed_t test = 1.0;
#pragma HLS pipeline off
    for (int i = 0; i < INPUT_LENGTH; i += 5)
    {

#pragma HLS pipeline off

        float force_x = 0;
        float force_y = 0;

        for (int j = 0; j < INPUT_LENGTH; j += 5)
        {
            if (i != j)
            {
                // CalculateForce2D(particleData, i, j, force_x, force_y);
                float x1 = particles[i];
                float y1 = particles[i + 1];
                float x2 = particles[j];
                float y2 = particles[j + 1];
                float mass1 = particles[i + 4];
                float mass2 = particles[j + 4];
                // Calculate the distance between the two particles in 2D
                float dx = x2 - x1;
                float dy = y2 - y1;
                // fixed_t distance = static_cast<fixed_t>(sqrt(static_cast<float>(dx * dx + dy * dy)));
                float distance = sqrt(dx * dx + dy * dy);
                // float distance = 3.0f;
                //  Define gravitational constant
                //  Calculate the gravitational force in 2D

                if (distance <= min_cul_radius)
                {
                    float force_magnitude = (G * mass1 * mass2) / (distance * distance);
                    // Calculate force components in 2D
                    force_x += force_magnitude * (dx / distance);
                    force_y += force_magnitude * (dy / distance);
                }
                // UpdateVelocity2D(particleData, i, force_x, force_y, time_step);
            }
        }

        float x1 = particles[i];
        float y1 = particles[i + 1];
        float vx = particles[i + 2];
        float vy = particles[i + 3];
        float mass = particles[i + 4];
        // Calculate acceleration in 2D
        float ax = force_x / mass;
        float ay = force_y / mass;
        // Update velocity in 2D using the calculated acceleration and time step
        temp[i + 2] = vx + ax * time_step;
        temp[i + 3] = vy + ay * time_step;
        temp[i] = x1 + temp[i + 2] * time_step;
        temp[i + 1] = y1 + temp[i + 3] * time_step;
        temp[i + 4] = mass;
        // test *= 2;
        // printf("Check out this var %f\n", static_cast<fixed_t>(test));
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