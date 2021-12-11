
#include <Keypad.h>
const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3','A',},
  {'4','5','6','B',},
  {'7','8','9','C',},
  {'*','0','#','D',},
};
byte rowPins[ROWS] = { 9, 8, 7, 6 };
byte colPins[COLS] = { 13,12, 11, 10 }; 
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

char inputArray[4]; //password length
char Main[4] = {'1','2','3','5'}; //main or master password
char Guest[4] = {'1','2','3','4'}; //guest password
int ledpinn=2;
int ledpin=3; //led to register keypad pressses
int buzzer=4; //led that registers correct password entry

int i = 0;
void setup()
{
Serial.begin(9600); //open serial port
pinMode(ledpinn,OUTPUT);
pinMode(ledpin, OUTPUT); //define led pin as output
pinMode(buzzer, OUTPUT); //define led pin as output

}

void loop()
{


 char key = kpd.getKey();

   if(key)
	{

	digitalWrite(buzzer, HIGH);
	delay(100);
	digitalWrite(buzzer, LOW);
	delay(100);
	inputArray[i] = key; 
	i++;
	Serial.println(key); 

	if (key=='*')
	  {
	    Serial.println("Reset");
	    i=0; 
	  }

	if (i == 4) 
	  {
	    {

	    //match input array to password array

		if (inputArray[0] == Guest[0] &&
		inputArray[1] == Guest[1] &&
		inputArray[2] == Guest[2] &&
		inputArray[3] == Guest[3])
		   {
        digitalWrite(ledpin, HIGH);
        digitalWrite(ledpinn, LOW);
        
	
		   }

	if (inputArray[0] == Main[0] &&
		inputArray[1] == Main[1] &&
		inputArray[2] == Main[2] &&
		inputArray[3] == Main[3])
		   {
        digitalWrite(ledpinn, HIGH);
        digitalWrite(ledpin, LOW);
	
		   }
	    }
	    {
	    i=0; //reset i
	    }
	  }
	}
  }



