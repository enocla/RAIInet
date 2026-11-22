# == Usage ==
# make:                  compiles dependencies listed in MODULES and source listed in SRC
# make run:              compiles and runs executable listed in TARGET
# make run ARGS="x y z": compiles and runs executable passing in x y z as parameters
# make clean:            deletes all compiled dependencies and executables

# Target executable
TARGET = raiinet

# Source files
SRC = 
# Dependencies / Modules
MODULES = iostream vector algorithm sstream string variant random chrono stdexcept

ARGS =

# =============================================================================

# COMP = g++-15.2.0
COMP = g++
COMPFLAGS = -fno-elide-constructors -Wall -std=c++20 -fmodules-ts
MODULEDIR = gcm.cache

all: $(TARGET)

$(TARGET): $(SRC) $(MODULEDIR) # Dependencies for TARGET: SRC and MODULEDIR
	@$(COMP) $(COMPFLAGS) -g $(SRC) -o $@

$(MODULEDIR): # To create MODULEDIR: compile all modules listed in MODULES
	@$(COMP) $(COMPFLAGS) -c -x c++-system-header $(MODULES)

run: $(TARGET)
	@./$(TARGET) $(ARGS)

clean:
	@rm -rf $(TARGET) $(MODULEDIR)
