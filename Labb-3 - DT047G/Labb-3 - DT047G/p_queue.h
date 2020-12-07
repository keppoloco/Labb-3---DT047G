#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
bool less(const T& e1, const T& e2)
{
	return e1 < e2;
}

template<typename T, class cmp = std::less<>>
class p_queue {
public:
	T pop()
	{
		T front_elem;
		if (!T_vec.empty())
		{
			front_elem = T_vec.front();
			T_vec.erase(T_vec.begin());
		}
		return front_elem;
	}

	void push(T elem)
	{
		T_vec.emplace_back(elem);

		if (size() > 1)
			std::sort(T_vec.begin(), T_vec.end(), less<T>);

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
			std::cout << T_vec[i] << ' ';

		std::cout << '\n';
	}
private:
	std::vector<T> T_vec;

};
#endif //! P_QUEUE_H