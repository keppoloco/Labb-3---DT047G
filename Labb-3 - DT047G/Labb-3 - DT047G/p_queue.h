#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, class cmp = std::less<>>
class p_queue {
public:

	p_queue() = default;

	p_queue(cmp comp) : comporator(comp) { }

	T pop()
	{
		T front_elem = T_vec.front();

		if (!T_vec.empty())
			T_vec.erase(T_vec.begin());

		return front_elem;
	}

	T front()
	{
		return T_vec.front();
	}

	void push(T elem)
	{
		T_vec.emplace_back(elem);

		if (size() > 1)
			std::sort(T_vec.begin(), T_vec.end(), comporator);

	}
	size_t size()
	{
		return T_vec.size();
	}
	bool empty()
	{
		if (T_vec.empty())
			return true;

		return false;
	}
	void print() const
	{
		for (size_t i = 0; i < T_vec.size(); i++)
			std::cout << T_vec[i].name << ' ' << T_vec[i].price << '\n';

		std::cout << '\n';
	}
private:
	std::vector<T> T_vec;
	cmp* comporator;

};
#endif //! P_QUEUE_H