#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	double x0;
	double y0;
	double x1;
	double y1;
	double x;
	double y;
}value;

void Func_Welcome(void);
value Func_Input(void);
double Func_Calc(value variable);

int main(void)
{
	char command;
	int command_size = sizeof(command);
	while (true)
	{
		/* Step. 01: Program Introduction */
		Func_Welcome();

		/* Step. 02: Variable Initialization */
		value variable = Func_Input();

		/* Step. 03: Interpolation Process */
		variable.y = Func_Calc(variable);

		printf("Calculation Result\n");
		printf("\ty = %lf\n\n", variable.y);

		printf("Continue? [y/n]: ");
		scanf_s(" %c", &command, command_size);
		if (command == 'n' || command == 'N')
		{
			printf("Program Done\n");
			break;
		}

		/* Step. 04: Clear CMD console */
		system("cls");
	}

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
	printf("|                    Simple Linear Extrapolation                    |\n");
	printf("|                                                                   |\n");
	printf("| @ author      : Heedo Park                                        |\n");
	printf("| @ execute date: %04d/%02d/%02d, %s                                   |\n", (1900 + now.tm_year), (now.tm_mon + 1), (now.tm_mday), week[now.tm_wday]);
	printf("|                                                                   |\n");
	printf("| - This program performs simple linear extrapolation.              |\n");
	printf("|                                                                   |\n");
	printf("|     Input Variable                                                |\n");
	printf("|                                                                   |\n");
	printf("|          Point A: (x0, y0) -> known value                         |\n");
	printf("|          Point B: (x1, y1) -> known value                         |\n");
	printf("|          Point C: x -> desired point                              |\n");
	printf("|                                                                   |\n");
	printf("|     Output variableiable                                          |\n");
	printf("|                                                                   |\n");
	printf("|          Point C: y -> the value correspontind to 'x'             |\n");
	printf("|                                                                   |\n");
	printf("+-------------------------------------------------------------------+\n\n");
}

value Func_Input(void)
{
	// Variable Initialization
	value variable;
	for (;;)
	{
		// Point A
		printf("Enter Point A (x0, y0)\n");

		printf("\tx0 = ");
		scanf_s("%lf", &variable.x0);

		printf("\ty0 = ");
		scanf_s("%lf", &variable.y0);

		printf("\n");

		// Point B
		printf("Enter Point B (x1, y1)\n");

		printf("\tx1 = ");
		scanf_s("%lf", &variable.x1);

		printf("\ty1 = ");
		scanf_s("%lf", &variable.y1);

		printf("\n");

		if (variable.x0 >= variable.x1)
		{
			printf("Error\n");
			printf("\t- x0 is greater than x1\n");
			printf("\t- therefore, check the values of y0 and y1\n");
			printf("\t- Please enter correct value\n\n");
		}
		else
		{
			break;
		}
	}

	for (;;)
	{
		// Point C
		printf("Enter the x value of Point C located outside x0 and x1\n");

		printf("\tx = ");
		scanf_s("%lf", &variable.x);

		printf("\n");

		if ((variable.x < variable.x1) && (variable.x > variable.x0))
		{
			printf("Error\n");
			printf("\t- The value of x iss inside the range of x0 and x1\n");
			printf("\t- Please enter correct value\n\n");
		}
		else
		{
			break;
		}
	}

	return variable;
}

double Func_Calc(value variable)
{
	double a, b;
	a = (variable.y1 - variable.y0) / (variable.x1 - variable.x0);
	b = variable.y0 - (a * variable.x0);
	variable.y = (a * variable.x) + b;

	return variable.y;
}