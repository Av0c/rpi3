# READ ME FIRST
# https://github.com/Av0c/rpi3

Raspberry Pi sound sensor project.

This project turns a RPi3 into a sound sensor.

1. Configuration

1.1 Hardware configuration

 - Raspberry Pi 3 (older version may require different configurations).
 - USD sound card and microphone connection.
 - Ethernet connection (recommended).

1.2 Software configuration

 - "lusb" command can be used to check if USB sound card is properly mounted.
 - USB sound card must be set as default device by modifying 2 files:
    1) /etc/asound.conf
    2) /.asoundrc
   with the following contents:
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
 - "alsamixer" command can be used to check if the USB sound card is default.
 - If you are using Raspbian Jessie, alsa-utils must be rolled back to an early version.
 - Encoding of environment must be UTF-8.
 - More information is available at https://portal.vamk.fi/mod/resource/view.php?id=265871

2. Operating instructions

 - Plug in the USB sound card and setup the RPi3 as usual (SD card, power cable, Ethernet cable).
 - Run "make" command to build the project ("make clean" and "make archive" are also available).
 - Run "./sound.a" to execute the project.
 - Observe the columns visualizing the recorded sound in (almost) real-time and admire the beauty of technology.
 - Run "make clean" to delete the execution file.

 3. File manifest

  The list of files in the project
 - comm.c comm.h
 - screen.c screen.h
 - wave.c wave.h
 - main.c
 - README.md

4. Copyright and Licensing

 - Author: QUYEN DUONG (e1601127)
 - Email: mindstorm1998@gmail.com

5. Known bugs

 - No known bug.
 - To report a bug please submit a new issue through Github.

6. Troubleshooting

6.1 The bar charts display incorrectly or don't display at all

 - Make sure your encoding is set to "UTF-8".
 - You may not have permission to run the executable ("sudo" and try again).
 - The microphone may be low-quality or be broken.

7. Credits and acknowledgements

 - Instructor: Mr. GAO CHAO
 - Source code: Mr. GAO CHAO
 - PHP Server: VAMK

8. Changelog

 - v1.0: First release. Program can display recorded sound on screen.
 - v1.1: Display is more detailed and smooth.
 - v1.2: Fix a bug where display can lag behind sound sometimes.
 - v1.3: Program is able to send data to PHP server.
 - v1.4: User can now view recored sounds through a website.
