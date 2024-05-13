#pragma once

template<class iterator,class Ref,class Ptr>
class ReverseIterator
{
	typedef ReverseIterator<iterator,Ref,Ptr> sef;
public:
	ReverseIterator(iterator it)
		:_it(it)
	{}

	sef& operator++()
	{
		--_it;
		return *this;
	}

	Ref operator*()
	{
		return *_it;
	}

	Ptr operator->()
	{
		return _it.operator->();
	}

	bool operator!=(const sef& it)
	{
		return _it != it._it;
	}

	bool operator==(const sef& it)
	{
		return _it == it.it;
	}

private:
	iterator _it;
};