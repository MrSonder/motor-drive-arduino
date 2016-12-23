# motor-drive-arduino
This directory is for motor driving part of our robot which is done on arduino.
# 23 December 2016 19:36
A. The reason for not being able to start the movement was proven to be caused by low current output of the regulator. Current requirement is higher for starting the movement than to continue moving.
A. a. When we connected battery directly to the input of the motor driver, it started its movement at around 55 % pwm. Once it starts moving, pwm can be dropped to 50 %.
A. b. However, since voltage is not regulated to higher values, max speed drops significantly.
B. 'Sarhoş tekerlek' limits the rotating movement greatly. 
B. a. More slippery one is needed.
C. The width and weight of the chassis also has an effect on rotating.
C. a. It should be as small as possible.
C. b. Maybe motors/wheels should not be outside the chassis.
C. c. Try to decrease weight.
