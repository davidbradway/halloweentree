# HalloweenTree :jack_o_lantern: :candy: :chocolate_bar: :ghost:

[Get it in build.partile.io!](https://go.particle.io/shared_apps/5bd2679508d258a1490010ec)

What can you do with a [Particle Holiday Tree shield](https://store.particle.io/products/holiday-tree-pcb) the rest of the year? This Halloween, I'm making mine into the brains of a motion-sensing, music-playing, light-animation-displaying, IoT Jack-o-Lantern!

I took Particle's [firmware for the sheild](https://github.com/particle-iot/xmastree/tree/master/src/firmware) and swapped out the music and light animations for Halloween-appropriate options. I also added [Cheerlights](https://cheerlights.com/) support using the Thingspeak library when you aren't using the animations. Finally, I added support for a Passive Infrared (PIR) motion sensor to activate the lights and sounds as trick or Treaters approach my IoT Jack-o-Lantern!

## LED Animations

- Pulse Orange: all LEDs smoothly fade in and out
- Orange Twinkle: random LEDs light up across the tree

## Piezo Buzzer tunes

- Addams Family theme
- Ghostbusters
- Bewitched

### Notes on creating the piezo buzzer tunes

- I found a source for some Halloween [midi files](https://westnet.com/Halloween/midi/)
- I found a [tool for converting a midi track to Arduino tone buzzer code](https://www.extramaster.net/tools/midiToArduino)
- To find the right track I follwed instructions on the site above and downloaded [MidiYodi](http://www.canato.se/midiyodi/my_download.html)
- Often a track with a simple melody, not percussion or chords, seems to work
- I chose the Midi Speed Factor to be 1X and the Percentage of Tone to Be Played to be 90%
- I cnose for Device the Arduino (C, Tone) option
- To check the track, I copied the source code to an Arduino simulator available at [Autodesk TInkercad Circuits](https://www.tinkercad.com/learn/#/learn/circuits)
- I then had to get the tones and delays in to the format used in `songs.h`. I did this with a lot of ugly search-and-replace, and it could probably be done with some slick regex if I knew that better...

## Contributions

I welcome more animations and songs via Pull Request!

Happy Halloween! :jack_o_lantern: :candy: :chocolate_bar: :ghost:
