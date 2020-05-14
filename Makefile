All:
	gcc -c launch.c -Wall -Wextra
	gcc -o launch launch.c -lm
	gcc launch.c -o launch -lm
	gcc -c tube.c -Wall -Wextra
	gcc -o tube tube.c -lm
	gcc tube.c -o tube -lm
launch:
	gcc -c launch.c -Wall -Wextra
	gcc -o launch launch.c -lm
	gcc launch.c -o launch -lm
tube:
	gcc -o tube.c -Wall -Wextra
	gcc -o tube tube.c -lm
	gcc tube.c -o tube -lm
clean: 
	rm launch launch.o tube tube.o