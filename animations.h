/*
 *      Copyright 2017 Particle Industries, Inc.
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 *
 */

#define ANIMATION_COUNT     2

#define PULSEORANGE         0
#define ORANGETWINKLE       1

/* Animation List */
String animationList = "Pulse Orange, Orange Twinkle";

/* An indicator to exit the current LED animation */
bool changeAnimation = false;

uint8_t red(uint32_t c)
{
  return (c >> 8);
}

uint8_t green(uint32_t c)
{
  return (c >> 16);
}

uint8_t blue(uint32_t c)
{
  return (c);
}

uint32_t Color(uint8_t r, uint8_t g, uint8_t b, uint8_t w)
{
  return ((uint32_t) w << 24) | ((uint32_t) r << 16) | ((uint32_t) g <<  8) | b;
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos)
{
    WheelPos = 255 - WheelPos;
    
    if (WheelPos < 85)
        return Color(255 - WheelPos * 3, 0, WheelPos * 3, 0);
    
    if (WheelPos < 170) {
        WheelPos -= 85;
        return Color(0, WheelPos * 3, 255 - WheelPos * 3, 0);
    }
    
    WheelPos -= 170;
    
    return Color(WheelPos * 3, 255 - WheelPos * 3, 0, 0);
}

bool delayAnimation(unsigned duration)
{
    while (duration > 0 && !changeAnimation) {
        unsigned thisDelay = duration > 100 ? 100 : duration;
        delay(thisDelay);
        duration -= thisDelay;
    }
  
    return changeAnimation;
}

bool randomDiff(uint8_t *buf, uint8_t len)
{
    for (uint8_t i = 0; i < len; i++) {
        for (uint8_t j = 0; j < len; j++) {
            if (i != j && buf[i] == buf[j])
                return false;
        }
    }
    return true;
}

/*
 *
 *      LED Animations
 *
 */

void pulseOrange(uint8_t wait)
{
    for (int j = 0; j < 256 ; j++) {

        if (changeAnimation)
            return;

        for (uint16_t i = 0; i < leds.numPixels(); i++)
            leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
        
        delay(wait);
        leds.show();
    }

    for (int j = 255; j >= 0 ; j--) {
        
        if (changeAnimation)
            return;

        for (uint16_t i = 0; i < leds.numPixels(); i++)
            leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
        
        delay(wait);
        leds.show();
    }
}

void orangeTwinkle(uint8_t wait)
{
    uint8_t leftOnIndex[3], rightOnIndex[3];
    
    while(true) {
        
        for (uint8_t i = 0; i < 3; i++) {
            leftOnIndex[i]  = random(13);
            rightOnIndex[i] = random(12);
        }
        
        while (!randomDiff(leftOnIndex, 3)) {
            for (uint8_t i = 0; i < 3; i++)
                leftOnIndex[i]  = random(13);
        }
        
        while (!randomDiff(rightOnIndex, 3)) {
            for (uint8_t i = 0; i < 3; i++)
                rightOnIndex[i]  = random(12);
        }
        
        for (int j = 0; j < 256 ; j++) {
            if (changeAnimation)
                return;
    
            for (uint16_t i = 0; i < leds.numPixels(); i++) {
                
                if (i < 13) {
                    if (i == leftOnIndex[0] || i == leftOnIndex[1] || i == leftOnIndex[2])
                        leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
                    else
                        leds.setPixelColor(i, leds.Color(0,0,0));
                }
                else {
                    uint8_t index = i - 13;
                    if (index == rightOnIndex[0] || index == rightOnIndex[1] || index == rightOnIndex[2])
                        leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
                    else
                        leds.setPixelColor(i, leds.Color(0,0,0));
                }
            }
            
            delay(wait);
            leds.show();
        }
        
        for (int j = 255; j >= 0 ; j--) {
        
            if (changeAnimation)
                return;
    
            for (uint16_t i = 0; i < leds.numPixels(); i++) {
                
                if (i < 13) {
                    if (i == leftOnIndex[0] || i == leftOnIndex[1] || i == leftOnIndex[2])
                        leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
                    else
                        leds.setPixelColor(i, leds.Color(0,0,0));
                }
                else {
                    uint8_t index = i - 13;
                    if (index == rightOnIndex[0] || index == rightOnIndex[1] || index == rightOnIndex[2])
                        leds.setPixelColor(i, leds.Color(255*j/255, 165*j/255, 0));
                    else
                        leds.setPixelColor(i, leds.Color(0,0,0));
                }
            }
            
            delay(wait);
            leds.show();
        }
    }
}
