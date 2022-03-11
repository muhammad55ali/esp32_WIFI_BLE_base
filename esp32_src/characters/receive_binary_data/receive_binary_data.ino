/*
in this code we are receiving binary data



*/

const byte numBytes = 32;
byte rcvdBytes[numBytes];
byte numReceived = 0;

boolean newData = false;

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
}

void loop() {
    rcvBytesWdStartEndMarkers();
    showData();
}

void rcvBytesWdStartEndMarkers() {
     /*
untill startmarker is arrived all other characters are discarded
after receiving starmarker it will start saving the read characters in array
until endmarker is arrived recieved input will be saved in receivedChar[]
 but will not be printed rather it will repeat the loops till endmarker is recieved
            */
    static boolean rcvInPrgrs = false;
    static byte ndx = 0;
    byte startMarker = 0x3C;
    byte endMarker = 0x3E;
    byte rb;
   

    while (Serial.available() > 0 && newData == false) {
        rb = Serial.read();

        if (rcvInPrgrs == true) {
            if (rb != endMarker) {
                rcvdBytes[ndx] = rb;
                ndx++;
                if (ndx >= numBytes) {
                    ndx = numBytes - 1;
                }
            }
            else {
                rcvdBytes[ndx] = '\0'; // terminate the string
                rcvInPrgrs = false;
                numReceived = ndx;  // save the number for use when printing
                ndx = 0;
                newData = true;
            }
        }

        else if (rb == startMarker) {
            rcvInPrgrs = true;
        }
    }
}

void showData() {
    /*
    
    
    */


    if (newData == true) {
        Serial.print("This just in (HEX values)... ");
        for (byte n = 0; n < numReceived; n++) {
            Serial.print(rcvdBytes[n], HEX);
            Serial.print(' ');
        }
        Serial.println();
        newData = false;
    }}
