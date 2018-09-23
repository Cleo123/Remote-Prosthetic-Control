//Thursday, April 10th 2014      By: Cameron Clark

////This sketch uses data from a infared rangefinder connected to analog pin A0
//and uses that to operate a servo connected to digital Pin 9 that is aiming
//the beam of a laser up so that a users hand can "pluck" the laser which
//wobbles back to place.

//General Setup:
//This is designed as a state-based fuction. It is always in one of these states:
//0: At rest.
//1: Tracking a right-handed pluck.
//2: Tracking a left-handed pluck.
//3: Pluck right.
//4: Pluck left.
//5: Returning to rest while listening.



//Additions planned: 
//-Run and power a laser
//-Send out serial info for use in Synth program

#include <Servo.h>
#include <Average.h>

//Variables that might be adjusted.
float decayLength = .1;
int servoPin = 9;
int delayAmount = 0;
int pluckLength = 50;

//Variables that should be constants.
Servo myservo;
int decayCounter = 0;
float decay = 0;
float rangeFinderX;
float userAngle = 0;
float initialAngle = 0;
float servoAngle = 0;
float lastLocationX = 0;
int currentState = 0;
int lastState = 0;
float pluckStrength = 0;
float handSpeed = 0;

void setup() {
  myservo.attach(servoPin);
  Serial.begin(9600);
  delay(1000);
}




void loop() {  
  
  rangeFinderX = rangeFinderValue();   //Get the rangefinder value.
  
  if (rangeFinderX == 132.00)
  {
    rangeFinderX = lastLocationX;
  }
 
  Serial.print("State before if's:  ");
  Serial.print(currentState);
  Serial.print(" RangeFinder Value before Ifs: ");
  Serial.print(rangeFinderX);


  switch(currentState){
      //State 0: At rest and listening...
      case 0:  if (rangeFinderX >= 0 && rangeFinderX < 50)
              {
                currentState = 1;   //If the rangefinder sees a value between 0 and 50, change to right-handed tracking state (1).
              }
      
              if (rangeFinderX < 0 || abs(lastLocationX - rangeFinderX) > 40)
              {
                currentState = 2;   //If the rangefinder sees a value less than 0, change to left-handed tracking state (2).
              }
    //State 1: Tracking a right-handed hand...  
    case 1:  if (rangeFinderX < 0)
             {
                currentState = 3;   //If, while tracking a right handed-pluck, rangeFinder is now less than 0, begin a right-handed pluck (3).
             }
      
             if (rangeFinderX > 50)
             {
                currentState = 0 ;  //If, while tracking right-handed pluck, and rangeFinder is now greater than 50, set the state back to rest (0).
             }
        //State 2: Tracking a left-handed hand...
    case 2: if (rangeFinderX > 0 && rangeFinderX < 40)
             {
                  currentState = 4;   //If, while tracking a left handed-pluck, rangeFinder is now greater than 0 but less than 40, begin a left-handed pluck (4).
             }
      
            if (rangeFinderX > 50)
             {
                  currentState = 0 ;  //If, while tracking left-handed pluck, rangeFinder is now less than -50, set the state back to rest (0).
             }
    //State 3: Right-Handed plucking...  
    case 3:  if (rangeFinderX < 0 && rangeFinderX > -pluckLength)
             {
                  servoAngle = rangeFinderX;   //If the rangefinder sees a value between 0 and -pluckLength (defined above) during a right-handed pluck, set the servo angle to follow the hand. 
             }
      
             if (rangeFinderX > 0 && rangeFinderX < 50)      //If you cross back over the beam, return to right hand tracking (1)
             {
                  currentState = 1;
             }
      
             if (rangeFinderX < -pluckLength || rangeFinderX > 50)  //If you release the string
             {
                  pluckStrength = abs(rangeFinderX);
                  decay = rangeFinderX;
                  decayCounter = 0;
          
                  Serial.print("pluckStrength before State 5: ");
                  Serial.println(pluckStrength);                     //PRINT OUT PLUCK STRENGTH (this should be used for intensity of note)   
          
                  handSpeed = abs(rangeFinderX - lastLocationX);
                  Serial.print("Speed multiplier at release: ");     //PRINT OUT OF SPEED AT PLUCK (this should be used as a volume mulitplier)
                  Serial.println(handSpeed);
          
                  currentState = 5;
             }
      
    //State 4: Left-Handed plucking...
    case 4:  if (rangeFinderX >= 0 && rangeFinderX <= pluckLength)
            {
              servoAngle = rangeFinderX;   //If the rangefinder sees a value between 0 and -pluckLength (defined above) during a right-handed pluck, set the servo angle to follow the hand. 
              myservo.write(map(rangeFinderX, -50, 50, 140, 92));
            }

            if (rangeFinderX < 0)          //If you cross back over the beam, it goes back to tracking left hand (2). 
            {
              currentState = 2;
            }

            if (rangeFinderX > pluckLength)     //If you release the string...
            {
                pluckStrength = abs(rangeFinderX);
                decay = rangeFinderX;
                decayCounter = 0;

                Serial.print("pluckStrength before State 5: ");
                Serial.println(pluckStrength);                     //PRINT OUT PLUCK STRENGTH (this should be used for intensity of note)   

                handSpeed = abs(rangeFinderX - lastLocationX);
                Serial.print("Speed multiplier at release: ");     //PRINT OUT OF SPEED AT PLUCK (this should be used as a volume mulitplier)
                Serial.println(handSpeed);

                currentState = 5;
            }
   //State 4: Wiggle back to rest...    
  case 5: servoAngle = 0;
          currentState = 0;

          servoAngle = decay*sin(decayCounter);
          decay = decay = decay* decayLength;


          myservo.write(map(servoAngle, -50, 50, 140, 92));


          if (decay == 0)
          {
            currentState = 0;
          }

          if (rangeFinderX > -pluckLength && rangeFinderX < pluckLength)
          {
            currentState = 0;
          }
  
  }
  
  
  //Write out the current value of "servoAngle."
  myservo.write(map(servoAngle, -50, 50, 140, 92));
  
  
  //set values for next loop.
  lastLocationX = rangeFinderX;
  lastState = currentState;
  
  delay(delayAmount);
}





//Function that returns the rangefinder value mapped from -50 to 50. 
float rangeFinderValue() {
  float average=0;
  int sampleSize = 9;
  float averageList[sampleSize];
  
  //Build an array of samples
  for(int a = 0; a < sampleSize; a++){
    averageList[a] = analogRead(A0);
   delay(2);
  }
  
  //Find the average (mode) of the samples.
 average = mode(averageList, sampleSize);
  
Serial.print(" Actual read average: ");
 Serial.println(average); 
  
  //Map the voltage value to the usable range of -50 to 50.
  average = map(average, 416, 188, -50, 50);
  
  return(average);
}
