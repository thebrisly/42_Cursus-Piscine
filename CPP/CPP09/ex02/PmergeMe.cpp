#include "PmergeMe.hpp"

class DisplayList
{
	public :
		void operator()(unsigned int a)
		{
			std::cout << a << " ";
		}
};

class SumList
{
	public :
		SumList() : _sum_list(0){};
		unsigned long long get_sum_list()
		{
			return this->_sum_list;
		}

		void operator()(unsigned int a)
		{
			this->_sum_list += a;
		}

	private :
		unsigned long long _sum_list;
};

PmergeMe::PmergeMe (){};
PmergeMe::~PmergeMe (){};

PmergeMe::PmergeMe(std::list<unsigned int>list_to_sort, std::deque<unsigned int>deq_to_sort) : _list_to_sort(list_to_sort), _deq_to_sort(deq_to_sort){};

PmergeMe & PmergeMe::operator=(const PmergeMe &rhs)
{
	if (this != &rhs)
	{
		this->_list_to_sort = rhs.get_list_to_sort();
		this->_list_sorted_pairs = rhs.get_list_sorted_pairs();
		this->_S = rhs.get_S();
		this->_pend = rhs.get_pend();

		this->_deq_to_sort = rhs.get_deque_to_sort();
		this->_deq_sorted_pairs = rhs.get_deque_sorted_pairs();
		this->_S_d = rhs.get_S_d();
		this->_pend_d = rhs.get_pend_d();

	}
	return *this;
}

PmergeMe::PmergeMe(const PmergeMe &rhs)
{
	*this = rhs;
}

std::list<unsigned int> PmergeMe::get_list_to_sort () const
{
	return this->_list_to_sort;
}

std::list<unsigned int> PmergeMe::get_list_sorted_pairs() const
{
	return this->_list_sorted_pairs;
}

std::list<unsigned int> PmergeMe::get_S() const
{
	return this->_S;
}

std::list<unsigned int> PmergeMe::get_pend() const
{
	return this->_pend;
}

std::deque<unsigned int> PmergeMe::get_deque_to_sort() const
{
	return this->_deq_to_sort;
}

std::deque<unsigned int> PmergeMe::get_deque_sorted_pairs() const
{
	return this->_deq_sorted_pairs;
}

std::deque<unsigned int> PmergeMe::get_S_d() const
{
	return this->_S_d;
}

std::deque<unsigned int> PmergeMe::get_pend_d() const
{
	return this->_pend_d;
}

void PmergeMe::diplayList(std::list<unsigned int> list_to_display)
{
	for_each(list_to_display.begin(), list_to_display.end(), DisplayList());
}

void PmergeMe::diplayDeq(std::deque<unsigned int> list_to_display)
{
	for_each(list_to_display.begin(), list_to_display.end(), DisplayList());
}

bool PmergeMe::check_sort(std::list<unsigned int>list_to_check)
{
	std::list<unsigned int>::iterator start = list_to_check.begin();
	std::list<unsigned int>::iterator it_mover = list_to_check.begin();
	std::list<unsigned int>::iterator end = list_to_check.end();

	++it_mover;
	for (; it_mover != end; ++it_mover)
	{
		if (*start > *it_mover)
		{	
			return false;
		}
		++start;
	}

	return true;
}

bool PmergeMe::check_sort_deq(std::deque<unsigned int>list_to_check)
{
	std::deque<unsigned int>::iterator start = list_to_check.begin();
	std::deque<unsigned int>::iterator it_mover = list_to_check.begin();
	std::deque<unsigned int>::iterator end = list_to_check.end();

	++it_mover;
	for (; it_mover != end; ++it_mover)
	{
		if (*start > *it_mover)
		{	
			return false;
		}
		++start;
	}
	return true;
}

