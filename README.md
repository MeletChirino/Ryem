# Ryem
An approach to RTOS in arduino
# Compiling Line
clear && g++ -Wall -Werror main.c Task.cpp Event.cpp test.c StateMachine.cpp -o tex.o && ./tex.o
scons --tree=all
