void timerInterrupt(){
    pinMode(pinLED, OUTPUT);     
    Timer1.initialize( 500000 );        
    Timer1.attachInterrupt(blinkLED); 
}
