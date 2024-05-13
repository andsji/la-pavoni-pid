import numpy as np
import matplotlib.pyplot as plt

# dataPath = 'heatloss_experiment_output.txt'
dataPath = 'first1200.txt'

data_points = []

# extract data from file with open
with open(dataPath) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")


time_seconds = np.arange(1, len(data_points) + 1)


# setting up parameters

# calculating the surface area of the boiler
hight = 18
r = 4
surface_area_cm = 2*np.pi*r*(r+hight)

surface_area_m = surface_area_cm/10000
ambient_temp = 20
specific_heat_capacity = 4186
water_mass_kg = 0.8

start_temp = data_points[0]

# calculating the heat loss


def heat_loss(h, temp):
    q_loss = h * surface_area_m * (temp - ambient_temp)
    delta_t = q_loss/(specific_heat_capacity * water_mass_kg)
    return temp - delta_t


# Adjust range and number based on your expectations
h_values = np.linspace(10, 100, 50)

# Function to simulate temperature profile over time for a given h


def simulate_temperature_profile(h, initial_temp, measurements):
    temperatures = [initial_temp]
    for i in range(1, len(measurements)):
        delta_t = heat_loss(h, temperatures[-1])
        temperatures.append(delta_t)
    return temperatures


# Calculate MSE for each h value
mse_values = []
for h in h_values:
    predicted_temps = simulate_temperature_profile(h, start_temp, data_points)
    mse = np.mean((np.array(data_points) - np.array(predicted_temps)) ** 2)
    mse_values.append(mse)
print(predicted_temps)
# Find the best h value
min_mse = min(mse_values)
best_h = h_values[mse_values.index(min_mse)]
print(f"Best h: {best_h} with minimum MSE: {min_mse}")

# Plot the experimental data
plt.plot(time_seconds, data_points, label='Experimental Data')

# Plot the best fit model
best_fit_temps = simulate_temperature_profile(best_h, start_temp, data_points)
plt.plot(time_seconds, best_fit_temps,
         label=f'Best Fit Model (h={best_h:.2f})', linestyle='--')

plt.xlabel('Time (seconds)')
plt.ylabel('Temperature (°C)')
plt.title('Experimental Data vs. Best Fit Model')
plt.legend()
plt.show()
