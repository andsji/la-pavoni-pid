import numpy as np
import matplotlib.pyplot as plt

# Path to the error data file
dataPath = 'error_data.csv'

# Load the error data from the file
error_data = np.loadtxt(dataPath)


time_seconds = np.arange(len(error_data))

plt.figure(figsize=(10, 6))
plt.plot(time_seconds, error_data, label='Error', color='blue')
plt.axhline(y=0, color='r', linestyle='--', label='Set point (Error = 0)')
plt.xlabel('Time (seconds)')
plt.ylabel('e(t)')
plt.legend()
plt.grid(True)
plt.gca().invert_yaxis()
plt.show()