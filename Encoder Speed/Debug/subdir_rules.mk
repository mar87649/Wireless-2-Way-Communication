################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Encoder\ Speed.cpp: ../Encoder\ Speed.ino
	@echo 'Building file: "$<"'
	@echo 'Invoking: Resource Custom Build Step'
	
	@echo 'Finished building: "$<"'
	@echo ' '

Encoder\ Speed.o: ./Encoder\ Speed.cpp $(GEN_OPTS) | $(GEN_HDRS)
	@echo 'Building file: "$<"'
	@echo 'Invoking: GNU Compiler'
	"C:/Users/Gaming-Jim/AppData/Local/Energia15/packages/energia/tools/msp430-gcc/4.6.5/bin/msp430-gcc.exe" -c -mmcu=msp430g2553 -fno-exceptions -DF_CPU=16000000L -DENERGIA_MSP_EXP430G2553LP -DENERGIA_ARCH_MSP430 -DENERGIA=18 -DARDUINO=10610 -I"C:/Users/Gaming-Jim/AppData/Local/Energia15/packages/energia/tools/msp430-gcc/4.6.5/include" -I"C:/Users/Gaming-Jim/AppData/Local/Energia15/packages/energia/hardware/msp430/1.0.3/cores/msp430" -I"C:/Users/Gaming-Jim/AppData/Local/Energia15/packages/energia/hardware/msp430/1.0.3/variants/MSP-EXP430G2553LP" -I"C:/Users/Gaming-Jim/Google Drive/School/Courses/Lab2/Encoder Speed" -I"C:/Users/Gaming-Jim/AppData/Local/Energia15/packages/energia/tools/msp430-gcc/4.6.5/msp430/include" -O2 -Os -ffunction-sections -fdata-sections -g -gdwarf-3 -gstrict-dwarf -w -Wall -fno-threadsafe-statics -MMD -MP -MF"Encoder Speed.d" -MT"Encoder\ Speed.d" $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


