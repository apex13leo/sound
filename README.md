# -----------------------------------------  SOUND SENSOR PROJECT  ------------------------------------------------

This project is meant to collect sound level at a proximity of a Raspberry Pi device. The RPi is equiped with a USB
sound card (C-Media Electronics, Inc. Audio Adapter) and a microphone. The sound is recorded at 16000Hz Sample rate 
and every second will produce 80 pieces of RMS value as a bar-diagram...


Table of Content
1. Configuration
2. Installation
3. Operation
4. Manifest (list of files and short description of their roles
5. Licence
6. Contact information

------------------------------------------------------------------------------------------------------------------

1. Configuration

Setting sound card:
	RPi onboard sound card doesn't have microphone interdace. Default audio device has to be changed to USB sound card
	in order to get application working by following next stepps.
	1. Boot up RPi, and apply the USB sound card
	2. Use "lsusb" command to check if USB sound card is mounted (device should be visible in list of devices)
	3. Use "sudo nano /stc/asound.conf" to start editing configuration file and insert following lines:

---------------------------------------------------------------------------------

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
                  
---------------------------------------------------------------------------------

	4. Go to your home directory by "cd" command. Use "nano .soundrc" command and insert same lines from previous step.
	Save both files so our configuration applies (Restart of device is recommended)
	5. Run "alsamixer" and check is USB sound card a default audio device.
	Navigate trough options to set sound and microphone to desired levels with directional keys on keyboard.


Known Bugs and fix:

	The latest version of Raspbian comes with new version of alsa-utils (1.0.28), which have a bug while recording.
	Recording doesn't stop and thus it generatas lots of unusable audio files. Currently know solution is to downgrade
	alsa-utils to an earlier version (1.0.25) by following next stepps:

	1. Use "sudo nano/etc/apt/sources.list" command and add the last line:

---------------------------------------------------------------------------------

deb http://mirrordirector.raspbian.org/raspbian/ jessie main contrib non-free rpi
# Uncomment line below then 'apt-get update' to enable 'apt-get source'
#deb-src http://archive.raspbian.org/raspbian/ jessie main contrib non-free rpi
deb http://mirrordirector.raspbian.org/raspbian/ wheezy main contrib non-free rpi

---------------------------------------------------------------------------------

	2. Run "sudo apt-get update"
	3. Run "sudo aptitude versions alsa-utils" to check if version 1.0.25 of alsa-utils is available
	4. Run "sudo apt-get install alsa-utils=1.0.25-4" to downgrade.
	5. Reboot (recommended)
	6. Run "arecord -r44100 -c1 -f S16_LE -d5 test.wav" to test that your microphone is working.
	"test.wav" file should be created in current folder.
	7. Put earphones on. Run "aplay test.wav" to check that your recording is working.

------------------------------------------------------------------------------------------------------------------

2. Installation

Install libcurl by following next stepps:

	1. Use command "ls /usr/include/curl" to check does that folder exists or not.
	Some newer versions of raspbian moved curl to next location:
	 "ls /usr/include/arm-linux-gnueabihf/curl"
	2. If the folder doesn't exist, run "sudo apt-get update" to update the application list.
	3. Run "sudo apt-get install libcurl3" to install the libcurl3
	4. Run "sudo apt-get install libcurl4-openssl-dev" to install the development API of libcurl4.

Install application:

	1. Create folder in which program should be installed (mkdir "folder name").
	2. Run command "git init" to initialize folder where program will be downloaded.
	3. Clone program from following link to your RPi by running next line:
	 "git clone https://github.com/apex13leo/sound.git"
	4. Complile program by running "make" command.
	5. Program will be compiled and ready to use. To run program, run "./sound.a" command.
