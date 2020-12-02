#include "p_queue.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	int iArr[] = { 1,38,63,10 };
	p_queue<int> pq;
	p_queue<double> pqd;

	double dArr[] = { 3.54,1007.1,25.83,1.2,2 };
	for (int i = 0; i < 5; i++) {
		pqd.push(dArr[i]);
	}

	for (int i = 0; i < 4; i++)
		pq.push(iArr[i]);

	pq.print();
	std::cout << '\n';

	pqd.print();
	/*p_queue<int,bool> pq;

	for (int i = 0; i < 10; i++)
	{
		int random = rand() % 100 + 1;
		pq.push(random);
	}
	pq.print();
	*/
	return 0;
}