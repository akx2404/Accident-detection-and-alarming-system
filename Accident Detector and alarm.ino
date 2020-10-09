int GreenLed =10;
int RedLed = 8;
int Shock = 2; 
int Buzzer = 7;
int val; 
int flag=0;

int tones[] = {261, 277, 293, 311, 329, 349, 369, 392, 415, 440, 466, 493, 523 ,554};

#include <SoftwareSerial.h>
SoftwareSerial BTserial(1, 0);


void setup ()
{
  BTserial.begin(9600);
  pinMode (GreenLed, OUTPUT) ; 
  pinMode (RedLed, OUTPUT) ; 
  pinMode (Shock, INPUT) ; //vibration sensor
  pinMode (Buzzer, OUTPUT) ;
}
void loop ()
{
  val = digitalRead (Shock) ; // Reads Digital Pin of sensor.
  if (val == HIGH) // When the shock sensor detects a signal, LED flashes
  {
    digitalWrite (RedLed, LOW);
    digitalWrite (GreenLed, HIGH);
    digitalWrite (Buzzer, LOW);
  }
  else
  {
    flag=1;
    digitalWrite (RedLed, HIGH);
    digitalWrite (GreenLed, LOW);
    digitalWrite(Buzzer, HIGH); // here the Buzzer is set high in order to make a sound.
    tone(Buzzer, tones[9]);
    delay (50);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay (50);
    digitalWrite(Buzzer, HIGH);

    tone(Buzzer, tones[9]);
    tone(Buzzer, tones[9]);
    delay (50);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay (50);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[9]);
    tone(Buzzer, tones[9]);
    delay (50);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay (50);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[9]);
    tone(Buzzer, tones[9]);
    delay (50);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay (50);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[9]);
    tone(Buzzer, tones[9]);
    delay (50);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
    delay (50);
    digitalWrite(Buzzer, HIGH);
    tone(Buzzer, tones[9]);

    
    delay (1000);
    digitalWrite(Buzzer, LOW);
    noTone(Buzzer);
  }

  if(flag==1){
    BTserial.print("ACCIDENT !!!");
    delay(2000);
    flag = 0;
    
  }
}
