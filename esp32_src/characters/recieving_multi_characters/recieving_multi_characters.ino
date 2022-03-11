/*
In this code we are receiving multi character from serial monitor.
read serial monitor 
store each character in array
using endmarker to ensure that full message is received
after full message us received print it on serial monitor
*/
const byte numChars = 32;
char rcvdChars[numChars];   // an array to store the received data

boolean newData = false;

void setup() {
    Serial.begin(9600);
    Serial.println("<Arduino is ready>");
}

void loop() {
    rcvWdEndMarker();
    showData();

    
}
/*
define endmarker
define rc 
read serial monitor until endmarker is received
saved each read character into rc
saved each read character into array.
*/
void rcvWdEndMarker() {
    static byte ndx = 0;
    char endMarker = '\n';
    char rc;
    
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (rc != endMarker) {
            rcvdChars[numChars]= rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            rcvdChars[numChars] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}
/*
print array on serial monitor
assign 0 to newData 
*/
void showData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(rcvdChars);
        newData = false;
    }
}
