#include "p_queue.h"
#include <time.h>

int main()
{
	srand((unsigned int)time(NULL));
	p_queue<std::string> pqs;

	pqs.push("Hej");
	pqs.push("xyz");

	pqs.print();

	std::cout << '\n';

	std::cout << pqs.pop();
	pqs.pop();

	std::cout << pqs.empty() << std::endl;

	std::cout << '\n';

	//pqs.print();

	return 0;
}