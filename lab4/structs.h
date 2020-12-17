/* Dev Patel */

/* Struct to hold simulation information */
struct Sim {
    double elapsed;
    double dT;
    void *head;
    FILE *fp;
};

/* Struct to hold ball information */
struct Ball {
    int ballNum;
    double X;
    double Y;
    double Vx;
    double Vy;
    struct Sim *table;
};

