
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 8, 9, 10, 11);

// set up a constant for the tilt switch pin
const int switchPin = 13;

// variable to hold the value of the switch pin
int switchState = 0;

// variable to hold previous value of the switch pin
int prevSwitchState = 0;

// a variable to choose which reply from the crystal ball
int reply;

void setup() {
  // set up the number of columns and rows on the LCD
  lcd.begin(16, 2);
// set up the switch pin as an input
  pinMode(switchPin, INPUT);

   // Print a message to the LCD.
  lcd.print("Use Arduino To");
  // set the cursor to column 0, line 1
  // line 1 is the second row, since counting begins with 0
  lcd.setCursor(0, 1);
  // print to the second line
  lcd.print("Control LCDs!");

}

void loop() {
// check the status of the switch
  switchState = digitalRead(switchPin);

  // compare the switchState to its previous state
  if (switchState != prevSwitchState) {
    // if the state has changed from HIGH to LOW you know that the button pressed
    if (switchState == LOW) {
      // increment by one message every time the button is pressed
      if (reply <8) {
      reply ++;
      }
      else {
      reply = 0;
      }
      // clean up the screen before printing a new reply
      lcd.clear();
      // set the cursor to column 0, line 0
      lcd.setCursor(0, 0);
      // print some text
      lcd.print("LeMaster Tech");
      // move the cursor to the second line
      lcd.setCursor(0, 1);

      // choose a saying to print based on the value in reply
      switch (reply) {
        case 0:
          lcd.print("Welcome!");
          break;

        case 1:
          lcd.print("So You Want To");
          break;

        case 2:
          lcd.print("Learn to Write");
          break;

        case 3:
          lcd.print("To An LCD With");
          break;

        case 4:
          lcd.print("An Arduino!?");
          break;

        case 5:
          lcd.print("Well You're In");
          break;

        case 6:
          lcd.print("The Right Place!");
          break;

        case 7:
          lcd.print("Let's Do It!!");
          break;
      }
    }
  }
// save the current switch state as the last state
  prevSwitchState = switchState;
}
