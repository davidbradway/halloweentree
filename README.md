# HalloweenTree :jack_o_lantern: :candy: :chocolate_bar: :ghost:

[Get it in build.partile.io!](https://go.particle.io/shared_apps/5bd2679508d258a1490010ec)

What can you do with a [Particle Holiday Tree shield](https://store.particle.io/products/holiday-tree-pcb) the rest of the year? This Halloween, I'm making mine into the brains of a motion-sensing, music-playing, light-animation-displaying, IoT Jack-o-Lantern!

Changes made

- I took Particle's [firmware for the sheild](https://github.com/particle-iot/xmastree/tree/master/src/firmware) and swapped out the music and light animations for Halloween-appropriate options. 
- I also added the option to use [Cheerlights](https://cheerlights.com/) via the Thingspeak library when you aren't using the animations
- Finally, I added a Passive Infrared (PIR) motion sensor to activate the lights and sounds as trick-or-treaters approach 

## LED Animations

- Pulse Orange: all LEDs smoothly fade in and out
- Orange Twinkle: random LEDs light up across the tree

## Piezo Buzzer tunes

- Addams Family theme
- Ghostbusters
- Bewitched

### Notes on creating the piezo buzzer tunes

- I found some Halloween [midi files](https://westnet.com/Halloween/midi/)
- I found a [tool for converting a midi track to Arduino tone buzzer code](https://www.extramaster.net/tools/midiToArduino)
- To find the right track, I followed instructions on the site above and downloaded [MidiYodi](http://www.canato.se/midiyodi/my_download.html)
- Often a track with a simple melody, not percussion or chords, seems to work
- I chose the Midi Speed Factor to be 1X 
- The Percentage of Tone to Be Played was left at 90%
- I chose for Device, the Arduino (C, Tone) option
- To check the track, I used an Arduino simulator available at [Autodesk TInkercad Circuits](https://www.tinkercad.com/learn/#/learn/circuits)
- I selected the Arduino Uno and connected a piezo buzzer to pin 11 and ground
- I copied the source code and ran the simulation 
- I then had to get the tones and delays into the array format used in `songs.h`. I did this with a lot of ugly search-and-replace, but it could probably be done with some slick regex (wish I knew that better...)

## Contributions

Written by Particle and modified by David Bradway.

I welcome more animations and songs via Pull Request!

Happy Halloween! :jack_o_lantern: :candy: :chocolate_bar: :ghost:
