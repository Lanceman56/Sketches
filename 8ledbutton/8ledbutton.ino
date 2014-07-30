// 8led.ino
//LED Pin Variables
int ledPins[] = {2,3,4,5,6,7,8,9};
int inPin = 13;
int button = 0;


void setup(){
	pinMode(inPin,INPUT);
	for(int i = 0; i < 8; i++){
		pinMode(ledPins[i],OUTPUT);
	}
}

void loop() {
	button = digitalRead(inPin);
	if (button == HIGH){
		KnightRider();
	} else {
		inAndOut();
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
	digitalWrite(ledPins[0], LOW);
	
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

	digitalWrite(ledPins[3], LOW);
	digitalWrite(ledPins[4], LOW);
}
