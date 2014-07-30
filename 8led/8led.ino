// 8led.ino
//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9};

void setup(){
	for(int i = 0; i < 8; i++){
		pinMode(ledPins[i],OUTPUT);
	}
}

void loop() {
//OneAfterAnotherNoLoop();
//OneAfterAnotherLoop();
//OneAtATime();
//inAndOut();
KnightRider();
}

void OneAfterAnotherNoLoop(){
	int delayTime = 100;
	digitalWrite(ledPins[0], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[1], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[2], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[3], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[4], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[5], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[6], HIGH);
	delay(delayTime);
	digitalWrite(ledPins[7], HIGH);
	delay(delayTime);

	digitalWrite(ledPins[0], LOW);
	delay(delayTime);
	digitalWrite(ledPins[1], LOW);
	delay(delayTime);
	digitalWrite(ledPins[2], LOW);
	delay(delayTime);
	digitalWrite(ledPins[3], LOW);
	delay(delayTime);
	digitalWrite(ledPins[4], LOW);
	delay(delayTime);
	digitalWrite(ledPins[5], LOW);
	delay(delayTime);
	digitalWrite(ledPins[6], LOW);
	delay(delayTime);
	digitalWrite(ledPins[7], LOW);
	delay(delayTime);
}

void OneAfterAnotherLoop(){
	int delayTime = 100;
	for(int i = 0; i <= 7; i++){
			digitalWrite(ledPins[i], HIGH);
			delay(delayTime);
	}
	for(int i = 7; i >=0; i--){
		digitalWrite(ledPins[i], LOW);
		delay(delayTime);
	}
}

void OneAtATime(){
	int delayTime = 100;

	for(int i = 0; i <=7; i++){
		int offLed = i - 1;
		if(i == 0) {
			offLed = 7;
		}
		digitalWrite(ledPins[i], HIGH);
		digitalWrite(ledPins[offLed], LOW);
		delay(delayTime);
	}
}

void inAndOut(){
	int delayTime = 100;
	for(int i = 0; i <=3; i++){
		int offLed = i - 1;
		if(i == 0) {
			offLed = 3;
		}
		int onLED1 = 3 - i;
		int onLED2 = 4 + i;
		int offLed1 = 3 - offLed;
		int offLed2 = 4 + offLed;
		digitalWrite(ledPins[onLED1], HIGH);
		digitalWrite(ledPins[onLED2], HIGH);
		digitalWrite(ledPins[offLed1], LOW);
		digitalWrite(ledPins[offLed2], LOW);
		delay(delayTime);
	}

	for(int i = 3; i>=0; i--){
		int offLed = i + 1;
		if(i == 3) {
			offLed = 0;
		}
		int onLED1 = 3 - i;
		int onLED2 = 4 + i;
		int offLed1 = 3 - offLed;
		int offLed2 = 4 + offLed;
		digitalWrite(ledPins[onLED1], HIGH);
		digitalWrite(ledPins[onLED2], HIGH);
		digitalWrite(ledPins[offLed1], LOW);
		digitalWrite(ledPins[offLed2], LOW);
		delay(delayTime);
	}
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
