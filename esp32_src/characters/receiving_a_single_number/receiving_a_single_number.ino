/*
in this code we are receiving number as character
convert the character number into integer number using atoi() function
printint the number


*/
const byte numChars = 32;
char rcvdChars[numChars];   // an array to store the received data

boolean newData = false;

int dataNumber = 0;             // new for this version

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
}

void loop() {
    rcvWdEndMarker();
    showNumber();
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
    
    if (Serial.available() > 0) {
        rc = Serial.read();

        if (rc != endMarker) {
            rcvdChars[ndx] = rc;
            ndx++;
            if (ndx >= numChars) {
                ndx = numChars - 1;
            }
        }
        else {
            rcvdChars[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}
/*
convert char number into int number using atoi()
print it on serial monitor
assign 0 to newData 
*/
void showNumber() {
    if (newData == true) {
        dataNumber = 0;             // new for this version
        dataNumber = atoi(rcvdChars);   // new for this version
        Serial.print("This just in ... ");
        Serial.println(rcvdChars);
        Serial.print("Data as Number ... ");    // new for this version
        Serial.println(dataNumber);     // new for this version
        newData = false;
    }
}
