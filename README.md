# Aliasing and FFT

This project investigates two core concepts in digital signal processing using **Arduino Uno** and **MATLAB**:

1. **Aliasing due to undersampling**  
2. **Low-pass filtering and FFT analysis**

---

## Project Overview

### Assignment 1 – Sampling Frequency Effect on Aliasing
- A 23 Hz sine wave is generated with Arduino (PWM + RC filter).  
- The signal is sampled at different frequencies (12, 20, 26, 46, 92, and 120 Hz).  
- MATLAB is used to plot time-domain signals and compute FFTs.  
- Results show how undersampling leads to aliasing and frequency distortion.  

### Assignment 2 – Low-Pass Filter and FFT
- A combined signal (6 Hz + 84 Hz) is generated with Arduino.  
- The signal passes through an RC low-pass filter (fc ≈ 48 Hz).  
- MATLAB applies a Hanning window and computes FFT.  
- Experimental attenuation is compared with theoretical filter response.  

---

## How to Run

### Arduino
1. Open the Arduino sketches in the `arduino/` folder:
   - `Lab4_Assignment1.ino` for aliasing experiments.  
   - `Lab4_Assignment2.ino` for low-pass filter experiments.  
2. Upload to Arduino Uno.  
3. Sampled data will be transmitted over Serial (baud rate 57600).  

### MATLAB
1. Open the MATLAB scripts in the `matlab/` folder.  
2. For Assignment 1:  
   - Run the receiver script to capture data from Arduino.  
   - Run the processing script to plot signals and FFTs.  
3. For Assignment 2:  
   - Load the sampled data file.  
   - Apply the Hanning window.  
   - Perform FFT and compare experimental attenuation with theoretical calculations.  

---

## Expected Results
- Visualization of aliasing at undersampling frequencies.  
- Correct representation of the 23 Hz signal at higher sampling rates.  
- Low-pass filter verified to attenuate the 84 Hz component more strongly than the 6 Hz component.  
- FFT results closely match theoretical predictions.  
