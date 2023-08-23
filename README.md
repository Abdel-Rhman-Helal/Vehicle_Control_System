# Vehicle_Control_System
it's a simple c project to simulate a Vehicle Control speed without gui that lets you to control a  speed of vehicle by traffic light Color &amp;  virtual vehicle temperature of room &amp; engine
## System Interface
Ask the user if he/she wants
  a. Turn on the vehicle engine
  b. Turn off the vehicle engine
  c. Quit the system
## Quit the system
  Quit program
## Turn off the vehicle engine
Ask him/her again what he/she wants to do (Pause System)
## Turn on the vehicle engine
  a. Turn off the engine
  b. Set the traffic light color.
  c. Set the room temperature (Temperature Sensor)
  d. Set the engine temperature (Engine Temperature Sensor)
## Turn off the engine
  Back System Interface
## Set the traffic light color
  i. If the traffic light is ‘G’ set vehicle speed to 100 km/hr
  ii. If the traffic light is ‘O’ set vehicle speed to 30 km/hr
      ### If vehicle speed is 30 km/hr
            i. Turn ON AC if it was OFF and set room temperature to:current
            temperature * (5/4) + 1
            ii. Turn ON “Engine Temperature Controller” if it was OFF and set engine
            temperature to: current temperature * (5/4) + 1
  iii. If the traffic light is ‘R’ set vehicle speed to 0 km/h

## Set the room temperature
    i. If temperature less than 10, Turn AC ON and set
    temperature to 20
    ii. If temperature is greater than 30, Turn AC ON and set
    temperature to 20
    iii. If temperature is otherwise, Turn AC OFF
## Set the engine temperature
    i. If temperature less than 100, Turn “Engine Temperature
    Controller” ON and set temperature to 125
    ii. If temperature is greater than 150, Turn “Engine Temperature
    Controller” ON and set temperature to 125
    iii. If temperature is otherwise, Turn “Engine Temperature
    Controller” OFF
## Display the current vehicle state After every Operation
    i. Engine state: ON/OFF.
    ii. AC: ON/OFF.
    iii. Vehicle Speed.
    iv. Room Temperature.
    v. Engine Temperature Controller State.
    vi. Engine Temperature
# All input token from console, we will 
# assume that this is the sensor read value
