/*  
 Test the tft.print() viz embedded tft.write() function

 This sketch used font 2, 4, 7
 
 Make sure all the display driver and pin connections are correct by
 editing the User_Setup.h file in the TFT_eSPI library folder.

 Note that yield() or delay(0) must be called in long duration for/while
 loops to stop the ESP8266 watchdog triggering.

 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
 */


#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>

#define SONG_LENGTH 110

TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h



struct wordItem {
  String letters;
  int chordRoot;
  int chordModifier;
  int len;
};

struct wordItem song[SONG_LENGTH] = {
  {
    letters: "5",
    chordRoot: -1,
    chordModifier: -1,
    len: 1000
  },
  {
    letters: "4",
    chordRoot: -1,
    chordModifier: -1,
    len: 1000
  },
  {
    letters: "3",
    chordRoot: -1,
    chordModifier: -1,
    len: 1000
  },
  {
    letters: "2",
    chordRoot: -1,
    chordModifier: -1,
    len: 1000
  },
  {
    letters: "1",
    chordRoot: -1,
    chordModifier: -1,
    len: 1000
  },
  {
    letters: "*drums*",
    chordRoot: -1,
    chordModifier: -2,
    len: 2200
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 13,
    len: 230
  },
  {
    letters: "horns!",
    chordRoot: -1,
    chordModifier: -1,
    len: 1745
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 2055
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 1,
    len: 2210
  },
  {
    letters: "",
    chordRoot: 5,
    chordModifier: 5,
    len: 1030
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 6,
    len: 895
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 13,
    len: 2085
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 2060
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 1,
    len: 3670
  },
  {
    letters: "Saturday",
    chordRoot: -1,
    chordModifier: -1,
    len: 570
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 0,
    len: 1360
  },
  {
    letters: "rest",
    chordRoot: -1,
    chordModifier: -1,
    len: 485
  },
  {
    letters: "can",
    chordRoot: -1,
    chordModifier: -1,
    len: 240
  },
  {
    letters: "",
    chordRoot: 2,
    chordModifier: 9,
    len: 295,
  },
  {
    letters: "wait",
    chordRoot: -1,
    chordModifier: -1,
    len: 1660
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 130
  },
  {
    letters: "got",
    chordRoot: 7,
    chordModifier: 5,
    len: 240
  },
  {
    letters: "a",
    chordRoot: -1,
    chordModifier: -1,
    len: 195
  },
  {
    letters: "list",
    chordRoot: -1,
    chordModifier: -1,
    len: 215
  },
  {
    letters: "a",
    chordRoot: -1,
    chordModifier: -1,
    len: 170
  },
  {
    letters: "million",
    chordRoot: -1,
    chordModifier: -1,
    len: 720
  },
  {
    letters: "letters",
    chordRoot: -1,
    chordModifier: -1,
    len: 530
  },
  {
    letters: "long",
    chordRoot: 5,
    chordModifier: 5,
    len: 1120  
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 6,
    len: 790
  },
  {
    letters: "nothing",
    chordRoot: -1,
    chordModifier: -1,
    len: 130
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 13,
    len: 380
  },
  {
    letters: "planned",
    chordRoot: -1,
    chordModifier: -1,
    len: 1720
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 1500
  },
  {
    letters: "till",
    chordRoot: -1,
    chordModifier: -1,
    len: 160
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 305
  },
  {
    letters: "reach",
    chordRoot: -1,
    chordModifier: -1,
    len: 215
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 0,
    len: 120
  },
  {
    letters: "the",
    chordRoot: -1,
    chordModifier: -1,
    len: 16
  },
  {
    letters: "end",
    chordRoot: -1,
    chordModifier: -1,
    len: 1630
  },
  {
    letters: "",
    chordRoot: 1,
    chordModifier: 5,
    len: 1085
  },
  {
    letters: "",
    chordRoot: 5,
    chordModifier: 8,
    len: 445
  },
  {
    letters: "No",
    chordRoot: -1,
    chordModifier: -1,
    len: 305
  },
  {
    letters: "reward",
    chordRoot: -1,
    chordModifier: -1,
    len: 265
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 0,
    len: 1505
  },
  {
    letters: "can’t",
    chordRoot: -1,
    chordModifier: -1,
    len: 285
  },
  {
    letters: "afford",
    chordRoot: -1,
    chordModifier: -1,
    len: 265
  },
  {
    letters: "",
    chordRoot: 2,
    chordModifier: 9,
    len: 1495
  },
  {
    letters: "to",
    chordRoot: -1,
    chordModifier: -1,
    len: 210
  },
  {
    letters: "indulge",
    chordRoot: -1,
    chordModifier: -1,
    len: 390
  },
  {
    letters: "",
    chordRoot: 7,
    chordModifier: 5,
    len: 120
  },
  {
    letters: "in",
    chordRoot: -1,
    chordModifier: -1,
    len: 305
  },
  {
    letters: "pleasures",
    chordRoot: -1,
    chordModifier: -1,
    len: 455
  },
  {
    letters: "till",
    chordRoot: -1,
    chordModifier: -1,
    len: 325
  },
  {
    letters: "this",
    chordRoot: -1,
    chordModifier: -1,
    len: 250
  },
  {
    letters: "list",
    chordRoot: -1,
    chordModifier: -1,
    len: 225
  },
  {
    letters: "is",
    chordRoot: 6,
    chordModifier: 2,
    len: 380
  },
  {
    letters: "gone",
    chordRoot: 5,
    chordModifier: 5,
    len: 1030
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 12,
    len: 955
  },
  {
    letters: "reverie",
    chordRoot: -1,
    chordModifier: -1,
    len: 85
  },
  {
    letters: "",
    chordRoot: 1,
    chordModifier: 6,
    len: 2080
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 1280
  },
  {
    letters: "won’t",
    chordRoot: -1,
    chordModifier: -1,
    len: 270
  },
  {
    letters: "get",
    chordRoot: -1,
    chordModifier: -1,
    len: 240
  },
  {
    letters: "the",
    chordRoot: -1,
    chordModifier: -1,
    len: 145
  },
  {
    letters: "best",
    chordRoot: -1,
    chordModifier: -1,
    len: 130
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 0,
    len: 140
  },
  {
    letters: "of",
    chordRoot: -1,
    chordModifier: -1,
    len: 215
  },
  {
    letters: "me",
    chordRoot: -1,
    chordModifier: -1,
    len: 2240
  },
  {
    letters: "",
    chordRoot: 1,
    chordModifier: 5,
    len: 520
  },
  {
    letters: "",
    chordRoot: 0,
    chordModifier: 1,
    len: 515
  },
  {
    letters: "And",
    chordRoot: -1,
    chordModifier: -1,
    len: 115
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 315
  },
  {
    letters: "try",
    chordRoot: -1,
    chordModifier: -1,
    len: 85
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 13,
    len: 145
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 235
  },
  {
    letters: "try",
    chordRoot: -1,
    chordModifier: -1,
    len: 290
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 235
  },
  {
    letters: "try",
    chordRoot: -1,
    chordModifier: -1,
    len: 635
  },
  {
    letters: "but",
    chordRoot: -1,
    chordModifier: -1,
    len: 135
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 120
  },
  {
    letters: "just",
    chordRoot: -1,
    chordModifier: -1,
    len: 275
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 120
  },
  {
    letters: "can't",
    chordRoot: -1,
    chordModifier: -1,
    len: 390
  },
  {
    letters: "get",
    chordRoot: -1,
    chordModifier: -1,
    len: 175
  },
  {
    letters: "it",
    chordRoot: -1,
    chordModifier: -1,
    len: 205
  },
  {
    letters: "right",
    chordRoot: -1,
    chordModifier: -1,
    len: 660
  },
  {
    letters: "am",
    chordRoot: -1,
    chordModifier: -1,
    len: 515
  },
  {
    letters: "I",
    chordRoot: 0,
    chordModifier: 1,
    len: 725
  },
  {
    letters: "the",
    chordRoot: -1,
    chordModifier: -1,
    len: 185
  },
  {
    letters: "only",
    chordRoot: -1,
    chordModifier: -1,
    len: 1020
  },
  {
    letters: "one?",
    chordRoot: -1,
    chordModifier: -1,
    len: 120
  },
  {
    letters: "",
    chordRoot: 7,
    chordModifier: 10,
    len: 1540
  },
  {
    letters: "Yeah",
    chordRoot: -1,
    chordModifier: -1,
    len: 210
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 300
  },
  {
    letters: "try",
    chordRoot: 3,
    chordModifier: 13,
    len: 235
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 205
  },
  {
    letters: "try",
    chordRoot: -1,
    chordModifier: -1,
    len: 210
  },
  {
    letters: "I",
    chordRoot: -1,
    chordModifier: -1,
    len: 235
  },
  {
    letters: "try",
    chordRoot: -1,
    chordModifier: -1,
    len: 700
  },
  {
    letters: "and",
    chordRoot: -1,
    chordModifier: -1,
    len: 260
  },
  {
    letters: "the",
    chordRoot: -1,
    chordModifier: -1,
    len: 175
  },
  {
    letters: "end",
    chordRoot: -1,
    chordModifier: -1,
    len: 95
  },
  {
    letters: "",
    chordRoot: 3,
    chordModifier: 3,
    len: 85
  },
  {
    letters: "is",
    chordRoot: -1,
    chordModifier: -1,
    len: 215
  },
  {
    letters: "not",
    chordRoot: -1,
    chordModifier: -1,
    len: 345
  },
  {
    letters: "in",
    chordRoot: -1,
    chordModifier: -1,
    len: 255
  },
  {
    letters: "sight",
    chordRoot: -1,
    chordModifier: -1,
    len: 690
  },
  {
    letters: "in",
    chordRoot: -1,
    chordModifier: -1,
    len: 475
  },
  {
    letters: "sight",
    chordRoot: 0,
    chordModifier: 0,
    len: 3600
  }
};

