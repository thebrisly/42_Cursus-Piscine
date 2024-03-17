#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <list>
#include <deque>

class PmergeMe
{
	public :
		PmergeMe();
		~PmergeMe();
		PmergeMe(std::list<unsigned int>list_to_sort, std::deque<unsigned int>deq_to_sort);
		PmergeMe & operator=(const PmergeMe &rhs);

		PmergeMe(const PmergeMe &rhs);


		std::list<unsigned int> get_list_to_sort() const;
		std::list<unsigned int> get_list_sorted_pairs() const;
		std::list<unsigned int> get_S() const;
		std::list<unsigned int> get_pend() const;

		std::deque<unsigned int> get_deque_to_sort() const;
		std::deque<unsigned int> get_deque_sorted_pairs() const;
		std::deque<unsigned int> get_S_d() const;
		std::deque<unsigned int> get_pend_d() const;

		void diplayList(std::list<unsigned int> list_to_display);
		void diplayDeq(std::deque<unsigned int> list_to_display);

		bool check_sort(std::list<unsigned int>list_to_check);
		bool check_sort_deq(std::deque<unsigned int>list_to_check);
		
		void sort_all();

	private :

		std::list<unsigned int> _list_to_sort;
		std::list<unsigned int> _list_sorted_pairs;
		std::list<unsigned int> _S;
		std::list<unsigned int> _pend;
		
		std::deque<unsigned int> _deq_to_sort;
		std::deque<unsigned int> _deq_sorted_pairs;
		std::deque<unsigned int> _S_d;
		std::deque<unsigned int> _pend_d;

		void sort();
		void sort_deq();

		void sort_pairs();
		void sort_pairs_deq();

		void insertion_sort_pairs ();
		void insertion_sort_pairs_deq ();

		void binary_insertion_sort();
		void binary_insertion_sort_deq();

		void switch_it(std::list<unsigned int>::iterator & it, std::list<unsigned int>::iterator & it_2);
		void switch_it_deq(std::deque<unsigned int>::iterator & it, std::deque<unsigned int>::iterator & it_2);
		
		std::list<unsigned int>::iterator get_element_in_list(unsigned long ind, std::list<unsigned int> & list);
		std::deque<unsigned int>::iterator get_element_in_deq(unsigned long ind, std::deque<unsigned int> & list);
		
		std::list<unsigned int> jacobsthal_generator ();
		std::deque<unsigned int> jacobsthal_generator_deq ();
		
		std::list<unsigned int> index_order_generator ();
		std::deque<unsigned int> index_order_generator_deq ();
		
		unsigned long binary_sort(unsigned int n_to_insert);
		unsigned long binary_sort_deq(unsigned int n_to_insert);
};


#endif
