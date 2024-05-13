import numpy as np
import matplotlib.pyplot as plt

# dataPath = 'heatloss_experiment_output.txt'
dataPathReal = 'Data_Real/pid_setpoint96_kp30_ki0.001_kd0.01.txt'
dataPathSim = 'Data_Sim/pid_setpoint96_kp30_ki0.001_kd0.01_sim.csv'
dataPathSim2 = 'Data_Sim/pid_setpoint96_kp30_ki0.001_kd0.01_sim_809w.csv'

dataPathReal2 = 'Data_Real/pid_setpoint101_kp30_ki0.001_kd0.01.txt'
dataPathSim3 = 'Data_Sim/pid_setpoint101_kp30_ki0.001_kd0.01_sim.csv'

dataPathOscillation = 'oscillation.csv'
dataPathZn1 = 'zn1.csv'
dataPathZnNoov = 'zn_noov.csv'
dataPathZnCondInt = 'zn_cond_int.csv'

dataPathZnCondIntReal = 'Data_Real/zn_kp50_ki50_kd16.5_condint_1.txt'

dataPathZnExp2 = 'Data_Real/zn_kp_setpoint96_50_ki50_kd16.5_condint_midtemp.txt'
dataPathMtExp2 = 'Data_Real/pid_setpoint96_kp30_ki0.001_kd0.01_midtemp.txt'

dataPathZnExp3 = 'Data_Real/zn_kp_setpoint96_50_ki50_kd16.5_condint_hightemp.txt'
dataPathMtExp3 = 'Data_Real/pid_setpoint96_kp30_ki0.001_kd0.01_hightemp.txt'

dataPathZnExp4 = 'Data_Real/zn_kp_setpoint101_50_ki50_kd16.5_condint.txt'
dataPathMtExp4 = 'Data_Real/pid_setpoint101_kp30_ki0.001_kd0.01.txt'

dataPathOnOff = 'Data_Real/onoffcontroller.txt'
data_points_onoff = []

dataPathOnOff117 = 'Data_Real/onoff117.txt'
data_points_onoff117 = []

dataPathPid117 = 'Data_Real/pid_setpoint117.14_kp30_ki0.001_kd0.1.txt'
data_points_pid117 = []

dataPathPstat117 = 'Data_Real/pstat117.txt'
data_points_pstat117 = []


data_points_real = []
data_points_sim = []
data_points_sim2 = []

data_points_real2 = []
data_points_sim3 = []

data_points_oscillation = []
data_points_zn1 = []
data_points_zn_noov = []
data_points_zn_cond_int = []

data_points_zn_cond_int_real = []

data_points_zn_exp2 = []
data_points_mt_exp2 = []
data_points_zn_exp3 = []
data_points_mt_exp3 = []
data_points_zn_exp4 = []
data_points_mt_exp4 = []

# extract data from file with open
with open(dataPathReal) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_real.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathSim) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_sim.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathSim2) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_sim2.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathReal2) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_real2.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathSim3) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_sim3.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathOscillation) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_oscillation.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZn1) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn1.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnNoov) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_noov.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnCondInt) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_cond_int.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnCondIntReal) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_cond_int_real.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnExp2) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_exp2.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathMtExp2) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_mt_exp2.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnExp3) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_exp3.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathMtExp3) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_mt_exp3.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathZnExp4) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_zn_exp4.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathMtExp4) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_mt_exp4.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathOnOff) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_onoff.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")


with open(dataPathPstat117) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_pstat117.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathOnOff117) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_onoff117.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

with open(dataPathPid117) as f:
    for line in f:
        try:
            # strip() removes any leading/trailing whitespace
            data_point = float(line.strip())
            data_points_pid117.append(data_point)
        except ValueError:
            # Handle the case where conversion to float fails
            print(f"Could not convert line to float: '{line.strip()}'")

time_seconds = np.arange(1, len(data_points_real) + 1)
time_seconds2 = np.arange(1, len(data_points_real2) + 1)
time_seconds3 = np.arange(1, len(data_points_sim3) + 1)
time_osc = np.arange(1, len(data_points_oscillation) + 1)
time_zn1 = np.arange(1, len(data_points_zn1) + 1)
time_zn_noov = np.arange(1, len(data_points_zn_noov) + 1)

time_zn_cond_int = np.arange(1, len(data_points_zn_cond_int) + 1)
time_sim = np.arange(1, len(data_points_sim) + 1)

time_zn_cond_int_real = np.arange(1, len(data_points_zn_cond_int_real) + 1)

time_zn_exp3 = np.arange(1, len(data_points_zn_exp3) + 1)
time_mt_exp3 = np.arange(1, len(data_points_mt_exp3) + 1)

time_zn_exp4 = np.arange(1, len(data_points_zn_exp4) + 1)
time_mt_exp4 = np.arange(1, len(data_points_mt_exp4) + 1)

time_onoff = np.arange(1, len(data_points_onoff) + 1)

time_pstat117 = np.arange(1, len(data_points_pstat117) + 1)
time_pid117 = np.arange(1, len(data_points_pid117) + 1)
time_onoff117 = np.arange(1, len(data_points_onoff117) + 1)


# plt.axhline(y=96.0, color='black', linestyle='--', label='Set point (96°C)')
# plt.axhline(y=101.0, color='black', linestyle='--', label='Set point (101°C)')
# plt.axhline(y=117.14, color='black', linestyle='--',
#             label='Set point (117.14°C, eq. to 0.8 bars)')

# plt.plot(time_seconds, data_points_real, label='Espresso Machine')
# plt.plot(time_seconds, data_points_sim, label='Simulation 1000 watts')
# plt.plot(time_seconds, data_points_sim, label='Simulation 809.06 watts')


# plt.plot(time_seconds, data_points_real2, label='Espresso Machine')
# plt.plot(time_seconds2, data_points_sim3, label='Simulation 809.06 watts')

# plt.plot(time_pstat117, data_points_pstat117, label='Pressurestat, 0.8 bars')
# plt.plot(time_onoff117, data_points_onoff117, label='On/Off Controller')
# plt.plot(time_pid117, data_points_pid117, label='PID Controller')

# plt.plot(time_onoff, data_points_onoff, label='On/Off Controller')
plt.plot(time_pstat117, data_points_pstat117,
         label='Pressurestat set to 0.8 bars')

plt.xlabel('Time (seconds)')
plt.ylabel('Temperature (°C)')
plt.title('PID Controller vs. On/Off Controller')

# plt.xticks(2*time_osc, data_points_oscillation)

plt.legend()
plt.show()
