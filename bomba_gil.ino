#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

int hr=0;
int min=1;
int seg=0;
int pinred=7;
int pingreen=8;
int pinbuzzer=6;
int half=0;
int fast=0;
int des=0;
int boom=0;

void setup()
{
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  pinMode(pinred,OUTPUT);
  pinMode(pinbuzzer,OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);  
}

void loop() {
  if (digitalRead(4) != HIGH && des == 0) {
    des = 1;
  } else {
    if (boom != 1) {
      if (des != 1) {
        if (digitalRead(5) != HIGH && boom == 0) {
          boom = 1;
        } else {
          if (digitalRead(2) != HIGH && half == 0) {
            media_cuenta();
            half = 1;
          }
          if (digitalRead(3) != HIGH) {
            fast = 1;
          }

          if (fast != 0) {
            cuenta_acelerada();
          } else {
            cuenta_normal();
          }
        }
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("BOMB DEACTIVATED");
        lcd.setCursor(7, 1);
        lcd.print(seg);
        digitalWrite(pingreen, HIGH);
      }
    } else {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("BOOM TE MORISTE");
      lcd.setCursor(7, 1);
      lcd.print(seg);
      digitalWrite(pinred, HIGH);
    }
  }
}

void cuenta_normal(){
if(seg==0){
   if(min>0){
      seg--;
    min--;
    seg=60;
    lcd.setCursor(0, 0);
    lcd.print("BOMB ACTIVATED");
    lcd.setCursor(0, 1);
    lcd.print("  :  :  ");
      
    if(hr<10){
      lcd.setCursor(1, 1);
      lcd.print(hr);
      lcd.setCursor(0,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(0, 1);
      lcd.print(hr);
    }//horas

    if(min<10){
      lcd.setCursor(4, 1);
      lcd.print(min);
      lcd.setCursor(3,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(3, 1);
      lcd.print(min);
    }//min

    if(seg<10){
      lcd.setCursor(7, 1);
      lcd.print(seg);
      lcd.setCursor(6,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(6, 1);
      lcd.print(seg);
    }//seg
      delay(100);  
    seg--;   
   } else {
      if(hr>0){
        hr--;
        min=60;
      }else{ //EXPLOTO

    lcd.setCursor(0, 0);
      lcd.print("BOOM TE MORISTE");
        lcd.setCursor(7, 1);
        lcd.print(seg);
        digitalWrite(pinred,HIGH);
      }
   }
  }else{
    lcd.setCursor(0, 0);
      lcd.print("BOMB ACTIVATED");
      lcd.setCursor(0, 1);
      lcd.print("  :  :  ");
      
    if(hr<10){
      lcd.setCursor(1, 1);
      lcd.print(hr);
      lcd.setCursor(0,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(0, 1);
      lcd.print(hr);
    }//horas

    if(min<10){
      lcd.setCursor(4, 1);
      lcd.print(min);
      lcd.setCursor(3,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(3, 1);
      lcd.print(min);
    }//min

    if(seg<10){
      lcd.setCursor(7, 1);
      lcd.print(seg);
      lcd.setCursor(6,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(6, 1);
      lcd.print(seg);
    }//seg
    if(seg<= 5 && min==0 && hr == 0){
      digitalWrite(pinbuzzer,HIGH);
      delay(50);    
      digitalWrite(pinbuzzer,LOW);
      delay(150);
      digitalWrite(pinbuzzer,HIGH);
      delay(50);    
      digitalWrite(pinbuzzer,LOW);
      delay(150);  
      digitalWrite(pinbuzzer,HIGH);
      delay(50);    
      digitalWrite(pinbuzzer,LOW);
      delay(150);  
      digitalWrite(pinbuzzer,HIGH);
      delay(50);    
      digitalWrite(pinbuzzer,LOW);
      delay(150);  
      digitalWrite(pinbuzzer,HIGH);
      delay(50);    
      digitalWrite(pinbuzzer,LOW);
      delay(150);  
      seg--;  
    } else {
      digitalWrite(pinbuzzer,HIGH);
      delay(100);   
      digitalWrite(pinbuzzer,LOW);
      delay(900);
      seg--;  
    }
  }  
}


void media_cuenta(){
  if(hr!=0){
    seg+=hr*3600;
  }
  if(min!=0){
    seg+=min*60;
  }
  
  seg/=2;

  if(seg>=3600){
    hr=seg/3600;
    seg-=3600*hr;
  }
  
  if(seg>=60){
    min=seg/60;
    seg-=60*min;
  }

    lcd.setCursor(0, 0);
    lcd.print("CUT DOWN TIME  ");
    digitalWrite(pinbuzzer,HIGH);
    delay(3000);
    half = 1;
}

void cuenta_acelerada(){
if(seg==0){
   if(min>0){
      seg--;
    min--;
    seg=60;
    lcd.setCursor(0, 0);
    lcd.print("HARD MODE      ");
    lcd.setCursor(0, 1);
    lcd.print("  :  :  ");
      
    if(hr<10){
      lcd.setCursor(1, 1);
      lcd.print(hr);
      lcd.setCursor(0,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(0, 1);
      lcd.print(hr);
    }//horas

    if(min<10){
      lcd.setCursor(4, 1);
      lcd.print(min);
      lcd.setCursor(3,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(3, 1);
      lcd.print(min);
    }//min

    if(seg<10){
      lcd.setCursor(7, 1);
      lcd.print(seg);
      lcd.setCursor(6,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(6, 1);
      lcd.print(seg);
    }//seg
      delay(100);  
    seg--;   
   } else {
      if(hr>0){
        hr--;
        min=60;
      }else{ //EXPLOTO

    lcd.setCursor(0, 0);
      lcd.print("BOOM TE MORISTE");
        lcd.setCursor(7, 1);
        lcd.print(seg);
        digitalWrite(pinred,HIGH);
      }
   }
  }else{
    lcd.setCursor(0, 0);
      lcd.print("BOMB ACTIVATED");
      lcd.setCursor(0, 1);
      lcd.print("  :  :  ");
      
    if(hr<10){
      lcd.setCursor(1, 1);
      lcd.print(hr);
      lcd.setCursor(0,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(0, 1);
      lcd.print(hr);
    }//horas

    if(min<10){
      lcd.setCursor(4, 1);
      lcd.print(min);
      lcd.setCursor(3,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(3, 1);
      lcd.print(min);
    }//min

    if(seg<10){
      lcd.setCursor(7, 1);
      lcd.print(seg);
      lcd.setCursor(6,1);
      lcd.print("0");
    }
    else{
      lcd.setCursor(6, 1);
      lcd.print(seg);
    }//seg
    if(seg<= 5 && min==0 && hr == 0){
      digitalWrite(pinbuzzer,HIGH);
      delay(25);    
      digitalWrite(pinbuzzer,LOW);
      delay(75);
      digitalWrite(pinbuzzer,HIGH);
      delay(25);    
      digitalWrite(pinbuzzer,LOW);
      delay(75);  
      digitalWrite(pinbuzzer,HIGH);
      delay(25);    
      digitalWrite(pinbuzzer,LOW);
      delay(75);  
      digitalWrite(pinbuzzer,HIGH);
      delay(25);    
      digitalWrite(pinbuzzer,LOW);
      delay(75);  
      digitalWrite(pinbuzzer,HIGH);
      delay(25);    
      digitalWrite(pinbuzzer,LOW);
      delay(75);  
      seg--;  
    } else {
      digitalWrite(pinbuzzer,HIGH);
      delay(50);   
      digitalWrite(pinbuzzer,LOW);
      delay(450);
      seg--;  
    }
  }  
}