#include "p_queue.h"
#include <time.h>

struct buyOrders {
	int buy_price;
};

struct sellOrders {
	sellOrders(std::string name) { sell_name = name; }
	std::string sell_name;
	int sell_price;
	buyOrders buy;
};

void setPrice(sellOrders& s)
{
	for (int i = 0; i < 21; i++)
	{
		int sell_price = rand() % 30 + 15;
		s.sell_price = sell_price;
		for (int j = 0; j < 21; j++)
		{
			int buy_price = rand() % 30 + 15;
			s.buy.buy_price = buy_price;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	
	sellOrders a("Erik Pendel");
	sellOrders b("Jarl Wallenburg");
	sellOrders c("Joakim von Anka");

	


	return 0;
}