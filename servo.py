from time import sleep
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

servo2 = 27
servo1 = 17

GPIO.setup(servo1, GPIO.OUT) # white => TILT
GPIO.setup(servo2, GPIO.OUT) # gray ==> PAN

def setServoAngle(servo, angle):
	assert angle >=-50 and angle <= 100
	pwm = GPIO.PWM(servo, 50)
	pwm.start(8)
	dutyCycle = angle / 18. + 3.
	pwm.ChangeDutyCycle(dutyCycle)
	sleep(0.3)
	pwm.stop()

if __name__ == '__main__':
    setServoAngle(servo1, -40)
    setServoAngle(servo2, 0)
    sleep(1)
    for i in range (-40, 0,5):
      setServoAngle(servo1, i)
       #setServoAngle(servo2, i)
    for i in range (0, -30,-5):
      setServoAngle(servo2, i)
    sleep(2)
    for i in range (-20, 0,5):
      setServoAngle(servo2, i)
    for i in range (0, -40,-5):
      setServoAngle(servo1, i)
       #setServoAngle(servo2, i)
    
    
   # for i in range (50, 0,-10):
    #    setServoAngle(pan, i)
     #   setServoAngle(tilt, i)
    #setServoAngle(servo2, -20)
   
    
      
    GPIO.cleanup()