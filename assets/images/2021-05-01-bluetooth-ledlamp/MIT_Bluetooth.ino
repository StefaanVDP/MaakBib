#include <SoftwareSerial.h>
 
int R;
int G;
int B;
int aantalPixels;
String code;
int hue;
int i;
int RR;
int GG;
int BB;
int lus1;
int lus2;
int wacht;
int wachtlus;
int loop2;
int wiel;
int j;
int k;
int m;
int pix1;
int pix2;
int pix3;
int vorigpix1;
int vorigpix2;
int vorigpix3;
int n;
int lus3;
int lus4;
int NeoPixel_3 = 6;
int BT_Sensor[2] = {4, 5};

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel myNeo_NeoPixel_2 = Adafruit_NeoPixel(12, 6, NEO_GRB + NEO_KHZ800);
SoftwareSerial myBTBT_Sensor(4,5);


  String myBTBT_Sensor_readCodeFromApp() {
      //Serial.println("myBTBT_Sensor_readT()");
      if (myBTBT_Sensor.available() >0) {
          String BT_receive_data = myBTBT_Sensor.readStringUntil('|');
          myBTBT_Sensor.flush();
          Serial.print(" --> ");
          Serial.println(BT_receive_data);
          if(BT_receive_data.length()<13) {
            return BT_receive_data;
          } else {
            //Serial.println("te lang");
            return "";
          }
     } else {
        //Serial.println("not available");
        return "";
     }
  }

boolean isStringEmpty(String msg) {
  if (msg.length() == 0) {
    return true;
  } else {
    return false;
  }
}

boolean isStringColour(String msg) {
  return msg.startsWith("C");
}

int getValue(String data, char separator, int index ) {
  int found = 0;
  String colour = "";
  data = data.substring(1);  // get rid of the leading 'C'
  int strIndex[] = { 0, -1 };
  int maxIndex = data.length() - 1;
  for (int i = 0; i <= maxIndex && found <= index; i++){
    if (data.charAt(i) == separator || i == maxIndex){
      found++;
      strIndex[0] = strIndex[1] + 1;
      strIndex[1] = (i == maxIndex) ? i + 1 : i;
    }
  }
  colour =  found > index ? data.substring(strIndex[0], strIndex[1]) : "";
  return colour.toInt();
}

boolean isBrightness(String msg) {
  return msg.startsWith("H");
}

int mathRandomInt(int min, int max) {
  if (min > max) {
    // Swap min and max to ensure min is smaller.
    int temp = min;
    min = max;
    max = temp;
  }
  return min + (rand() % (max - min + 1));
}


void setup() {
  myNeo_NeoPixel_2.begin();
  myNeo_NeoPixel_2.show();
  myBTBT_Sensor.begin(9600);
  Serial.begin(9600);

  /**********************
  ** generated from ardublockly << MIT_Bluetooth.xml >>
  **********************/

  myNeo_NeoPixel_2.setBrightness(constrain(50,0,255)) ;
  myNeo_NeoPixel_2.show();
  R = 100;
  G = 100;
  B = 100;
  aantalPixels = myNeo_NeoPixel_2.numPixels();
  ;

}

