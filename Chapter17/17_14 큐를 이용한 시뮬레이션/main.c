#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "LinkedQueue.h"

/*
	min_per_cust = 60.0f / average_n_customers_per_hour;
	x : probabilistic number of n_queued_customers per an hour
*/
bool newcustomer_visit(double x)
{
	if (rand() * x / RAND_MAX < 1.0)
		return true;
	else
		return false;
}

Item get_customer(long arrival_time)
{
	Item cust;

	cust.processtime = rand() % 3 + 1; // 1 - 3
	cust.arrival_time = arrival_time;

	return cust;
}

int main()
{
	Queue waiting_queue;//아이스크림을 받으려고 대기줄에 서있는 손님들

	int simulation_length_in_hours;
	int average_n_customers_per_hour;
	double min_per_cust;
	long cycle, cyclelimit;// 한 사이클은 1분

	/* Statistics */
	long n_lost_customers = 0; // came when queue is full
	long n_queued_customers = 0;//큐에 들어온 손님수
	long n_served_customers = 0;//실제로 아이스크림 만들기를 시작한 손님수
	long sum_line = 0;	// accumulated queue sizes of all time. Used to caculate average.
	int  wait_time = 0; // time left

	long line_wait = 0;	// cumulative time in line

	InitializeQueue(&waiting_queue);

	srand((unsigned int)time(0));	// random initializing of rand()
	//srand(0); // for deterministic debugging

	printf("How many hours do you want to simulate? \n>> ");
	int flag;
	flag = scanf("%d", &simulation_length_in_hours);

	printf("How many customers per hour do you expect? \n>> ");
	flag = scanf("%d", &average_n_customers_per_hour);

	cyclelimit = simulation_length_in_hours * 60;
	min_per_cust = 60.0f / average_n_customers_per_hour;// 이번 사이클에 새로운 손님이 올지 안올지

	for (cycle = 1; cycle <= cyclelimit; cycle++)
	{
		// 새로운 손님이 왔는데
		if (newcustomer_visit(min_per_cust))
		{
			// 큐가 꽉 차있으면 그냥 가버릴 거고
			if (QueueIsFull(&waiting_queue))
			{
				// ___________________
				// 큐가 꽉 차있다면 잃어버린 손님 수 더하고
				n_lost_customers++;
				printf("%3ld : Customer lost\n", cycle);
			}
			// 그렇지 않으면 줄을 서실 수 있게 , 줄서서 아이스크림 주문할 순간을 기다리면서
			// 서비스를 받을시간을 기다리면서
			else 
			{	 
				n_queued_customers++;
				// ___________________
				// ___________________
				// get_customer(cycle) : 몇분이 걸릴 아이스크림을 주문할지를 랜덤넘버로 결정, 도착한 시간이 언제인지
				Item customer_ready = get_customer(cycle);
				EnQueue(customer_ready, &waiting_queue); // 큐에 계속 서있도록 구현
				printf("%3ld : a new customer enqueue.\n", cycle);
			}
		}

		// 주문을 받을 수 있는 상태고 큐가 비어있지 않다면
		if (wait_time <= 0 && !QueueIsEmpty(&waiting_queue))
		{
			// ________________
			// ________________
			Item customer_ready;
			// 손님을 하나 큐에서 꺼내서
			// 아이스크림을 만들어주기 시작을 하면 되겠죠?
			DeQueue(&customer_ready, &waiting_queue);
			printf("%3ld : start serving a customer for %d minutes.\n", cycle, customer_ready.processtime);
			
			// 손님이 새로주문한 아이스크림을 만드는 데 걸리는 시간
			wait_time = customer_ready.processtime;
			line_wait += cycle - customer_ready.arrival_time;
			n_served_customers++;
		}

		// 현재 고객이 주문한 아이스크림이 다 만들어졌는지 만들어지지 않았는지 확인할 수 있겠죠?
		if (wait_time > 0)
			wait_time--;

		sum_line += QueueItemCount(&waiting_queue);
	}

	printf("\n");

	if (n_queued_customers > 0)
	{
		printf("customers accepted: %ld\n", n_queued_customers);
		printf("  customers served: %ld\n", n_served_customers);
		printf("              Lost: %ld\n", n_lost_customers);
		// 평균적으로 큐에 손님들이 몇명이나 서있었는가?
		printf("average queue size: %.2f\n", (double)sum_line / cyclelimit);
		printf(" average wait time: %.2f minutes\n", (double)line_wait / n_served_customers);
	}
	else
	{
		puts("No customers!");
	}

	EmptyTheQueue(&waiting_queue);

	return 0;
}