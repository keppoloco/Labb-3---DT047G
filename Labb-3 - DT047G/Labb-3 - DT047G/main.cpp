#include "p_queue.h"
int main()
{
	p_queue<int,bool> pq;

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100 + 1;
		pq.push(random);
	}
	pq.print();

	return 0;
}