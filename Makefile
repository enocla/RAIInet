# == Usage ==
# make:                  compiles dependencies listed in MODULES and source listed in SRC
# make run:              compiles and runs executable listed in TARGET
# make run ARGS="x y z": compiles and runs executable passing in x y z as parameters
# make clean:            deletes all compiled dependencies and executables

# Target executable
TARGET = raiinet

# Source files
SRC = observer.cc observer-impl.cc piece.cc piece-impl.cc player.cc player-impl.cc target.cc squareeffect.cc firewall.cc square.cc square-impl.cc board.cc board-impl.cc command.cc ability.cc ability-impl.cc game.cc game-impl.cc commandinterpreter.cc commandinterpreter-impl.cc view.cc view-impl.cc textdisplay.cc textdisplay-impl.cc graphics.cc graphics-impl.cc main.cc

# Dependencies / Modules
MODULES = iostream vector algorithm sstream string variant random chrono stdexcept set map memory optional

ARGS =

# =============================================================================

# COMP = g++-15.2.0
COMP = g++
COMPFLAGS = -fno-elide-constructors -Wall -std=c++20 -fmodules-ts
MODULEDIR = gcm.cache

all: $(TARGET)

$(TARGET): $(SRC) $(MODULEDIR)/.headers
	@$(COMP) $(COMPFLAGS) -g $(SRC) -o $@

$(MODULEDIR)/.headers: Makefile
	@$(COMP) $(COMPFLAGS) -c -x c++-system-header $(MODULES)
	@touch $@

run: $(TARGET)
	@./$(TARGET) $(ARGS)

clean:
	@rm -rf $(TARGET) $(MODULEDIR)
