all: compile link

compile:
	g++ -IExternal/include -c src/*.cpp

link:
	g++ *.o -o main -LExternal/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lsfml-audio