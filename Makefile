all:
	g++ main.cpp GUI.cpp my_window.cpp simulaatio.cpp mouse_handler.cpp varahteleva_jousipallo.cpp jousipallo.cpp rect.cpp -o Epilepsia-Applet -lSDL2 --std=c++0x -O3 -s
