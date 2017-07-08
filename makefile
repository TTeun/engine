OBJS = main.cc \
			 game/game.cc \
			 game/display/window/window.cc \
			 game/display/sprite/sprite.cc \
			 game/display/spritebox/spritebox.cc \
			 game/input/keyboard/keyboard.cc \
			 game/input/input.cc \
			 game/util/point/point.cc \
			 game/util/box/box.cc \
			 game/util/color/color.cc \
			 game/gameobjects/player/player.cc \
			 game/gameobjects/level/level.cc \
			 game/physics/rigidbody/rigidbody.cc

CC = g++

COMPILER_FLAGS = -std=c++14 -Wall

LINKER_FLAGS = -lSDL2 -lSDL2_image

OBJ_NAME = a.out

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
