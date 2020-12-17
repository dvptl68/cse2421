/* Dev Patel */

#define CONVERSION 1000 /* Constant to convert seconds to milliseconds */
#define SLEEP 2000 /* Sleep time between ball simulations */

void outputStart(int ballNum);
void outputBall(int ballNum, double xPos, double yPos, double totalTime, double dT);
void outputEnd(int ballNum, double xPos, double yPos, double totalTime);

