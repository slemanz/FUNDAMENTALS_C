# 3. Moore and Mealy Finite State Machines (FSM)

- **Moore FSM:** output value depends on only current state.

- **Mealy FSM:** output value depends on both current state and inputs.

## The State Graph

- Defines high-level behavior of the system. 
- States are drawn as circles. 
- Arrows are drawn from one state to another, and labeled with the input value causing that state transition.

## Choosing between Moore FSM and Mealy FSM

### Moore FSM

- Output is necessary to be a state

### Mealy FSM

- No specific output value is necessary to be a state.
- Output is required to transition the machine from one state to the next state.


## FSM Implementation

- We use a linked structure with fixed size.
- There should be one-to-one mapping between the FSM state graph and the data structure.

## Case Study: traffic light system (using moore FSM)

Steps:

1. Define what a state is (e.g. light patterns)
2. Make a list of various states in which system might exists.
3. Add outputs and inputs to enable the system to affect external environment and collect information about environment.

Key points:

- State describes which road has authority to cross the intersection.
- Light pattern defines which road has right of way over the other.

Inputs:

- Car sensor on north
- Car sensor on east

Outputs:

- 6 outputs one for each light in the traffic signal

Decision rules:

1. If no cars are coming stay in green state
2. To change from green to red implement yellow for exactly 5 seconds
3. Green lights should last for at least 30 secongs
4. If cars are only comming in one direction, move to that direction and say in green
5. If cars are coming in both directions cycle through all 4 states.

**[CODE IMPLEMENTATION - MOORE](Src/moore.c)**

**[CODE IMPLEMENTATION - MOORE POINTERS](Src/moore_pointers.c)**

**[CODE IMPLEMENTATION - MOORE FUNCTIONS](Src/moore_functions.c)**

## Case Stury: Engine Control System (Mealy FSM)

2 output

- Brake
- Gas

1 input

- Control

Decision Rules:

1. If stopped and control is low, press brake and remain stopped.
2. If stopped and control is high, release brake and go.
3. If going and control is high, press gas and keep going.
4. If going and control is high, press gas gas keep going.
5. There must be at least 1 ms of no brake, no gas as system switches between go and stop.

**[CODE IMPLEMENTATION - MEALY](Src/mealy.c)**