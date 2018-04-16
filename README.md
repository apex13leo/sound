# --------------  SOUND SENSOR PROJECT  --------------

This project is meant to collect sound level at a proximity of a Raspberry Pi device. The RPi is equiped with a USB
sound card (C-Media Electronics, Inc. Audio Adapter) and a microphone. The sound is recorded at 16000Hz Sample rate 
and every second will produce 80 pieces of RMS value as a bar-diagram...


Table of Content
1. Configuration
2. Installation
3. Operation
4. Manifest (list of files and short description of their roles)
5. Licence
6. Contact information

------------------------------------------------------------------------------------------------------------------

1. Configuration

	Setting sound card:
	RPi onboard sound card doesn't have microphone interdace. Default audio device has to be changed to USB sound 
	card in order to get application working by following next stepps.

1.1 Boot up RPi, and apply the USB sound card
1.2 Use "lsusb" command to check if USB sound card is mounted (device should be visible in list of devices)
1.3 Use "sudo nano /stc/asound.conf" to start editing configuration file and insert following lines:


	pcm.!default {
		type plug
		slave {
			pcm "hw:1,0"
		}
	}
	ctl.!default {
		type hw
		card 1
	}


1.4 Go to your home directory by "cd" command. Use "nano .soundrc" command and insert same lines from previous
	step.Save both files so our configuration applies (Restart of device is recommended)
1.5 Run "alsamixer" and check is USB sound card a default audio device.
	Navigate trough options to set sound and microphone to desired levels with directional keys on keyboard.


Known Bugs and fix:

	The latest version of Raspbian comes with new version of alsa-utils (1.0.28), which have a bug
	while recording. Recording doesn't stop and thus it generatas lots of unusable audio files. 
	Currently know solution is to downgrade alsa-utils to an earlier version (1.0.25)
	by following next stepps:

1.6.1 Use "sudo nano/etc/apt/sources.list" command and add the last line:



	deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
	# Uncomment line below then 'apt-get update' to enable 'apt-get source'
	#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
	deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi



1.6.2 Run "sudo apt-get update"
1.6.3 Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-utils is available
1.6.4 Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade.
1.6.5 Reboot (recommended)
1.6.6 Run "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test that your microphone is working.
	"test.wav" file should be created in current folder.
1.6.7 Put earphones on. Run "aplay test.wav" to check that your recording is working.

------------------------------------------------------------------------------------------------------------------

2. Installation

Install libcurl by following next stepps:

2.1 Use command "ls /usr/include/curl" to check does that folder exists or not.
	Some newer versions of raspbian moved curl to next location:
	"ls /usr/include/arm-linux-gnueabihf/curl"
2.2 If the folder doesn't exist, run "sudo apt-get update" to update the application list.
2.3 Run "sudo apt-get install libcurl3" to install the libcurl3
2.4 Run "sudo apt-get install libcurl4-openssl-dev" to install the development API of libcurl4.

Install application:

2.5.1 To fully see bars as intended remote character set have to be changed to UTP-8 in putty settings under
	translation option. To access this settings, right click on top of bar of putty program. 
	Select "Change Settings..." option and select "Translation" option from list. Select "UTP-8" from 
	scroll down menu.
2.5.2 Create folder in which program should be installed (mkdir "folder name").
2.5.3 Run command "git init" to initialize folder where program will be downloaded.
2.5.4 Clone program from following link to your RPi by running next line:
	"git clone https://github.com/apex13leo/sound.git"
2.5.5 Complile program by running "make" command.

------------------------------------------------------------------------------------------------------------------

3. Operation

Running application:

3.1 To start application run "./sound.a" command.
3.2 To stop application use Ctrl+C combination buttons on your keyboard.

------------------------------------------------------------------------------------------------------------------

4. Manifest (list of files and short description of their roles)

File list:

4.1 comm.c ; comm.h ; main.c ; sound.c ; sound.h ; screen.c ; screen.h ; makefile ; README.md ;
	sound.php
		 
Short file description:

4.2.1 comm.c: Function definition of sendToServer function. Includes data collection and dB conversion.
4.2.2 comm.h: Function prototype for sending data to web server.
4.2.3 main.c: Main function. Runs recording of ".wav" file in infinite loop until stopped.
4.2.4 sound.c: Function definitions of displayBar and displayWAVheader.
4.2.5 sound.h: Header file for processing sound ".Wav" file.
4.2.6 screen.c: Screen manipulation functions like clearScreen(), gotoxy(), setColor(), etc.
4.2.7 screen.h: Definitions of constants and function prototypes.
4.2.8 makefile: Compilation instructions, contains commands like "make", "makeclean".
4.2.9 README.md: Readme file containing all details about program.
4.2.10 sound.php: Server communication and data sending to webserver.

------------------------------------------------------------------------------------------------------------------

5. Licence

Copyright (C) <2018>  <Leonard Hujic>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
                
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

This program was guided by teacher Gao Chao.

------------------------------------------------------------------------------------------------------------------

6. Contact information

	Leonard Hujic

	e1700678@edu.vamk.fi

------------------------------------------------------------------------------------------------------------------

