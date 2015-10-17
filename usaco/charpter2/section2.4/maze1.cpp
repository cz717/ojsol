/*
ID: huajian2
LANG: C++
TASK: maze1
*/
#include <stdio.h>
#include <stdlib.h>
#include <queue>
using namespace std; 
#define infinity 3801

struct point {
    int x;
    int y;

    point (int a = 0, int b = 0) {
        x = a;
        y = b;
    }

    bool operator == (const point &a) {
        return x == a.x && y == a.y;
    }

};

int h, w;
char maze[201][77];
int dis[100][38];
point exits[2];
queue<point> q;
point sign(-1, -1);

int get_dis(point pt) {
    return dis[pt.x][pt.y];
}

void set_dis(point pt, int d) {
    dis[pt.x][pt.y] = d;
}

point convert(point pt, int dir) {
    point npt = pt;
    if (dir == 0)   --npt.x;
    if (dir == 1)   ++npt.x;
    if (dir == 2)   --npt.y;
    if (dir == 3)   ++npt.y;
    return npt;
}

char get_maze(point pt, int dir) {
    point npt(2 * pt.x + 1, 2 * pt.y + 1);
    npt = convert(npt, dir);
    return maze[npt.x][npt.y];
}


main () {
    FILE *fin  = fopen ("maze1.in", "r");
    FILE *fout = fopen ("maze1.out", "w");
    int i, j, e, dir;
    int max_dis, new_dis;
    point pt, npt;

    fscanf (fin, "%d %d", &w, &h);
    fgets(maze[0], 2, fin);
    for (i = 0; i < 2*h+1; i++) {
        fgets(maze[i], 2*w+3, fin);
        maze[i][2*w+1] = '\0';
    }

    // for (i = 0; i < 2*h+1; i++)
    //     printf("%s\n", maze[i]);

    /* find the exits */
    for (i = 0; i < w; i++) {
        if (maze[0][2*i+1] == ' ') {
            exits[e++] = point(0, i);
            maze[0][2*i+1] = '-';
        }
        if (maze[2*h][2*i+1] == ' ') {
            exits[e++] = point(h-1, i);
            maze[2*h][2*i+1] = '-';
        }
    }
    for (i = 0; i < h; i++) {
        if (maze[2*i+1][0] == ' ') {
            exits[e++] = point(i, 0);
            maze[2*i+1][0] = '|';
        }
        if (maze[2*i+1][2*w] == ' ') {
            exits[e++] = point(i, w-1);
            maze[2*i+1][2*w] = '|';
        }
    }

    
    // for (i = 0; i < 2*h+1; i++)
    //     printf("%s\n", maze[i]);
    // printf("exits: [%d %d] [%d %d]\n", exits[0].x, exits[0].y, exits[1].x, exits[1].y);

    /* initial the dis */
    for (i = 0; i < h; i++)
        for (j = 0; j < w; j++)
            dis[i][j] = infinity;

    /* bfs */
    q.push(exits[0]);
    q.push(exits[1]);
    q.push(sign);
    dis[exits[0].x][exits[0].y] = 1;
    dis[exits[1].x][exits[1].y] = 1;
    max_dis = 1;

    while (!q.empty()) {
        pt = q.front();
        q.pop();

        if (pt == sign) {
            if (q.empty())      /* all visited */
                break;
            else {              
                q.push(sign);   
                continue;
            }
        }

        new_dis = get_dis(pt) + 1;
        for (dir = 0; dir < 4; dir++) {
            npt = convert(pt, dir);
            if (get_maze(pt, dir) == ' ' && get_dis(npt) > new_dis) {
                set_dis(npt, new_dis);
                q.push(npt);
                max_dis = new_dis;
            }

        }
    }

    // for (i = 0; i < h; i++) {
    //     for (j = 0; j < w; j++)
    //         printf("%d ", dis[i][j]);
    //     printf("\n");
    // }
    
    fprintf(fout, "%d\n", max_dis);

    exit (0);
}
