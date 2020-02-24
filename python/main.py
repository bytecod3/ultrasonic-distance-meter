from pyfirmata import Arduino, util
from time import sleep, time
import os

# board configurations
port = '/dev/ttyACM0'
board = Arduino(port)
sleep(5)
it = util.Iterator(board)
it.start()

# pin configurations
red_led = board.get_pin('d:9:o')
blue_led = board.get_pin('d:10:o')
green_led = board.get_pin('d:11:o')

trigger = board.get_pin('d:2:o')
echo = board.get_pin('d:3:i')

while True:
	try:
		red_led.write(0)
		blue_led.write(0)
		green_led.write(0)

		# clear the trigger pin for 2 microceconds
		trigger.write(0)
		sleep(0.000002)

		# generate a sonic signal for 10 microseconds and start measuring with echo
		trigger.write(1)
		sleep(0.00001)



	except KeyboardInterrupt
		# exit board safely
		board.exit()
		os._exit()
