# 

# \## EMG Processing Circuit

# EMG signals can be collected by placing electrodes on the muscle to measure the electrical activity during muscle contraction and relaxation. The electric signal reading can be processed entirely through hardware to obtain a meaningful signal. For the nerf gun prosthetic an on or off signal is required. So when there is a muscle contraction the input to the arduino should be a digital high, otherwise the pin will be low.

# 

# \### Circuit Overview

# The circuit consists of three main phases: signal collection, filtering and conversion to a digital signal. Each phase has different sub-circuits that were carefully chosen to process and convert the signal to a meaningful digital signal.

# 

# \### Signal collection

# The signal collection phase consists of two circuits, the instrumentation amplifier (IA), and an inverting op amp for additional gain. The IA has a customizable gain which is set by the resistance between the RG+ and RG- pins of the IA. Initially a gain of 1000 was chosen (without the additional amplification stage), but it was found that the IA would not give a consistent reading on this setting. In the gain was set to 50 and added an additional gain of 10 with an inverting op amp for a total gain of 500 on the EMG signal. These settings gave a clean EMG signal ready to be filtered.

# 

# \### Filtering

# With all signal collection there will be noise within the signal. This noise must be eliminated to have a clean meaningful signal. EMG signals tend to be between 20 and 600 Hz. There will also be 60 Hz electrical hum noise in the collected signal. The filtering circuit has three sub-circuits to eliminate all this noise: a notch filter, a low pass filter and a high pass filter. The notch filter is used to remove 60 Hz frequencies to get rid of electrical hum. This is followed by the low pass filter which removes noise above 600 Hz. The high pass filter removes frequencies below 20 Hz such as motion artifacts. Bode plots for each filter were collected to verify the circuits functionality.

# 

# \### Analog to Digital Conversion

# Since the desired signal is an on or off input the EMG signal must be converted digital. There are three sub-circuits to do this: full-wave rectification, envelope detection and a schmitt trigger. The purpose of the rectifier is to take the absolute value of the signal so that when the envelope filter outlines the signal it wont go below the virtual ground. Once the signal is rectified the envelope filter gets rid of extremely low frequencies (below 5 Hz) so that the comparator stage will have a clean signal without many oscillations. The schmitt trigger will output a high voltage when the enveloped signal is above a set threshold. The output of the schmitt trigger will be low when the enveloped signal is below a set threshold. This can be seen in figure 3. Now we have a digital signal that is high when the muscle is contracted and low when the muscle is relaxed.