void PmergeMe::sort_all()
{

	if (this->_deq_to_sort.size() == 0 || this->_list_to_sort.size() == 0)
	{
		return;
	}

    std::chrono::time_point<std::chrono::high_resolution_clock> start_time = std::chrono::high_resolution_clock::now();
	this->sort();
    std::chrono::time_point<std::chrono::high_resolution_clock> end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds_list = end_time - start_time;

	start_time = std::chrono::high_resolution_clock::now();
	this->sort_deq();
	end_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double> elapsed_seconds_deq = end_time - start_time;

	unsigned long max_display = 5;
	std::cout << "Before: ";
	for (std::list<unsigned int>::iterator it = this->_list_to_sort.begin(); it!= this->_list_to_sort.end() && max_display > 0; ++it)
	{
		std::cout << *it << " ";
		max_display--;
	}

	if (this->_list_to_sort.size() > 5)
	{
		std::cout << "[...]";
	}

	std::cout << std::endl;

	max_display = 5;
	std::cout << "After:  ";
	for (std::list<unsigned int>::iterator it = this->_S.begin(); it!= this->_S.end() && max_display > 0; ++it)
	{
		std::cout << *it << " ";
		max_display--;
	}

	if (this->_list_to_sort.size() > 5)
	{
		std::cout << "[...]";
	}

	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_list_to_sort.size() << " elements with std::list : " << elapsed_seconds_list.count() * 100000 << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deq_to_sort.size() << " elements with std::deque : " << elapsed_seconds_deq.count() * 100000 << " us" << std::endl;
}

void PmergeMe::sort()
{
	this->sort_pairs();
	this->insertion_sort_pairs();
	this->binary_insertion_sort();
}

void PmergeMe::sort_deq()
{
	this->sort_pairs_deq();
	this->insertion_sort_pairs_deq();
	this->binary_insertion_sort_deq();
}

void PmergeMe::sort_pairs()
{
	this->_list_sorted_pairs = this->_list_to_sort;

	std::list<unsigned int>::iterator it = this->_list_sorted_pairs.begin();
	std::list<unsigned int>::iterator it_2 = this->_list_sorted_pairs.begin();

	unsigned long loop_count = this->_list_sorted_pairs.size() / 2;
	it_2++;

	while (loop_count > 0)
	{	
		if (*it_2 < *it)
		{	
			this->switch_it(it, it_2);
		}
		++it;
		++it;
		++it_2;
		++it_2;
		loop_count--;
	}
}

void PmergeMe::sort_pairs_deq()
{
	this->_deq_sorted_pairs = this->_deq_to_sort;

	std::deque<unsigned int>::iterator it = this->_deq_sorted_pairs.begin();
	std::deque<unsigned int>::iterator it_2 = this->_deq_sorted_pairs.begin();

	unsigned long loop_count = this->_deq_sorted_pairs.size() / 2;
	it_2++;

	while (loop_count > 0)
	{	
		if (*it_2 < *it)
		{	
			this->switch_it_deq(it, it_2);
		}
		++it;
		++it;
		++it_2;
		++it_2;
		loop_count--;
	}
}

void PmergeMe::insertion_sort_pairs ()
{
	std::list<unsigned int>::iterator it = this->_list_sorted_pairs.begin();
	
	for (unsigned long i = 0; i < this->_list_sorted_pairs.size(); ++i)
	{
		if (i%2 == 1)
		{
			this->_S.push_back(*it);
		}
		else
		{
			this->_pend.push_back(*it);
		}
		++it;
	}

	for (unsigned long index = 1; index < this->_S.size(); ++index)
	{
		std::list<unsigned int>::iterator start = this->_S.begin();
		std::list<unsigned int>::iterator it_current = this->get_element_in_list(index, this->_S);
		std::list<unsigned int>::iterator it_mover = this->get_element_in_list(index - 1, this->_S);

		std::list<unsigned int>::iterator it_current_p = this->get_element_in_list(index, this->_pend);
		std::list<unsigned int>::iterator it_mover_p = this->get_element_in_list(index - 1, this->_pend);

		while (*it_current < *it_mover && it_mover != start)
		{
			--it_mover_p;
			--it_mover;
		}

		if (index == 1 && *it_current < *it_mover )
		{
			this->switch_it(it_mover_p, it_current_p);
			this->switch_it(it_mover, it_current);
		}
		else if (it_mover == start && *it_current < *start)
		{
			this->_pend.push_front(*it_current_p);
			this->_pend.erase(it_current_p);
			this->_S.push_front(*it_current);
			this->_S.erase(it_current);
		}
		else
		{
			this->_pend.insert(++it_mover_p, *it_current_p);
			this->_pend.erase(it_current_p);
			this->_S.insert(++it_mover, *it_current);
			this->_S.erase(it_current);
		}
	}
}

