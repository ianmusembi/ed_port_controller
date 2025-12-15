# Embedded-Style Event-Driven(ED) Port Controller (C++)

## Overview
This project simulates an embedded telecom control component responsible for managing a network port.  
The system is implemented using an event-driven architecture with a deterministic main loop, finite state machine (FSM), and software timers, similar to control-plane logic used in networking equipment.

## Architecture
- Single-threaded embedded-style main loop
- Event queue for asynchronous stimuli
- Finite State Machine (FSM)
- Software timers for recovery logic
- Fault detection and recovery handling

## States
INIT → DOWN → UP → ERROR → RECOVERING → DOWN

## Key Features
- Deterministic behavior without OS threads
- Fault injection and recovery mechanism
- Timestamped logging for debugging
- Hardware-independent (runs on Linux/Windows)

## Technologies
- C++17
- Event-driven design
- Finite State Machines
- Software timers

## Motivation
This project demonstrates embedded software design principles commonly used in telecom systems, focusing on reliability, state management, and fault tolerance.
