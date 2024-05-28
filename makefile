# Autor: Toby Wichmann
# Date: 28.05.2024

all:
	g++ -std=c++20 ./src/main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system

linux-install:
	@echo "Install abhängigkeiten"
	sudo apt-get install libsfml-dev -y

clean:
	rm -rf main
