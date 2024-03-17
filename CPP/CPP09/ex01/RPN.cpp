#include "RPN.hpp"

RPN::RPN(){};

RPN::RPN(const std::string str) : _str(str) {};

RPN::RPN(const RPN &src) : _str(src.get_str())
{
	this->_stack_process = src.get_process_stack();
}

RPN & RPN::operator=(const RPN &rhs)
{	
	if (this != &rhs)
	{
		this->_str = rhs.get_str();
		this->_stack_process = rhs.get_process_stack();
	}
	return *this;
}

RPN::~RPN(){};

const std::string RPN::get_str() const
{
	return this->_str;
}

std::stack<long> RPN::get_process_stack() const
{
	return this->_stack_process;
};

void RPN::process ()
{
	std::istringstream str_stream(this->_str);

	char c;
	int loop_c = 0;

	while (str_stream >> c)
	{
		switch (c)
		{
			case '+' :
				this->process_add();
				break;
			case '-' :
				this->process_min();
				break;
			case '*' :
				this->process_mul();
				break;
			case '/' :
				this->process_div();
				break;
			default :
				this->process_push(c);
				break;
		}	
		loop_c ++;
	}
};

void RPN::display()
{
	std::stack<long> stack_process_copy = this->_stack_process;

	if (stack_process_copy.size() == 1)
	{
		std::cout << "Result = " << stack_process_copy.top() << std::endl;
	}
	else if (stack_process_copy.size() == 0)
	{
		std::cerr << "Stack is empty." <<std::endl; 
	}
	else
	{
		std::cout << "Stack is not empty : ";
		while (stack_process_copy.empty() == false)
		{
			std::cout << stack_process_copy.top() << " | ";
			stack_process_copy.pop();
		}
		std::cout << std::endl;
	}
}

void RPN::process_add()
{
	long op0;
	long op1;
	long r;
	
	if (this->_stack_process.size() <= 1)
	{
		throw StackSizeError();
	}
	op0 = this->_stack_process.top();
	this->_stack_process.pop();
	op1 = this->_stack_process.top();
	this->_stack_process.pop();
	r = op1 + op0;
	if (r < INT_MIN || r > INT_MAX)
	{
		throw MaxExceeded();
	}
	this->_stack_process.push(r);
}

void RPN::process_min()
{
	long op0;
	long op1;
	long r;
	
	if (this->_stack_process.size() <= 1)
	{
		throw StackSizeError();
	}
	op0 = this->_stack_process.top();
	this->_stack_process.pop();
	op1 = this->_stack_process.top();
	this->_stack_process.pop();
	r = op1 - op0;
	if (r < INT_MIN || r > INT_MAX)
	{
		throw MaxExceeded();
	}
	this->_stack_process.push(r);
}

void RPN::process_mul()
{
	long op0;
	long op1;
	long r;
	
	if (this->_stack_process.size() <= 1)
	{
		throw StackSizeError();
	}
	op0 = this->_stack_process.top();
	this->_stack_process.pop();
	op1 = this->_stack_process.top();
	this->_stack_process.pop();
	r = op1 * op0;
	if (r < INT_MIN || r > INT_MAX)
	{
		throw MaxExceeded();
	}
	this->_stack_process.push(r);
}

void RPN::process_div()
{
	long op0;
	long op1;
	long r;
	
	if (this->_stack_process.size() <= 1)
	{
		throw StackSizeError();
	}
	op0 = this->_stack_process.top();
	this->_stack_process.pop();
	op1 = this->_stack_process.top();
	this->_stack_process.pop();
	if (op0 == 0)
	{
		throw DivisionByZero();
	}
	r = op1 / op0;
	if (r < INT_MIN || r > INT_MAX)
	{
		throw MaxExceeded();
	}
	this->_stack_process.push(r);
}

void RPN::process_push(const char c)
{
	if (std::isdigit(c) == false)
	{
		throw NotADigit();
	}
	this->_stack_process.push(c - '0');
}