void loop() {
  code = myBTBT_Sensor_readCodeFromApp();
  if (!isStringEmpty(String(code))) {
    if (isStringColour(String(code))) {
      R = getValue(code,'.',0);
      G = getValue(code,'.',1);
      B = getValue(code,'.',2);
      myNeo_NeoPixel_2.fill(myNeo_NeoPixel_2.Color(R,G,B));
      myNeo_NeoPixel_2.show();
    } else if (isBrightness(String(code))) {
      myNeo_NeoPixel_2.setBrightness(constrain((code.substring(1).toInt()),0,255)) ;
      myNeo_NeoPixel_2.show();
    } else if (code.equals("EFF1")) {
      hue = 0;
      while (!(myBTBT_Sensor.available() > 0)) {
        int i_inc = 1;
        if (1 > aantalPixels) {
          i_inc = -i_inc;
        }
        for (i = 1;
             i_inc >= 0 ? i <= aantalPixels : i >= aantalPixels;
             i += i_inc) {
          myNeo_NeoPixel_2.setPixelColor(i-1 , myNeo_NeoPixel_2.gamma32(myNeo_NeoPixel_2.ColorHSV(hue)));
          myNeo_NeoPixel_2.show();
          hue += 5;
          delay(5);
        }
      }
    } else if (code.equals("EFF2")) {
      while (!(myBTBT_Sensor.available() > 0)) {
        int i_inc2 = 1;
        if (1 > aantalPixels) {
          i_inc2 = -i_inc2;
        }
        for (i = 1;
             i_inc2 >= 0 ? i <= aantalPixels : i >= aantalPixels;
             i += i_inc2) {
          RR = mathRandomInt(1, R);
          GG = mathRandomInt(1, G);
          BB = mathRandomInt(1, B);
          myNeo_NeoPixel_2.setPixelColor(i-1, myNeo_NeoPixel_2.Color(RR,GG,BB));
          myNeo_NeoPixel_2.show();
        }
        delay(50);
      }
    } else if (code.equals("EFF3")) {
      hue = -20000;
      lus1 = 1;
      lus2 = (int)(floor((aantalPixels / 2)) + 1);
      while (!(myBTBT_Sensor.available() > 0)) {
        myNeo_NeoPixel_2.setPixelColor(lus1-1 , myNeo_NeoPixel_2.gamma32(myNeo_NeoPixel_2.ColorHSV(hue)));
        myNeo_NeoPixel_2.show();
        myNeo_NeoPixel_2.setPixelColor(lus2-1 , myNeo_NeoPixel_2.gamma32(myNeo_NeoPixel_2.ColorHSV(hue)));
        myNeo_NeoPixel_2.show();
        delay(50);
        myNeo_NeoPixel_2.clear();
        myNeo_NeoPixel_2.show();
        lus1 += 1;
        lus2 += 1;
        if (lus1 > aantalPixels) {
          lus1 = 1;
        }
        if (lus2 > aantalPixels) {
          lus2 = 1;
        }
        hue += 10;
      }
    } else if (code.equals("EFF4")) {
      hue = 15000;
      wacht = 50;
      wachtlus = 50;
      while (!(myBTBT_Sensor.available() > 0)) {
        int i_inc3 = 1;
        if (1 > aantalPixels) {
          i_inc3 = -i_inc3;
        }
        for (i = 1;
             i_inc3 >= 0 ? i <= aantalPixels : i >= aantalPixels;
             i += i_inc3) {
          myNeo_NeoPixel_2.setPixelColor(i-1 , myNeo_NeoPixel_2.gamma32(myNeo_NeoPixel_2.ColorHSV(hue)));
          myNeo_NeoPixel_2.show();
          hue += 100;
        }
        delay(wachtlus);
        wachtlus += wacht;
        if (wachtlus <= 0 || wachtlus > 300) {
          wacht = -wacht;
        }
      }
    } else if (code.equals("EFF5")) {
      loop2 = 0;
      wiel = 0;
      while (!(myBTBT_Sensor.available() > 0)) {
        for (j = 0; j <= 2; j++) {
          int k_end = aantalPixels - 1;
          int k_inc = 3;
          if (0 > k_end) {
            k_inc = -k_inc;
          }
          for (k = 0;
               k_inc >= 0 ? k <= k_end : k >= k_end;
               k += k_inc) {
            wiel = (k + loop2) % 255;
            loop2 += 1;
            if (wiel < 85) {
              R = wiel * 3;
              G = 255 - wiel * 3;
              B = 0;
            } else if (wiel < 170) {
              wiel += -85;
              R = 255 - wiel * 3;
              G = 0;
              B = wiel * 3;
            } else {
              wiel += -170;
              R = 0;
              G = wiel * 3;
              B = 255 - wiel * 3;
            }
            myNeo_NeoPixel_2.setPixelColor(((j + k) + 1)-1, myNeo_NeoPixel_2.Color(R,G,B));
            myNeo_NeoPixel_2.show();
          }
          delay(50);
          int m_inc = 3;
          if (1 > aantalPixels) {
            m_inc = -m_inc;
          }
          for (m = 1;
               m_inc >= 0 ? m <= aantalPixels : m >= aantalPixels;
               m += m_inc) {
            myNeo_NeoPixel_2.setPixelColor((m + j)-1, myNeo_NeoPixel_2.Color(0,0,0));
            myNeo_NeoPixel_2.show();
          }
        }
      }
    } else if (code.equals("EFF6")) {
//      myNeo_NeoPixel_2.clear();
      myNeo_NeoPixel_2.fill(myNeo_NeoPixel_2.Color(R,G,B));
      myNeo_NeoPixel_2.show();
      pix1 = mathRandomInt(1, aantalPixels);
      pix2 = mathRandomInt(1, aantalPixels);
      pix3 = mathRandomInt(1, aantalPixels);
      vorigpix1 = 1;
      vorigpix2 = 1;
      vorigpix3 = 1;
      while (!(myBTBT_Sensor.available() > 0)) {
        pix1 = mathRandomInt(1, aantalPixels);
        for (n = 25; n <= 99; n += 10) {
          myNeo_NeoPixel_2.setPixelColor(vorigpix1-1, myNeo_NeoPixel_2.Color(constrain(int(R*(100 - n)/100.0),0,255), constrain(int(G*(100 - n)/100.0),0,255), constrain(int(B*(100 - n)/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(pix1-1, myNeo_NeoPixel_2.Color(constrain(int(R*n/100.0),0,255), constrain(int(G*n/100.0),0,255), constrain(int(B*n/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          delay(200);
        }
        vorigpix1 = pix1;
        delay((mathRandomInt(50, 1000)));
        pix2 = mathRandomInt(1, aantalPixels);
        for (n = 25; n <= 99; n += 10) {
          myNeo_NeoPixel_2.setPixelColor(vorigpix2-1, myNeo_NeoPixel_2.Color(constrain(int(R*(100 - n)/100.0),0,255), constrain(int(G*(100 - n)/100.0),0,255), constrain(int(B*(100 - n)/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(pix2-1, myNeo_NeoPixel_2.Color(constrain(int(R*n/100.0),0,255), constrain(int(G*n/100.0),0,255), constrain(int(B*n/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          delay(200);
        }
        vorigpix2 = pix2;
        delay((mathRandomInt(50, 300)));
        pix3 = mathRandomInt(1, aantalPixels);
        for (n = 25; n <= 99; n += 10) {
          myNeo_NeoPixel_2.setPixelColor(vorigpix3-1, myNeo_NeoPixel_2.Color(constrain(int(R*(100 - n)/100.0),0,255), constrain(int(G*(100 - n)/100.0),0,255), constrain(int(B*(100 - n)/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(pix3-1, myNeo_NeoPixel_2.Color(constrain(int(R*n/100.0),0,255), constrain(int(G*n/100.0),0,255), constrain(int(B*n/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          delay(200);
        }
        vorigpix3 = pix3;
        delay((mathRandomInt(50, 300)));
      }
    } else if (code.equals("EFF7")) {
      lus1 = 4;
      lus2 = 3;
      lus3 = 2;
      lus4 = 1;
      while (!(myBTBT_Sensor.available() > 0)) {
        int i_inc4 = 1;
        if (1 > aantalPixels) {
          i_inc4 = -i_inc4;
        }
        for (i = 1;
             i_inc4 >= 0 ? i <= aantalPixels : i >= aantalPixels;
             i += i_inc4) {
          myNeo_NeoPixel_2.setPixelColor(lus1-1, myNeo_NeoPixel_2.Color(constrain(int(R*100/100.0),0,255), constrain(int(G*100/100.0),0,255), constrain(int(B*100/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(lus2-1, myNeo_NeoPixel_2.Color(constrain(int(R*75/100.0),0,255), constrain(int(G*75/100.0),0,255), constrain(int(B*75/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(lus3-1, myNeo_NeoPixel_2.Color(constrain(int(R*50/100.0),0,255), constrain(int(G*50/100.0),0,255), constrain(int(B*50/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          myNeo_NeoPixel_2.setPixelColor(lus4-1, myNeo_NeoPixel_2.Color(constrain(int(R*25/100.0),0,255), constrain(int(G*25/100.0),0,255), constrain(int(B*25/100.0),0,255) ));
          myNeo_NeoPixel_2.show();
          delay(100);
          myNeo_NeoPixel_2.clear();
          lus1 += 1;
          lus2 += 1;
          lus3 += 1;
          lus4 += 1;
          if (lus1 > aantalPixels) {
            lus1 = 1;
          }
          if (lus2 > aantalPixels) {
            lus2 = 1;
          }
          if (lus3 > aantalPixels) {
            lus3 = 1;
          }
          if (lus4 > aantalPixels) {
            lus4 = 1;
          }
        }
      }
    } else if (code.equals("EFF8")) {
      while (!(myBTBT_Sensor.available() > 0)) {
        // theaterchase effect
        for(int a=0; a<10; a++) {  // Repeat 10 times...
          for(int b=0; b<3; b++) { // b counts from 0 to 2...
            myNeo_NeoPixel_2.clear();         //   Set all pixels in RAM to 0 (off)
            for(int c=b; c<myNeo_NeoPixel_2.numPixels(); c += 3) {
              myNeo_NeoPixel_2.setPixelColor(c, myNeo_NeoPixel_2.Color(R,   G,   B)); // Set pixel c  to value  color
            }
            myNeo_NeoPixel_2.show();
            delay(50);
           }
          }
        myNeo_NeoPixel_2.clear();
        myNeo_NeoPixel_2.show();
        // rainbow effect
        for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
           for(int i=0; i<myNeo_NeoPixel_2.numPixels(); i++) {
           int pixelHue = firstPixelHue + (i * 65536L / myNeo_NeoPixel_2.numPixels());
           myNeo_NeoPixel_2.setPixelColor(i, myNeo_NeoPixel_2.gamma32(myNeo_NeoPixel_2.ColorHSV(pixelHue)));
        }
        myNeo_NeoPixel_2.show();
        delay(10);
        }
        myNeo_NeoPixel_2.clear();
        myNeo_NeoPixel_2.show();
        // colorwipe effect
        for(int i=0; i<myNeo_NeoPixel_2.numPixels(); i++) {
          myNeo_NeoPixel_2.setPixelColor(i, myNeo_NeoPixel_2.Color(R,   G,   B));
          myNeo_NeoPixel_2.show();
          delay(50);
        }
        for(int i=0; i<myNeo_NeoPixel_2.numPixels(); i++) {
          myNeo_NeoPixel_2.setPixelColor(i, myNeo_NeoPixel_2.Color(0,0,0));
          myNeo_NeoPixel_2.show();
          delay(50);
        }
          delay(100);
      }
    }
  }

}
