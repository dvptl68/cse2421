/* Dev Patel */
/* Prototype to practice CLA and file input */

#include <stdio.h>

/* Reads the file and stores data in given variables */
void readFile(FILE *fp, int *ballNum, double *X, double *Y, double *Vx, double *Vy) {
    fscanf(fp, "%d %lf %lf %lf %lf", ballNum, X, Y, Vx, Vy);
}

int main(int argc, char **argv) {

    int ballNum;
    double X, Y, Vx, Vy;
    FILE *fp;

    /* Check that a file is given */
    if (argc == 1){

        printf("ERROR: No input file given.\n");

    }else{

        /* Attempt to open given file */
        if (fp = fopen(argv[1], "r")){

            readFile(fp, &ballNum, &X, &Y, &Vx, &Vy);
            printf("Read data:\nballNum: %d\nX: %lf\nY: %lf\nVx: %lf\nVy: %lf\n", ballNum, X, Y, Vx, Vy);
            fclose(fp);

        }else{
            
            printf("ERROR: Unable to open file %s.\n", argv[1]);
        }
        
    }

    return 0;
}

