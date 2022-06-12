
//By HomeMade Electronics
//Subscribe to my channel https://www.youtube.com/channel/UC8isJR_71x1wIfw6jB106pg
//for more tutorial videos
//like, share and leave a comment if you need help

#include<Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,20,4);

char keys[4][3]={
 {'1','2','3'},
 {'4','5','6'},
 {'7','8','9'},
 {'*','0','#'}};
 
byte rowPin[4]={6,7,8,9};
byte colPin[3]={3,4,5};

String password0 = "120";
String password1 = "121";
String password2 = "122";
String password3 = "123";
String password4 = "124";
String password5 = "125";
String password6 = "126";
String password7 = "127";
String password8 = "128";
String password9 = "129";
int position = 0;

int wrong = 0; // Variable to calculate the wrong inputs.

int redPin = 10;
int greenPin = 11;
int buzzer = 12;
 
Keypad keypad=Keypad(makeKeymap(keys),rowPin,colPin,4,3);
// MAPPING THE KEYPAD.


int total = 0; // Variable to determine the number of wrong attempts.

void setup()
{
  
 pinMode(redPin,OUTPUT);
 pinMode(greenPin,OUTPUT);
 pinMode(buzzer, OUTPUT);
 
lcd.init(); //lcd startup
lcd.init();
lcd.backlight();
setLocked(true);
lcd.print(" Enter Unlock Code: ");
delay(20);
}

void loop()
{

  // lcd.clear();
  //lcd.print(" Enter Unlock Code: ");
 
  
  //delay(100);
  
 char pressed=keypad.getKey();
 String key[3];
  
 if(pressed)
 {
  //lcd.clear();
  //lcd.print(" Enter Unlock Code: ");
  lcd.setCursor(position,2);
  lcd.print(pressed);
  //delay(500);
    if(pressed == '*' || pressed == '#')
      {
          position = 0;
          setLocked(true);
          lcd.clear();
      }

    else if(pressed == password0[position] || pressed == password1[position] || pressed == password2[position] || pressed == password3[position] || pressed == password4[position] || 
    pressed == password5[position] || pressed == password6[position] || pressed == password7[position] || pressed == password8[position] || pressed == password9[position])
      {
          key[position]=pressed;
          position++;
      }
 
    else if (pressed != password0[position] && pressed != password1[position] && pressed != password2[position] && pressed != password3[position] && pressed != password4[position] && 
    pressed != password5[position] && pressed != password6[position] && pressed != password7[position] && pressed != password8[position] && pressed != password9[position])
      {
          wrong++;
          position ++;
      }

    if(position == 3){
          if( wrong >0)
            {
                total++;
                wrong = 0;
                position = 0;
                lcd.clear();
                lcd.setCursor(0,2);
                lcd.print("    Wrong Code!     ");
                delay(100);
                setLocked(true);
                lcd.clear();
                lcd.print(" Enter Unlock Code: ");
            }

          else if(position == 3 && wrong == 0)
            {
                position = 0;
                wrong = 0;
                lcd.clear();
                lcd.setCursor(0,1);
                lcd.print("      Welcome!     ");
                lcd.setCursor(5,2);
                lcd.print(" Door Open");
                delay(100);
                setLocked(false);
                lcd.clear();
                lcd.print(" Enter Unlock Code: ");
            }

             

        }

   }

   
}

void setLocked(int locked)
  {
    if (locked)
      {
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
          delay(1000);
      }
    else
      {
          digitalWrite(redPin, LOW);
          digitalWrite(greenPin, HIGH);
          delay(2000);
          digitalWrite(redPin, HIGH);
          digitalWrite(greenPin, LOW);
      }
  }
