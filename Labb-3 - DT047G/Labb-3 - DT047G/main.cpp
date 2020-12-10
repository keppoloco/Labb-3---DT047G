#include "p_queue.h"
#include <time.h>

struct buyOrder {
	std::string name;
	int price;
};

struct order {
	std::string name;
	// wished sell price
	int price;
};


int main()
{
	srand((unsigned int)time(NULL));
	
	p_queue<buyOrder> buy;
	p_queue<order> sell;

	order a;
	a.name = "Erik Pendel";
	order b;
	b.name = "Jarl Wallenburg";
	order c;
	c.name = "Joakim Von Anka";

	buyOrder d;
	d.name = a.name;

	buyOrder e;
	e.name = b.name;

	buyOrder f;
	f.name = c.name;

	for (int i = 0; i < 7; i++)
	{
		a.price = rand() % 15 + 15;
		sell.push(a);
		d.price = rand() % 15 + 15;
		buy.push(d);
	}

	for (int i = 0; i < 7; i++)
	{
		b.price = rand() % 15 + 15;
		sell.push(b);
		e.price = rand() % 15 + 15;
		buy.push(e);
	}

	for (int i = 0; i < 7; i++)
	{
		c.price = rand() % 15 + 15;
		sell.push(c);
		f.price = rand() % 15 + 15;
		buy.push(f);
	}


	while (!sell.empty() && !buy.empty())
	{
		auto tmp_sell = sell.front();
		auto tmp_buy = buy.front();

		if (tmp_buy.price > tmp_sell.price)
		{
			if (tmp_buy.name == tmp_sell.name)
			{
				sell.pop();
				buy.pop();
				continue;
			}
	
			std::cout << "Purchase made." << '\n';
			std::cout << "Buyer: " << tmp_buy.name << '\n';
			std::cout << "Seller: " << tmp_sell.name << '\n';
			std::cout << "Agreed price: " << tmp_buy.price << '\n';
			std::cout << '\n';
		}
		sell.pop();
		buy.pop();
	}

	return 0;
}