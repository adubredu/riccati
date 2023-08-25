riccati_main: main.cpp
	g++ main.cpp riccati.cpp -I/usr/include/eigen3 -I./ riccati.h -o riccati_main