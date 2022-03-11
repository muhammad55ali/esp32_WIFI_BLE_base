/*
In this code we are receiving single character from serial monitor.
get character from user via serial monitor and print it on serial monitor.



*/
char rcvdChar;
boolean newData = false;//newData has initial value of 0

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
}

void loop() {
    rcvSnglChar();//rcvdChar function is called
    showData();//showData is called
}
/*
check serial availability 
read serial monitor
save the character in rcvdChar.
assign 1 to newData 
*/
void rcvSnglChar() {
    if (Serial.available() > 0) {
        rcvdChar = Serial.read();//reading serial monitor and saving its value in rcvdChar
        newData = true;//assigning 1 to newData 
    }
}
/*
after reading character from serial monitor 
print it on serial monitor
assign 0 to newData 
*/
void showData() {
    if (newData == true) {
        Serial.print("This just in ... ");//printing "This just in ... "
        Serial.println(rcvdChar);//printing value in rcvdChar
        newData = false;//assign 0 to newData
    }