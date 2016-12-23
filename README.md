# motor-drive-arduino
This directory is for motor driving part of our robot which is done on arduino.
# 23 December 2016 19:36
1. The reason for not being able to start the movement was proven to be caused by low current output of the regulator. Current requirement is higher for starting the movement than to continue moving.
1. a. When we connected battery directly to the input of the motor driver, it started its movement at around 55 % pwm. Once it starts moving, pwm can be dropped to 50 %.
1. b. However, since voltage is not regulated to higher values, max speed drops significantly.
2. 'Sarhoş tekerlek' limits the rotating movement greatly. 
2. a. More slippery one is needed.
3. The width and weight of the chassis also has an effect on rotating.
3. a. It should be as small as possible.
3. b. Maybe motors/wheels should not be outside the chassis.
3. c. Try to decrease weight.
