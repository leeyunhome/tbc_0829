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
	Queue waiting_queue;//���̽�ũ���� �������� ����ٿ� ���ִ� �մԵ�

	int simulation_length_in_hours;
	int average_n_customers_per_hour;
	double min_per_cust;
	long cycle, cyclelimit;// �� ����Ŭ�� 1��

	/* Statistics */
	long n_lost_customers = 0; // came when queue is full
	long n_queued_customers = 0;//ť�� ���� �մԼ�
	long n_served_customers = 0;//������ ���̽�ũ�� ����⸦ ������ �մԼ�
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
	min_per_cust = 60.0f / average_n_customers_per_hour;// �̹� ����Ŭ�� ���ο� �մ��� ���� �ȿ���

	for (cycle = 1; cycle <= cyclelimit; cycle++)
	{
		// ���ο� �մ��� �Դµ�
		if (newcustomer_visit(min_per_cust))
		{
			// ť�� �� �������� �׳� ������ �Ű�
			if (QueueIsFull(&waiting_queue))
			{
				// ___________________
				// ť�� �� ���ִٸ� �Ҿ���� �մ� �� ���ϰ�
				n_lost_customers++;
				printf("%3ld : Customer lost\n", cycle);
			}
			// �׷��� ������ ���� ���� �� �ְ� , �ټ��� ���̽�ũ�� �ֹ��� ������ ��ٸ��鼭
			// ���񽺸� �����ð��� ��ٸ��鼭
			else 
			{	 
				n_queued_customers++;
				// ___________________
				// ___________________
				// get_customer(cycle) : ����� �ɸ� ���̽�ũ���� �ֹ������� �����ѹ��� ����, ������ �ð��� ��������
				Item customer_ready = get_customer(cycle);
				EnQueue(customer_ready, &waiting_queue); // ť�� ��� ���ֵ��� ����
				printf("%3ld : a new customer enqueue.\n", cycle);
			}
		}

		// �ֹ��� ���� �� �ִ� ���°� ť�� ������� �ʴٸ�
		if (wait_time <= 0 && !QueueIsEmpty(&waiting_queue))
		{
			// ________________
			// ________________
			Item customer_ready;
			// �մ��� �ϳ� ť���� ������
			// ���̽�ũ���� ������ֱ� ������ �ϸ� �ǰ���?
			DeQueue(&customer_ready, &waiting_queue);
			printf("%3ld : start serving a customer for %d minutes.\n", cycle, customer_ready.processtime);
			
			// �մ��� �����ֹ��� ���̽�ũ���� ����� �� �ɸ��� �ð�
			wait_time = customer_ready.processtime;
			line_wait += cycle - customer_ready.arrival_time;
			n_served_customers++;
		}

		// ���� ���� �ֹ��� ���̽�ũ���� �� ����������� ��������� �ʾҴ��� Ȯ���� �� �ְ���?
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
		// ��������� ť�� �մԵ��� ����̳� ���־��°�?
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