void PmergeMe::insertion_sort_pairs_deq ()
{
	std::deque<unsigned int>::iterator it = this->_deq_sorted_pairs.begin();
	
	for (unsigned long i = 0; i < this->_deq_sorted_pairs.size(); ++i)
	{
		if (i%2 == 1)
		{
			this->_S_d.push_back(*it);
		}
		else
		{
			this->_pend_d.push_back(*it);
		}
		++it;
	}

	for(unsigned long i = 1; i < this->_S_d.size(); ++i) 
	{
		unsigned int key = this->_S_d[i];
		unsigned int key_p = this->_pend_d[i];
		int j = i - 1;

		while(j >= 0 && this->_S_d[j] > key) 
		{
			this->_S_d[j + 1] = this->_S_d[j];
			this->_pend_d[j + 1] = this->_pend_d[j];
			j--;

		}
		this->_S_d[j + 1] = key;
		this->_pend_d[j + 1] = key_p;
	}
}

void PmergeMe::binary_insertion_sort()
{

	std::list<unsigned int> index_order = this->index_order_generator();

	unsigned int index = 0;

	while (index_order.size() > 0)
	{
		index = index_order.front();

		unsigned int value_to_insert = *(this->get_element_in_list(index, this->_pend));

		unsigned long ind_to_insert = this->binary_sort(value_to_insert);

		std::list<unsigned int>::iterator it_insertion_S = this->get_element_in_list(ind_to_insert, this->_S);

		this->_S.insert(it_insertion_S, value_to_insert);

		index_order.pop_front();
	}
}

void PmergeMe::binary_insertion_sort_deq()
{
	std::deque<unsigned int> index_order = this->index_order_generator_deq();

	unsigned int index = 0;

	while (index_order.size() > 0)
	{
		index = index_order.front();

		unsigned int value_to_insert = *(this->get_element_in_deq(index, this->_pend_d));

		unsigned long ind_to_insert = this->binary_sort_deq(value_to_insert);

		std::deque<unsigned int>::iterator it_insertion_S_d = this->get_element_in_deq(ind_to_insert, this->_S_d);

		this->_S_d.insert(it_insertion_S_d, value_to_insert);

		index_order.pop_front();

	}
}

void swap_in_list(std::deque<unsigned int>::iterator & it, std::deque<unsigned int>::iterator & it_2)
{
	unsigned int temp;

	temp = *it;
	*it = *it_2;
	*it_2 = temp;
};

void PmergeMe::switch_it(std::list<unsigned int>::iterator & it, std::list<unsigned int>::iterator & it_2)
{
	unsigned int temp;

	temp = *it;
	*it = *it_2;
	*it_2 = temp;
};

void PmergeMe::switch_it_deq(std::deque<unsigned int>::iterator & it, std::deque<unsigned int>::iterator & it_2)
{
	unsigned int temp;

	temp = *it;
	*it = *it_2;
	*it_2 = temp;
};

std::list<unsigned int>::iterator PmergeMe::get_element_in_list(unsigned long ind, std::list<unsigned int> & list)
{
	std::list<unsigned int>::iterator it;
	it = list.begin();

	while (ind > 0)
	{
		it++;
		ind--;
	}
	return it;
}

std::deque<unsigned int>::iterator PmergeMe::get_element_in_deq(unsigned long ind, std::deque<unsigned int> & list)
{
	std::deque<unsigned int>::iterator it;
	it = list.begin();

	while (ind > 0)
	{
		it++;
		ind--;
	}
	return it;
}

std::list<unsigned int> PmergeMe::jacobsthal_generator ()
{
	std::list<unsigned int> jacobsthal;

	jacobsthal.clear();
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	SumList sum = for_each(jacobsthal.begin(), jacobsthal.end(), SumList());

	unsigned long i = 2;
	while ((sum.get_sum_list()*2) <= this->_list_to_sort.size())
	{
		std::list<unsigned int>::iterator Jn_2 = this->get_element_in_list(i - 1, jacobsthal); 
		std::list<unsigned int>::iterator Jn_1 = this->get_element_in_list(i, jacobsthal); 

		unsigned int r = *Jn_1 + (2 * (*Jn_2));

		jacobsthal.push_back(r);

		sum = for_each(jacobsthal.begin(), jacobsthal.end(), SumList());

		++i;
	}

	return jacobsthal;
}

std::deque<unsigned int> PmergeMe::jacobsthal_generator_deq ()
{
	std::deque<unsigned int> jacobsthal;

	jacobsthal.clear();
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	jacobsthal.push_back(1);

	SumList sum = for_each(jacobsthal.begin(), jacobsthal.end(), SumList());

	unsigned long i = 2;
	while ((sum.get_sum_list()*2) <= this->_deq_to_sort.size())
	{
		std::deque<unsigned int>::iterator Jn_2 = this->get_element_in_deq(i - 1, jacobsthal); 
		std::deque<unsigned int>::iterator Jn_1 = this->get_element_in_deq(i, jacobsthal); 

		unsigned int r = *Jn_1 + (2 * (*Jn_2));

		jacobsthal.push_back(r);

		sum = for_each(jacobsthal.begin(), jacobsthal.end(), SumList());

		++i;
	}

	for (std::deque<unsigned int>::iterator it = jacobsthal.begin(); it != jacobsthal.end(); ++it)
	{
		(*it) *= 2;
	}
	
	return jacobsthal;
}

