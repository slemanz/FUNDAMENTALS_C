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

