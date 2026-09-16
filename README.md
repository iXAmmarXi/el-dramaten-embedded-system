# El-Dramaten – Embedded Motor Control System

El-Dramaten is a motorized shopping trolley prototype developed as part of the **HE1043 Project Course at KTH Royal Institute of Technology**.

The project combines embedded software, electronics and motor control to create a trolley designed to reduce the physical effort required when transporting groceries.

## Features

- DC motor speed and direction control
- PWM-based motor control
- Analog input using ADC
- Battery level monitoring
- LCD interface with battery status
- Emergency stop functionality
- Custom electronic circuit and PCB
- Forward, reverse and stop control

## System Architecture

The system is based on a **GD32VF103 RISC-V 32-bit microcontroller**.

A potentiometer provides an analog control signal that is converted using the microcontroller's ADC. The resulting value is used to generate PWM signals for controlling the DC motors through a **DRV8833 dual H-bridge motor driver**.

Battery voltage is also measured using ADC and the battery status is displayed on an LCD.

## Technologies & Components

- C
- Embedded Systems
- RISC-V
- GD32VF103 Microcontroller
- DRV8833 Motor Driver
- DC Motors
- PWM (Pulse Width Modulation)
- ADC (Analog-to-Digital Conversion)
- KiCad
- PCB Design
- LCD Interface
- Electronics

## Motor Control

The analog signal from the potentiometer is converted into a 12-bit digital value using the microcontroller's ADC.

The value is then used to determine the motor direction and generate a PWM signal for speed control. The motor driver enables forward, reverse and stop operation.

## Battery Monitoring

Battery voltage is sampled through the ADC. Multiple measurements are collected and averaged before the calculated battery level is displayed on the LCD.

The interface provides visual battery status information and a low-battery indication.

## Project Context

**Course:** HE1043 Project Course  
**University:** KTH Royal Institute of Technology  
**Location:** Flemingsberg, Sweden  
**Year:** 2023  

This project was developed as a team project. It involved embedded programming, electronics, hardware integration, system design, testing and technical documentation.