std::list<unsigned int> PmergeMe::index_order_generator ()
{

	std::list<unsigned int> jacobsthal = this->jacobsthal_generator();

	std::list<unsigned int> index_order;

	const unsigned long pend_size = this->_pend.size();

	if (pend_size == 1)
	{
		index_order.push_back(0);
		return index_order;
	}

	if (pend_size == 2)
	{
		index_order.push_back(0);
		index_order.push_back(1);
		return index_order;
	}

	if (pend_size == 3)
	{

		index_order.push_back(0);
		index_order.push_back(1);
		index_order.push_back(2);
		return index_order;
	}

	index_order.push_back(0);
	index_order.push_back(2);
	index_order.push_back(1);

	unsigned long index_lowest = *(max_element(index_order.begin(), index_order.end()));
	unsigned long index_highest = *(max_element(index_order.begin(), index_order.end())) + *(this->get_element_in_list(1, jacobsthal));
	
	int count = 1;
	while (index_order.size() != pend_size)
	{

		index_lowest = *(max_element(index_order.begin(), index_order.end()));
		index_highest = *(max_element(index_order.begin(), index_order.end())) + *(this->get_element_in_list(count, jacobsthal));
		
		if (index_highest >= pend_size)
		{
			index_highest = pend_size - 1;
		}
		while (index_lowest < index_highest)
		{
			index_order.push_back(index_highest);
			index_highest--;
		}
		count++;
	}

	if (index_order.size() != pend_size)
	{
		std::cerr << "Error : index_order.size() != pend_size" << std::endl;
	}

	return index_order;
}

std::deque<unsigned int> PmergeMe::index_order_generator_deq ()
{
	std::deque<unsigned int> jacobsthal = this->jacobsthal_generator_deq();

	std::deque<unsigned int> index_order;

	const unsigned long pend_size = this->_pend_d.size();

	if (pend_size == 1)
	{
		index_order.push_back(0);
		return index_order;
	}

	if (pend_size == 2)
	{
		index_order.push_back(0);
		index_order.push_back(1);
		return index_order;
	}

	if (pend_size == 3)
	{

		index_order.push_back(0);
		index_order.push_back(1);
		index_order.push_back(2);
		return index_order;
	}

	index_order.push_back(0);
	index_order.push_back(2);
	index_order.push_back(1);

	unsigned long index_lowest = *(max_element(index_order.begin(), index_order.end()));
	unsigned long index_highest = *(max_element(index_order.begin(), index_order.end())) + *(this->get_element_in_deq(1, jacobsthal));
	
	int count = 1;
	while (index_order.size() != pend_size)
	{

		index_lowest = *(max_element(index_order.begin(), index_order.end()));
		index_highest = *(max_element(index_order.begin(), index_order.end())) + *(this->get_element_in_deq(count, jacobsthal));
		
		if (index_highest >= pend_size)
		{
			index_highest = pend_size - 1;
		}
		while (index_lowest < index_highest)
		{
			index_order.push_back(index_highest);
			index_highest--;
		}
		count++;
	}

	// if (index_order.size() != pend_size)
	// {
	// 	std::cerr << "Error : index_order.size() != pend_size" << std::endl;
	// }

	return index_order;
}

unsigned long PmergeMe::binary_sort(unsigned int n_to_insert)
{
	unsigned long left = 0;
	unsigned long right = this->_S.size();
	unsigned long mid = 0;

	while (left < right)
	{
		mid = left + (right - left) / 2;

		if (*(this->get_element_in_list(mid, this->_S)) < n_to_insert)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}

	return left;
}

unsigned long PmergeMe::binary_sort_deq(unsigned int n_to_insert)
{
	unsigned long left = 0;
	unsigned long right = this->_S_d.size();
	unsigned long mid = 0;

	while (left < right)
	{
		mid = left + (right - left) / 2;

		if (*(this->get_element_in_deq(mid, this->_S_d)) < n_to_insert)
		{
			left = mid + 1;
		}
		else
		{
			right = mid;
		}
	}
	return left;
}











