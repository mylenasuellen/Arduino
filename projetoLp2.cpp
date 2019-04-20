// include the library code:
#include <LiquidCrystal.h>
#include <time.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int blocked  = 6; //vermelho
const int pronto = 7; //azul
const int enter = 8; //verde
const int accessButton = 9; //botão
int buttonState = 0;
int lastButtonState = 0;
int buttonPushCounter = 0;

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode (blocked,OUTPUT);
  pinMode (pronto,OUTPUT);
  pinMode (enter,OUTPUT);
  pinMode (accessButton,INPUT);

}
void acesso(){
  {
  // read the pushbutton input 
  buttonState = digitalRead(accessButton);
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button
      // went from off to on
      buttonPushCounter += 1;
      
    }
    // delay a little bit to avoid debouncing
    delay(5); // Wait for 5 millisecond(s)
  }
  /* save the current state as the last state, for
  the next time through the loop*/
  lastButtonState = buttonState;
  /*turns on the LED every two button pushes by
   checking the modulo of the button push counter.
   the modulo function gives you the remainder of
   the devision of two numbers*/
  if (buttonPushCounter % 2 == 0) {
    digitalWrite(pronto, HIGH);
  } else {
    digitalWrite(pronto, LOW);
  }
}
void loop() {
  acesso();

}
 