#include "p_queue.h"
#include <time.h>

//template<typename T>

struct buyOrder {
	std::string name;
	int price;
};

struct order {
	std::string name;
	// wished sell price
	int price;
};
struct xd {
	bool operator()(const order& e1, const order& e2)
	{
		return e1.price < e2.price;
	}
};
bool less(const order& e1, const order& e2)
{
	return e1.price < e2.price;
}


int main()
{
	srand((unsigned int)time(NULL));
	
	p_queue<order,decltype(less)> buy(less);
	p_queue<order,decltype(less)> sell(less);

	order a;
	a.name = "Erik Pendel";
	order b;
	b.name = "Jarl Wallenburg";
	order c;
	c.name = "Joakim Von Anka";

	for (int i = 0; i < 7; i++)
	{
		a.price = rand() % 15 + 15;
		sell.push(a);
		a.price = rand() % 15 + 15;
		buy.push(a);
	}

	for (int i = 0; i < 7; i++)
	{
		b.price = rand() % 15 + 15;
		sell.push(b);
		b.price = rand() % 15 + 15;
		buy.push(b);
	}

	for (int i = 0; i < 7; i++)
	{
		c.price = rand() % 15 + 15;
		sell.push(c);
		c.price = rand() % 15 + 15;
		buy.push(c);
	}


	while (!sell.empty() && !buy.empty())
	{
		auto tmp_sell = sell.front();
		auto tmp_buy = buy.front();

		if (tmp_buy.price > tmp_sell.price)
		{
			if (tmp_buy.name == tmp_sell.name)
			{
				buy.pop();
				continue;
			}
	
			std::cout << "Purchase made." << '\n';
			std::cout << "Buyer: " << tmp_buy.name << '\n';
			std::cout << "Seller: " << tmp_sell.name << '\n';
			std::cout << "Agreed price: " << tmp_buy.price << '\n';
			std::cout << '\n';

			sell.pop();
			buy.pop();
		}
		else 
			buy.pop();
	}
	return 0;
}