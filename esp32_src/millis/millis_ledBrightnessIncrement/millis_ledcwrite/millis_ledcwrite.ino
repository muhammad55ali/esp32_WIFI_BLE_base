
const int ledPin = 16;  
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
 unsigned long initial_time;
unsigned long current_time;
const unsigned long delay_sec = 1000; 

void setup(){
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(ledPin, ledChannel);
  Serial.begin(115200); 
  pinMode(ledPin, OUTPUT);

  
    initial_time = millis();


}
 
void loop(){
 current_time = millis(); 
 
    
     if (current_time - initial_time >= delay_sec)  //test whether the period has elapsed
      {
        Serial.print(current_time);
        Serial.print(" / ");
        Serial.println(initial_time);
  
        
     for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){  
        ledcWrite(ledChannel, dutyCycle);
          Serial.println("Lef turned Full Bright"); }
 
    for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
      ledcWrite(ledChannel, dutyCycle); Serial.println("Lef turned LOW");}
    

    
      initial_time = current_time;
        
      }  
}
  

  
