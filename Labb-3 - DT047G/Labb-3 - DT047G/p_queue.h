#pragma once
#ifndef P_QUEUE_H
#define P_QUEUE_H

#include <vector>
#include <algorithm>
template<typename T>
class p_queue {
public:
	T pop();
	void push(T elem);
	size_t size();
	bool empty();
	bool less(const T& e1, const T& e2);

private:
	std::vector<T> T_vec;
};

template<typename T>
inline T p_queue<T>::pop()
{
	T last_elem = T_vec.back();
	T_vec.pop_back();

	return last_elem;
}

template<typename T>
inline void p_queue<T>::push(T elem)
{
	T_vec.emplace_back(elem);

	std::sort(T_vec.begin(), T_vec.end(), less);
}

template<typename T>
inline size_t p_queue<T>::size()
{
	return T_vec.size();
}

template<typename T>
inline bool p_queue<T>::empty()
{
	if (size())
		return true;

	return false;
}
template<typename T>
inline bool p_queue<T>::less(const T& e1, const T& e2)
{
	return e1 < e2;
}
#endif //! P_QUEUE_H