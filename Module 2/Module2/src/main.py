import mido
import serial
import math

# change the port as necessary by your OS
ser = serial.Serial('/dev/tty.wchusbserial54D80194451', 115200)
outport = mido.open_output('IAC Driver Bus 1')
cur = 0
notes = [0, 60, 64]
on = [False, False, False]
mid_x = 2937
mid_y = 3002
cur_note = 60
cur_vel = 64	
z_pressed = False
button_pressed = False
while(True):
	message = ser.readline().decode().strip('\n').split('\t')
	if not z_pressed:
		dist_x = int(message[0]) - mid_x
		cur_note += round(dist_x/200)
		if cur_note < 0:
			cur_note = 0
		if cur_note > 127:
			cur_note = 127

		dist_y = int(message[1]) - mid_y
		cur_vel += round(dist_y/200)
		if cur_vel < 0:
			cur_vel = 0
		if cur_vel > 127:
			cur_vel = 127
	
	print(f"Note {cur_note} Velocity {cur_vel}")

	if message[2] == "0" and not z_pressed:
		z_pressed = True
		outport.send(mido.Message('note_on', note=cur_note))
	
	if message[3] == "0" and not button_pressed:
		button_pressed = True
		outport.send(mido.Message('control_change', control=64, value=127))

	if message[2] == "1" and z_pressed:
		z_pressed = False
		outport.send(mido.Message('note_off', note=cur_note))
	
	if message[3] == "1" and button_pressed:
		button_pressed = False
		outport.send(mido.Message('control_change', control=64, value=0))
