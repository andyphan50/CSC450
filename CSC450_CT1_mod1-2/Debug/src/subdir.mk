################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/CSC450_CT1_mod1-2.cpp 

CPP_DEPS += \
./src/CSC450_CT1_mod1-2.d 

OBJS += \
./src/CSC450_CT1_mod1-2.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/CSC450_CT1_mod1-2.d ./src/CSC450_CT1_mod1-2.o

.PHONY: clean-src

