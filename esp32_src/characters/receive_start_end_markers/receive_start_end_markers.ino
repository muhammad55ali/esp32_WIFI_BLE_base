/*
in this code we are using start and end markers(< and >) 
to tell the arduino when the message is starts and when it ends




*/
const byte numChars = 32;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
}


void loop() {
    recvWithStartEndMarkers();//function calling
    showNewData();// g\function calling
}
/*
untill startmarker is arrived all other characters are discarded
after receiving starmarker it will start saving the read characters in array
until endmarker is arrived recieved input will be saved in receivedChar[]
 but will not be printed rather it will repeat the loops till endmarker is recieved
            */
void recvWithStartEndMarkers() {

    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    char rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();//reading serial monitor and saving its value in rc

        if (recvInProgress == true) {
             
            if (rc != endMarker)
            {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) //
        {
            recvInProgress = true;
        }
    }
}
/*
print array on serial monitor
assign 0 to newData 
*/
void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.println(receivedChars);
        newData = false;
    }
}
