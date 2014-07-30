// 8led.ino
//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9};

void setup(){
	for(int i = 0; i < 8; i++){
		pinMode(ledPins[i],OUTPUT);
	}
}

void loop() {
KnightRider();
}
void KnightRider(){
	for(int i = 0; i <= 7; i++){
		int onLed = i;
		int offLed = i - 1;
		digitalWrite(ledPins[onLed], HIGH);
		if (offLed >=0){
			digitalWrite(ledPins[offLed], LOW);
			delay(100);
			continue;
		}
		// if (offLed <=0){
		// 	offLed = 1;
		// 	digitalWrite(ledPins[offLed], LOW);
		// 	//continue;
		// }
	}
	for(int i = 7; i >= 0; i--){
		int onLed = i;
		int offLed = i + 1;
		digitalWrite(ledPins[onLed], HIGH);
		if (offLed >=0){
			digitalWrite(ledPins[offLed], LOW);
		}
		delay(100);
	}
	
}