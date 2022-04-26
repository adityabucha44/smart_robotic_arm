# Smart Robotic Arm

Simple code in python to detect face and actuate the roboci arm and codes in c as .ino files for actuating the bionic hand. Find codes for bionic hand actuation in folder bionic_hand

## Dependencies

1. Python 3
2. opencv (tested with 3.4) 
3. dlib	(tested with 19.18.0)
4. imutils (tested with 0.5.3)
5. scipy
6. numpy
7. argparse

## Run 

```
Python3 smart_arm.py -- webcam 0		//For external webcam, use the webcam number accordingly
```

## Setups

Change the threshold values according to your need
```
EYE_AR_THRESH = 0.3
EYE_AR_CONSEC_FRAMES = 30
Y_THRESH = 10`	//change this according to the distance from the camera
Servo angles as required
```










