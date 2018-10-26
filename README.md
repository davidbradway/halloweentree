# HalloweenTree

What can you do with a [Particle Holiday Tree shield](https://store.particle.io/products/holiday-tree-pcb) the rest of the year? This Halloween, I'm making mine into the brains of a motion-sensing, music-playing, light-animation-displaying, IoT Jack-o-Lantern!

I took Particle's [firmware for the sheild](https://github.com/particle-iot/xmastree/tree/master/src/firmware) and swapped out the music and light animations for Halloween-appropriate options. I also added [Cheerlights](https://cheerlights.com/) support using the Thingspeak library when you aren't using the animations. Finally, I added support for a Passive Infrared (PIR) motion sensor to activate the lights and sounds as trick or Treaters approach my IoT Jack-o-Lantern!

## LED Animations:

- Pulse Orange: all LEDs smoothly fade in and out
- Orange Twinkle: random LEDs light up across the tree

## Piezo Buzzer tunes

- Addams Family theme
- Ghostbusters
- Bewitched
