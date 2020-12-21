import serial
import sys
import time

# Connects to arduino through port COM4 and reads the parameters of the cmd command
ser = serial.Serial('/dev/ttyACM0', 9600)
param = int(sys.argv[1])


# To turn LED on, 1 is passed as the parameter
if param == 1:
    # Delay is added to ensure the arduino receives the function
    for i in range(10000):
        ser.write('O'.encode())
        time.sleep(0.000001)
# To turn LED off, 0 is passed as the parameter
elif param == 0:
    ser.write('F'.encode())
