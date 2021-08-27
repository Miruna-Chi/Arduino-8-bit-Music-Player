# Arduino-8-bit-Music-Player
A microcontroller powered retro player in C++, using Arduino IDE

![](Demo.png?raw=true "Title")

• The player generates tones through a piezo buzzer and displays song information on an LCD.\
• Volume and brightness are potentiometer adjustable.\
• Implemented functions such as Prev/Next, Play/Pause, Shuffle, Repeat One/All/None on a predefined playlist.\
• All songs have been manually (and painstakingly) translated from music sheet notes to their respective frequencies. The piezo buzzer can only play one note at a time.\

Demo video: https://www.youtube.com/watch?v=Coqtfu8GF64

# Hardware Design

Parts:

    - Arduino UNO
    - Breadboard
    - Jumper wires
    - Piezo Buzzer
    - LCD
    - 5x buttons
    - Volume Potentiometer
    - (Optional) Brightness and contrast potentiometer for the LCD

All the above parts can be found in this Starter Kit: https://store.arduino.cc/genuino-starter-kit

# Software Design

Development:

    Arduino IDE, VS Code
    Tinkercad - Circuit Diagram
    
The project contains 5 source files: the main code, a library that contains note - frequency pairings, 3 files where the sheet music for each song gets initialized and the _buttons.h_ file where special characters for the Play/Pause, Repeat One/All/None, Shuffle icons are created.

The player is actually a song scheduler which frequently reads the input from the aforementioned buttons and makes a decision.

# Block Diagram
![](BlockDiagram.png?raw=true "Title")

# Circuit Diagram
![](CircuitDiagram.png?raw=true "Title")

# Resources

- Software resources:

https://www.makerguides.com/character-lcd-arduino-tutorial/

https://www.hackster.io/techarea98/super-mario-theme-song-with-piezo-buzzer-and-arduino-2cc461

https://solarianprogrammer.com/2017/01/31/arduino-buzzer-player-adjustable-volume-playing-fur-elise-beethoven/

- Musical resources:

https://www.youtube.com/watch?v=1pVNm-cG4Tg

https://www.youtube.com/watch?v=I0hbFdPR42c

https://www.youtube.com/watch?v=1xKfytm0ngo





