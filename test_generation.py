import random

# Generate 100 random (x, y) tuples with floating-point values
n = 100
min_value = -100.0
max_value = 100.0
max_mass = 10
min_mass = -10
random_tuples = [(random.uniform(min_value, max_value), random.uniform(min_value, max_value), random.uniform(min_value, max_value), random.uniform(min_value, max_value), random.uniform(max_mass, min_mass)) for _ in range(n)]

# Write the tuples to a file named "in.dat"
with open("in.dat", "w") as file:
    for a, b, c, d, e in random_tuples:
        file.write(f"{a:.6f} {b:.6f} {c:.6f} {d:.6f} {e:.6f}\n")
