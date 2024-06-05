# Autor: Toby Wichmann
# Date: 28.05.2024

all:
	g++ -std=c++20 -Isrc/include ./src/*.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

linux-install:
	@echo "Install abhängigkeiten"
	sudo apt-get install libsfml-dev libxrandr-dev libxcursor-dev libudev-dev libfreetype-dev libopenal-dev libflac-dev libvorbis-dev libgl1-mesa-dev libegl1-mesa-dev -y
clean:
	rm -rf main
