unsigned long prdStrtMillis;
unsigned long currentMillis;
const unsigned long period = 5000;  //period during which button input is valid
const byte buttonPin = 16;    //button on pin A1
byte crrntBttnState;
byte prevsBttnState;
int count = 0;
boolean printFinalMsg = true;
unsigned long debncStrtMillis;
unsigned long debncPeriod = 20;
boolean debouncing = false;

void setup()
{
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.println("Press the button as many times a possible in 5 seconds");
  prdStrtMillis = millis();
}

void loop()
{
  currentMillis = millis();
  if (currentMillis - prdStrtMillis <= period)  //true until the period elapses
  {
    prevsBttnState = crrntBttnState;    //save the previous button state
    crrntBttnState = digitalRead(buttonPin);  //read the current state of the input
    if (crrntBttnState != prevsBttnState) //if the button state has changed
    {
      debncStrtMillis = currentMillis;  //save the time that the state change occured
      debouncing = true;  //flag that debouncing in progress
    }    //end state change check
    
    if (currentMillis - debncStrtMillis >= debncPeriod)  //if the debounce period has elapsed
    {
      if (debouncing == true)    //debouncing taking place
        {
        if (crrntBttnState == LOW)  //if the button is currently pressed
              {
          debouncing = false;    //debouncing is finished
          count++;               //increment the count
          Serial.println(count);
              }    //end count increment
        }  //end debouncing in progress check
    }    //end debounce time elapsed check
  }  //end timing period check
  else  //period has ended
  {
    if (printFinalMsg == true)
    {
      Serial.println("Time is up");
      Serial.print("Button pressed count : ");
      Serial.println(count);
      printFinalMsg = false;    //prevent the final message being displayed again
    }    //end printing final message
  }    //end final message check
}
