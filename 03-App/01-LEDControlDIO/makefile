#------------------------------------------ Setup stage ----------------------------------------#                      
#compile variable&flags
cc = avr-gcc
 
cflags_d = -O0 -g -Wall #debugging flags , d --> debug 
cflags_r = -Os -Wl,--gc-sections # release flags with garbage collection of unused sections  ,r --> release 

#SRC_FILE_LIST
SRC := ../../01-MCAL/01-DIO/DIO_program.c
SRC += main.c

#include path
INCLUDE_PATH :=../../01-MCAL/01-DIO ../../--LIB 
    
#Program (EXC) name
EXC_NAME = release/DIOLed.elf
HEXA_NAME = release/DIOLed.hex
EXC_DEBUG_NAME = Debug/DIOLedDebug.elf
HEXA_DEBUG_NAME = Debug/DIOLedDebug.hex

#MC 
MCU = atmega32
F_CPU = 8000000UL
#--------------------------------------- Debugging stage ----------------------------------------#
#create debug directory if it does not exist 
create_debug_dir:
	@mkdir -p Debug 

# Build for debugging stage
build : create_debug_dir clear_debug_files
	@$(cc) -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(cflags_d) $(SRC) $(addprefix -I,$(INCLUDE_PATH)) -o $(EXC_DEBUG_NAME)
	@avr-objcopy -O ihex $(EXC_DEBUG_NAME) $(HEXA_DEBUG_NAME)
	@echo "Build completed Successfully"
			
# Start debugging with gdb
debug: 
        
	@echo "Starting gdb for debugging..."
	@avr-gdb $(EXC_DEBUG_NAME)
	
# Display the size of the HEX and ELF files in debugging stage 	
size-d :                                         
	@echo "HEXA FORMAT-------> Debug stage\n"
	@avr-size $(HEXA_DEBUG_NAME)
	@echo "ELF FORMAT-------> Debug stage\n"
	@avr-size $(EXC_DEBUG_NAME)
		
# Clean up all generated files (ELF and HEX)		
clear_debug_files :
	@rm -f Debug/*.elf Debug/*.hex	
	@echo "Successfully cleared"		
#--------------------------------------- release stage ----------------------------------------#
#create release directory if it does not exist 
create_release_dir:
	@mkdir -p release

# Build for release stage
release :  create_release_dir clear_release_files
	@$(cc) -mmcu=$(MCU) -DF_CPU=$(F_CPU) $(cflags_r) $(SRC) $(addprefix -I,$(INCLUDE_PATH)) -o $(EXC_NAME)
	@avr-objcopy -O ihex $(EXC_NAME) $(HEXA_NAME)
	@echo "Build completed Successfully"
	
# Clean up all generated files (ELF and HEX)	
clear_release_files :
	@rm -f release/*.elf release/*.hex	
	@echo "Successfully cleared"	
	
# Display the size of the HEX and ELF files in release stage r --> release	
size-r :                                         
	@echo "HEXA FORMAT-------> release stage\n"
	@avr-size $(HEXA_NAME)
	@echo "ELF FORMAT-------> release stage\n"
	@avr-size $(EXC_NAME)	
	
flash : release 
	@avrdude -c usbasp -p m32 -U flash:w:"$(HEXA_NAME)":a
	@echo "Flash programming completed successfully"
#---------------------------------------------------------------------------------------------#

	

		


     
