# C8051F410-Microcontroller-Vote-Counter
Single-chip Microcomputer Programming 


#1. Introduction

A Polling System is one in which people can cast or record their votes when making decisions either on matters like deciding who the best candidate for a higher-up office within an organization would be or something of a smaller nature like deciding a class representative. Such kind of decision making is tough to make without outside influence of peers since half the time there isn’t any provision for anonymity of the voter and proper record keeping. To overcome such a problem, I decided to make a polling system based on C8051F410 microcontroller. 

#2. Design
The main component in the circuit is C8051F410 controller. A 4x4 keypad attached to the chip is used for casting the votes. For the system to be effective there has to be at least two buttons assigned for each vote. Each vote has to count for only one person and an incremental count assigned to it. The system has to display what is being voted on and the options for the voters to choose from. There has to be no biased answers that may lead to misinterpretation on the vote count. At least two options have to be provided to be voted on.

#3. Requirements

#Hardware

i.	C8051F410 board
Features of 8051:
•	It is an 8-bit CPU.
•	It has 4KB ROM on chip (i.e. program memory).
•	128 bytes RAM on chip (i.e. Data memory).
•	It can address 64KB of program memory.
•		It can address 64KB of data memory.
•	It has two 16-bit counter / Timer.
•	It has 32 I/O lines (four 8-bit I/O ports)
•	Full featured serial port.
•	It has Powerful 111-instructions instruction set.

ii.	16x4 LED display
LCDs are more energy efficient and offer safer disposal than CRTs. Its low electrical power consumption enables it to be used in battery-powered electronic equipment. It is an electronically modulated optical device made up of any number of segments filled with liquid crystals and arrayed in front of a light source (backlight) or reflector to produce images in color or monochrome. The most flexible ones use an array of small pixels

iii.	4x4 Matrix Keyboard
Since this project can be expanded for a broader use, a 4x4 keyboard attached to the board is a great addition. It will allow for a more answers on the opinions to votes for in the future.
	
	
	
#4. Software
Keil_ µVision V5.25.3.0

	
IDE-Version:
µVision V5.25.3.0
Copyright (C) 2018 ARM Ltd and ARM Germany GmbH. All rights reserved.

License Information:
Talent Paul Mavingire
LIC=----

Tool Version Numbers:
Toolchain:        PK51 Prof. Develpers Kit  Version: 9.59.0.0
Toolchain Path:    C:\Keil_v5\C51\BIN
C Compiler:         C51.exe    V9.59.0.0
Assembler:          A51.exe    V8.2.7.0
Linker/Locator:     BL51.exe    V6.22.2.0
Librarian:             LIB51.exe    V4.30.1.0
Hex Converter:      OH51.exe    V2.7.0.0
CPU DLL:               S8051.DLL            V3.122.0.0
Dialog DLL:         DCYG.DLL             V2.75.0.0
Target DLL:             SiC8051F.dll         V4.3.0.0
Dialog DLL:         TCYG.DLL             V2.72.0.0

#5. The Solution and program ideas

For simplicity in demonstrating the concept of the project, I only included one opinion to be voted upon. Furthermore, to reduce any kind of bias in the answers, I only included a “YES/NO” response. As people vote, they are anonymous since this system will provide an alternative to paper-based methods that have a risk of detecting who voted on what through tracing. Additional using this system reduces the time taken for vote counting as it is in real time. There is a count for each vote which is incremented as the voters decide on what they want.

#6. Experimental results and analysis

There is a global variable declared for “YES” and “NO” that will keep count of the votes. When the button is pressed it sends an interrupt which will trigger an increase in the option for yes/no according to what the use has pressed. “YES’ button is connected to external interrupt 0 and “NO” is connected external interrupt 1. 

#7. Summary and outlook
The project can be expanded for various uses across different fields. It can be used with classes for instance when deciding on the time periods to have classes amongst other things. This is merely a scratch of the surface and many additions can be assigned to work with this design. 





