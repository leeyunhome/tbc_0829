#include <stdio.h>

int main()
{
	/*
		Simulation of a Moving Object

		- Speed = 1.0 m/s
		- dt = 1.0 s
		- Distance traveled during dt = Speed * dt
		
		- Step 1 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m
		- Step 2 : 1.0 m/s * 1.0 s = 1.0 m, dist = 1.0 m + 1.0 m = 2.0 m
		- Step 3 : 1.0 m/s * 1.0 s = 1.0 m, dist = 2.0 m + 1.0 m = 3.0 m
		- ... ...
	*/

	/*
		Zenon's Paradox

		- Step 1 : 1.0 * 1.0 = 1.0, 1.0
		- Step 2 : 1.0 * 0.5 = 0.5, 1.0 + 0.5 = 1.5
		- Step 3 : 1.0 * 0.25 = 0.25, 1.5 + 0.25 = 1.75
	*/

	//const double speed = 1.0;
	//const unsigned repeat_max = 100;
	//
	//double dt = 1.0;
	//double time = 0.0;	// Elapsed time
	//double dist = 0.0;	// Distance

	//for (unsigned i = 0; i < repeat_max; ++i)
	//{
	//	dist += dt * speed;
	//	time += dt;

	//	printf("Elapsed time = %.10fs, Distance = %.10fm\n", time, dist);

	//	dt *= 0.5;
	//}

	// Note: infinite geometric series

	const unsigned repeat_max = 50;
	
	double dt = 0.01;
	double time = 0.0;	// Elapsed time
	//double dist = 0.0;	// Distance
	double dist_arch = 0.0;
	double dist_turtle = 1.0;
	const double arch_speed = 10.0;
	const double turtle_speed = 0.001;

	printf("time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n", time, dt, dist_arch, dist_turtle);

	for (unsigned i = 0; i < repeat_max; ++i)
	{
		dist_arch   += dt * arch_speed;
		dist_turtle += dt * turtle_speed;
		time += dt;
		printf("time = %fs, dt = %fs, Archilleus = %fm, turtle = %fm\n",
			time, dt, dist_arch, dist_turtle);

		dt *= 0.5;
	}

	return 0;
}