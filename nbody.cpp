#include "nbody.h"
#include "hls_math.h"
void nBodySimulation2D(float particles[75]) {
    const int numParticles = 15;
    const float time_step = 0.01;
    for (int i = 0; i < numParticles; i += 5) {
        for (int j = 0; j < numParticles; j += 5) {
            if (i != j) {
                float force_x, force_y;
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
                float distance = sqrt(dx * dx + dy * dy);
                //float distance = 3.0f;
                // Define gravitational constant
                const float G = 6.67430e-11f;
                // Calculate the gravitational force in 2D
                float force_magnitude = (G * mass1 * mass2) / (distance * distance);
                // Calculate force components in 2D
                force_x = force_magnitude * (dx / distance);
                force_y = force_magnitude * (dy / distance);
                float vx = particles[i + 2];
                float vy = particles[i + 3];
                float mass = particles[i + 4];
                // Calculate acceleration in 2D
                float ax = force_x / mass;
                float ay = force_y / mass;
                // Update velocity in 2D using the calculated acceleration and time step
                particles[i + 2] = vx + ax * time_step;
                particles[i + 3] = vy + ay * time_step;
                // UpdateVelocity2D(particleData, i, force_x, force_y, time_step);
            }
        }
    }


   
}