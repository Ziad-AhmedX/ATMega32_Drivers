# Project Name: LEDControlDIO Project

## Description
This project is for controlling an LED using AVR-GCC. It includes both debugging and release stages, with appropriate flags for each build configuration.

## Features
- Debugging build with full debug information.
- Release build with optimizations and garbage collection of unused sections.
- Flashing capabilities to upload the firmware to the microcontroller.

## Installation

### Prerequisites
- `avr-gcc`: AVR C compiler.
- `avr-objcopy`: Utility to convert object files to other formats.
- `avr-size`: Tool to display the size of object files.
- `avrdude`: Tool to program the AVR microcontroller.
- **`avrutils`**: Toolset for working with AVR, including size display utilities.

### Setup
1. **Clone the repository:**
   ```bash
   git clone https://github.com/Ziad-AhmedX/ATMega32_Drivers.git


#### Make File Interface -> debug stage  
- `make create_debug_dir`: Create the Debug directory if it does not exist
- `make build`: Build the project for debugging; includes creating the debug directory and cleaning up old debug files
- `make debug`: Start debugging the program using gdb 
- `make size-d`: Display the size of the HEX and ELF files in the debugging stage
- `make clear_debug_files`: Clean up all generated ELF and HEX files from the Debug directory

#### Make File Interface -> release stage  
- `make create_release_dir`: Create release Directory if it does not exist 
- `make release`:  Build for the release stage (includes creating the release directory and cleaning up release files).
- `make size-r`: Display size information of HEX and ELF files in the release stage
- `make flash`:  Upload the firmware to the microcontroller using usbasp
- `make clear_release_files`:  Clean up all generated ELF and HEX files from the release directory



