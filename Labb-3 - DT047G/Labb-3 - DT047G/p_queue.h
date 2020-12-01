#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <iostream>
#include <vector>
#include <algorithm>

bool less(const int& e1, const int& e2)
{
	return e1 < e2;
}

template<typename T, class cmp>
class p_queue {
public:
	T pop()
	{
		T last_elem = T_vec.back();
		T_vec.pop_back();

		return last_elem;
	}
	void push(T elem)
	{
		T_vec.emplace_back(elem);

		if (size() > 1)
			std::sort(T_vec.begin(), T_vec.end(), less);
	}
	size_t size()
	{
		return T_vec.size();
	}
	bool empty()
	{
		if (size())
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