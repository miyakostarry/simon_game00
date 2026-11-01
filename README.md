# Simon -bread

<img width="753" height="686" alt="Screenshot 2026-11-02 022008" src="https://github.com/user-attachments/assets/c47c3c69-e006-43bd-a370-3b64abc38bba" />

<img width="985" height="866" alt="image" src="https://github.com/user-attachments/assets/c331a223-58e4-4556-aba1-6e1500571429" />

<img width="678" height="582" alt="image" src="https://github.com/user-attachments/assets/12333675-371e-42ff-8e8d-3d5d28c14947" />

<img width="645" height="711" alt="Screenshot 2026-11-01 232243" src="https://github.com/user-attachments/assets/f0f233de-002e-4f96-82d8-86ad2d0901f1" />

A bread styled-shaped memory game made with a Raspberry Pi Pico.I added some twists so its not the same as the normal one.

## What is it?

The board lights up a led and plays a sound. You have to press the same button for that led back, in the same order. Every round the game adds one more led, so the pattern gets longer and longer and your brain gets more tired.

If you press the wrong led button, all the lights blink and you loose. If you remember 8 steps, you win and the middle led glowes you "won"

## My twists

- **Bread shaped PCB** - the board outline is made of round on one size, i drew it in KiCad. There is also a drawing on the back of the board.
- **Reverse mode** - a slide switch makes you press the pattern BACKWARDS. This is way harder then it sounds.
- **Centre LED** - it stays on in reverse mode so you dont forget wich mode your in, and it glows when you win.
- **Each petal has its own sound** - so you can almost play it like a tiny piano.

## How to play

1. Pick the mode with the slide switch BEFORE you start (one side is Classic, other side is Reverse).
2. Press any button to start.
3. Watch and listen to the pattern.
4. Press the button back. In Classic mode its the same order, in Reverse mode its backwards.
5. Get 8 right to win. Press a wrong one and you loose.

Example: the game shows red, blue, green.
- Classic: you press red, blue, green.
- Reverse: you press green, blue, red.

## Parts

| Part | How many |
|---|---|
| Raspberry Pi Pico (with headers) | 1 |
| 6mm push buttons | 4 |
| 5mm LEDs | 5 (4 petals + 1 centre) |
| 220 ohm resistors | 5 for the LEDs, plus a spare one for the buzzer |
| Passive buzzer (12mm) | 1 |
| SPDT slide switch | 1 |


The code is in the `firmware` folder. To use it:

1. Install Arduino IDE and add the Raspberry Pi Pico board package (the one by Earle Philhower).
2. Choose the board "Raspberry Pi Pico".
3. Hold BOOTSEL, plug in the Pico, and click Upload.

Status: the code is written and compiles, but i have not tested it on the real board yet because im still waiting for the parts and PCB. So there might be bugs, sorry in advance.

## Folders

- `kicad_simon` - the KiCad schematic and PCB
- `gerbers` - the files for the PCB factory
- `firmware` - the Arduino code
- `screenshots` - pictures of the schematic, PCB and 3D view


MADE FOR HACK CLUB HAFF-LIFE
