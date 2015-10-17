/*
ID: huajian2
LANG: C
TASK: ride
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    long c = 1, g = 1;
    char comet[7], group[7];
    int i, cl, gl;

    fscanf (fin, "%s\n%s", comet, group);
    cl = strlen(comet);
    gl = strlen(group);
    for (i = 0; i < cl; i++)
    	c *= comet[i] - 'A' + 1;
    for (i = 0; i < gl; i++)
    	g *= group[i] - 'A' + 1;
    
    if (c%47 == g%47)
    	fprintf (fout, "GO\n");
    else
    	fprintf (fout, "STAY\n");
    
    exit (0);
}
