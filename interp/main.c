#include <stdio.h>
#include <time.h>

typedef struct
{
	double x1;
	double y1;
	double x2;
	double y2;
	double x;
	double y;
}value;

void Func_Welcome(void);
value Func_Input(void);
double Func_Calc(value p);

int main(void)
{
	/* Step. 01: Program Introduction */
	Func_Welcome();

	/* Step. 02: Variable Initialization */
	value var = Func_Input();
	var.y = Func_Calc(var);

	printf("x1 = %lf\n", var.x1);
	
	return 0;
}

void Func_Welcome(void)
{
	time_t seconds = time(NULL);
	struct tm now;

	localtime_s(&now, &seconds);

	char week[][6] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

	printf("+-------------------------------------------------------------------+\n");
	printf("|                                                                   |\n");
	printf("|                    Simple Linear Interpolation                    |\n");
	printf("|                                                                   |\n");
	printf("| @ author      : Heedo Park                                        |\n");
	printf("| @ execute date: %04d/%02d/%02d, %s                                   |\n", (1900 + now.tm_year), (now.tm_mon + 1), (now.tm_mday), week[now.tm_wday]);
	printf("|                                                                   |\n");
	printf("| - This program performs simple linear interpolation.              |\n");
	printf("|                                                                   |\n");
	printf("|     Input Variable                                                |\n");
	printf("|                                                                   |\n");
	printf("|          Point A: (x1, y1) -> known value                         |\n");
	printf("|          Point B: (x2, y2) -> known value                         |\n");
	printf("|          Point C: x -> desired point                              |\n");
	printf("|                                                                   |\n");
	printf("|     Output Variable                                               |\n");
	printf("|                                                                   |\n");
	printf("|          Point C: y -> the value correspontind to 'x'             |\n");
	printf("|                                                                   |\n");
	printf("+-------------------------------------------------------------------+\n");
}

value Func_Input(void)
{
	// Variable Initialization
	value var;

	printf("x1: ");
	scanf_s("%lf", &var.x1);

	printf("y1: ");
	scanf_s("%lf", &var.y1);

	printf("x2: ");
	scanf_s("%lf", &var.x2);

	printf("y2: ");
	scanf_s("%lf", &var.y2);

	printf("x: ");
	scanf_s("%lf", &var.x);

	return var;
}

double Func_Calc(value p)
{
	p.y = ((p.x - p.x1) / (p.x2 - p.x1)) * (p.y2 - p.y1) + p.y1;

	return p.y;
}