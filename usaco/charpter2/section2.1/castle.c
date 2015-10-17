/*
ID: huajian2
LANG: C
TASK: castle
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define nil -1
#define visited -2

unsigned char module[50][50];
int room[50][50];
int size[2500];
int room_num, max_size;
int x, y, new_room_size;
char direction;
int M, N;

bool west(unsigned char type) { return type & 0x01;	}	/* 0001 */
bool north(unsigned char type) { return type & 0x02; }	/* 0010 */
bool east(unsigned char type) {	return type & 0x04;	}	/* 0100 */
bool south(unsigned char type) { return type & 0x08; }	/* 1000 */


void flood_fill(int new_room)
{
	int visited_num, i, j;
	do {
		visited_num = 0;
		for (i = 0; i < N; i++) {			/* for each module */
			for (j = 0; j < M; j++) {
				if (room[i][j] == visited) {
					// printf("[%d %d] ", i, j);
					visited_num++;
					room[i][j] = new_room;
					if (!west(module[i][j]))
						if (room[i][j-1] == nil)
							room[i][j-1] = visited;
					if (!north(module[i][j]))
						if (room[i-1][j] == nil)
							room[i-1][j] = visited;
					if (!east(module[i][j]))
						if (room[i][j+1] == nil)
							room[i][j+1] = visited;
					if (!south(module[i][j]))
						if (room[i+1][j] == nil)
							room[i+1][j] = visited;
				}
			}
		}
		size[new_room] += visited_num;
	} while (visited_num);
}

void find_room()
{
	int i, j;
	room_num = -1;
	for (i = 0; i < N; i++) {		/* for each module */
		for (j = 0; j < M; j++) {
			if (room[i][j] == nil) {
				room_num++;
				room[i][j] = visited;
				flood_fill(room_num);
				// printf("\n");
			}
		}
	}
}

main () {
    FILE *fin  = fopen ("castle.in", "r");
    FILE *fout = fopen ("castle.out", "w");
    
    int i, j;
    unsigned int type;

    fscanf (fin, "%d %d", &M, &N);
    for (i = 0; i < N; i++) {
    	for (j = 0; j < M; j++) {
    		fscanf (fin, "%u", &type);
    		module[i][j] = ( unsigned char ) type;
    		room[i][j] = nil;
    		//printf ("%d ", (unsigned char) type);
    	}
    }

    for (i = 0; i < 2500; i++)
    	size[i] = 0;
    max_size = 0;

    find_room();
    fprintf(fout, "%d\n", room_num+1);

    for (i = 0; i <= room_num; i++)
    	if (size[i] > max_size)
    		max_size = size[i];
    fprintf(fout, "%d\n", max_size);

    int new_size;
    for (i = 0; i < N; i++) {
    	for (j = 0; j < M; j++) {
    		if (north(module[i][j]) && i > 0
    			&& room[i][j] != room[i-1][j]) {
    			new_size = size[room[i][j]] + size[room[i-1][j]];
    			if (new_size > new_room_size) {
    				x = i;
    				y = j;
    				direction = 'N';
    				new_room_size = new_size;
    			}
    			else if (new_size == new_room_size) {
    				if (j<y || (j==y && i>x) ) {
    					x = i;
    					y = j;
    					direction = 'N';
    				}
    			}
    		} else if (east(module[i][j]) && j < M-1
    				   && room[i][j] != room[i][j+1]) {
    			new_size = size[room[i][j]] + size[room[i][j+1]];
    			if (new_size > new_room_size) {
    				x = i;
    				y = j;
    				direction = 'E';
    				new_room_size = new_size;
    			}
    			else if (new_size == new_room_size) {
    				if (j<y || (j==y && i>x) ) {
    					x = i;
    					y = j;
    					direction = 'E';
    				}
    			}
    		}
    	}
    }
    fprintf(fout, "%d\n", new_room_size);
    fprintf(fout, "%d %d %c\n", x+1, y+1, direction);


    exit (0);
}