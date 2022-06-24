CC = g++
PROJECT = main
SRC = main.cpp
LIBS = `pkg-config --cflags --libs opencv4 tesseract`
$(PROJECT) : $(SRC)
	$(CC) $(SRC) $(LIBS) -o $(PROJECT) 