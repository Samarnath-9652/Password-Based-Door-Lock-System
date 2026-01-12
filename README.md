# Password-Based Security System using 8051
This project implements a password-based security system using an 8051 microcontroller, a 4×3 keypad, and a 16×2 LCD display. The system allows access only when the correct password is entered through the keypad. All system messages and user prompts are displayed on the LCD

## Hardware Components
- AT89C51 (8051 Microcontroller)
- 16×2 LCD Display
- 4×3 Matrix Keypad
- Crystal Oscillator (11.0592 MHz)
- Potentiometer
- Reset Circuit
- 5V Power Supply

## Software Tools
- Embedded C
- Keil µVision
- Proteus ISIS

## Working Principle
1. LCD displays "ENTER PASSWORD"
2. User enters password using keypad
3. Each key press is masked with '*'
4. Entered password is compared with stored password
5. If correct, LCD shows "ACCESS GRANTED"
6. If wrong, LCD shows "ACCESS DENIED"

## Features
- Password masking
- Key debounce handling
- Reliable keypad scanning
- Simple and low-cost design

## Applications
- Door access systems
- Electronic lockers
- Security systems
- Embedded systems learning projects
