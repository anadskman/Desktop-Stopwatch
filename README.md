# Desktop Stopwatch

A small physical stopwatch I built using an ESP32 and 7-segment displays. 
It sits on a desk and uses one-button to control it.

---

## Features

- 4-digit display for hours and minutes (HH:MM)
- Extra digit for seconds (counts every 10 Seconds, 0-9 = 0, 10-19=1, ect)
- One button:
  - Press → start / stop
  - Hold → reset
- Wired on a stripboard

---

## Hardware

- ESP32-C3 Super Mini  
- 4-digit 7-segment display  
- Single 7-segment display  
- Push button  
- 7x 330Ω resistors  
- Stripboard  

---

## How it works

The digits are controlled using multiplexing, so only one digit is on at a time but it looks continuous.

Time is tracked using the ESP32 and updated every second.

---

## Build

Everything is soldered onto stripboard and mounted in a small case.

---

## Preview

<img width="1083" height="489" alt="Screenshot 2026-04-01 133248" src="https://github.com/user-attachments/assets/cf2ee3b7-9572-4462-90e7-6ca1efdcf8c0" />
<img width="973" height="545" alt="Screenshot 2026-04-01 215338" src="https://github.com/user-attachments/assets/c5d028cd-490f-43bd-a774-6286690873c9" />
