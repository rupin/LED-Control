#include "FastLED.h"

// How many leds are in the strip?
#define NUM_LEDS 60

// Data pin that led data will be written out over
#define DATA_PIN 6

// Clock pin only needed for SPI based chipsets when not using hardware SPI
//#define CLOCK_PIN 8

// This is an array of leds.  One item for each led in your strip.
CRGB leds[NUM_LEDS];
int LEDIndex=0;

boolean redArray=false;


// This function sets up the ledsand tells the controller about them
void setup() {
	// sanity check delay - allows reprogramming if accidently blowing power w/leds
   	delay(2000);
        //Serial.begin(115200);
      // Uncomment one of the following lines for your leds arrangement.
      // FastLED.addLeds<TM1803, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1804, DATA_PIN, RGB>(leds, NUM_LEDS);
      // FastLED.addLeds<TM1809, DATA_PIN, RGB>(leds, NUM_LEDS);
      FastLED.addLeds<UCS1903B, DATA_PIN, RGB>(leds, NUM_LEDS);
      //setLEDArray(redArray);
      //FastLED.show();
      
}

void loop()
{
  //Serial.println("******Starting Loop*****************");
 redArray=!redArray;
 setLEDArray(redArray);
 FastLED.show();
 delay(1000);
 
  
}  

void setLEDArray(boolean colorChanged)
{
  //Serial.println("***********************");
  boolean lredArray=colorChanged;
  int index;
   for(index=0;index<NUM_LEDS;index=index+1 )
      {
        if(index%10==0 && index!=0)
        {
          lredArray=!lredArray;
        }  
        if(lredArray)
        {
           leds[index]=CRGB::Red;
                       
        }
        else
        {
          leds[index]=CRGB::Green; 
        } 
        /*Serial.print(index, DEC);
        Serial.print("\t"); 
        Serial.println(lredArray);*/
        
      
      }   
  
}  