int i = 0;

int last_color = 0xFFFF;
String last_word = "";
String last_chord = "";

void setup(void) {
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(last_color);

  randomSeed(analogRead(0)); // get sufficient randomness
  
}

void loop() {

  if (song[i].letters != "") {
    last_word = song[i].letters;
  }
  if (song[i].chordRoot != -1) {
    last_chord = song[i].chordRoot + song[i].chordModifier;
    int red = 0;
    switch (song[i].chordRoot) {
      case 0:
        red = 0;
        last_chord = "F";
        break;
      case 1:
        red = 4;
        last_chord = "G";
        break;
      case 2:
        red = 8;
        last_chord = "A";
        break;
      case 3:
        red = 12;
        last_chord = "Bb";
        break;
      case 4:
        red = 16;
        last_chord = "B";
        break;
      case 5:
        red = 20;
        last_chord = "C";
        break;
      case 6:
        red = 24;
        last_chord = "Db";
        break;
      case 7:
        red = 28;
        last_chord = "D";
        break;
      default:
        red = 31;
        last_chord = "";
        break;
    }

    int green = 0;
    switch (song[i].chordModifier) {
      case 0:
        green = 0;
        break;
      case 1:
        green = 4;
        last_chord += "/A";
        break;
      case 2:
        green = 8;
        last_chord += "dim";
        break;
      case 3:
        green = 12;
        last_chord += "m6";
        break;
      case 4:
        green = 16;
        last_chord += "add4";
        break;
      case 5:
        green = 20;
        last_chord += "m7";
        break;
      case 6:
        green = 24;
        last_chord += "7";
        break;
      case 7:
        green = 28;
        last_chord += "m7b5";
        break;
      case 8:
        green = 32;
        last_chord += "7sus";
        break;
      case 9:
        green = 36;
        last_chord += "7#5";
        break;
      case 10:
        green = 40;
        last_chord += "7#9";
        break;
      case 11:
        green = 44;
        last_chord += "m9";
        break;
      case 12:
        green = 48;
        last_chord += "9";
        break;
      case 13:
        green = 52;
        last_chord += "Maj9";
        break;
      case 14:
        green = 56;
        last_chord += "Maj9/A";
        break;
      case 15:
        green = 60;
        last_chord += "m11";
        break;
      default:
        green = 63;
        break;
    }

    int blue = random(32);

    last_color = (red << 11) + (green << 5) + blue;
  }

  tft.fillScreen(last_color);
  // Set "cursor" at top left corner of display (0,0) and select font 2
  // (cursor will move to next line automatically during printing with 'tft.println'
  //  or stay on the line is there is room for the text with tft.print)
  tft.setCursor(10, 10, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_BLACK);  tft.setTextSize(3);
  // We can now plot text on screen using the "print" class
  tft.println(last_word);

  tft.setCursor(10, 80, 2);
  // Set the font colour to be white with a black background, set text size multiplier to 1
  tft.setTextColor(TFT_BLACK);  tft.setTextSize(3);
  // We can now plot text on screen using the "print" class
  tft.println(last_chord);
  
  delay(song[i].len - 14);

  i += 1;
  if (i >= SONG_LENGTH) {
    i = 0;
  }
  
}
