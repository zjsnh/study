#pragma once

//  file: "E:\2023_code\study\notes_stu\c++_note\·´Ïòµü´úÆ÷.md"

template<class Iterator,class Ref,class Ptr>
class ReverseIterator
{
	typedef ReverseIterator<Iterator,Ref,Ptr> sef;
	/*typedef ReverseIterator<Iterator,Ref,Ptr> iterator;
	typedef ReverseIterator<const Iterator,Ref,Ptr> const_iterator;*/

public:
	ReverseIterator(Iterator it)
		:_it(it)
	{}

	ReverseIterator(const sef& it)
		:_it(it._it)
	{}

	sef& operator++()
	{
		--_it;
		return *this;
	}

	sef operator++(int)
	{
		Iterator temp(_it);
		--_it;
		return temp;
	}


	Ref operator*() const
	{
		Iterator temp = _it;
		return *(--temp);
	}

	Ptr operator->() const
	{
		//return &(this->operator*())£»
		return &(operator*());
	}

	bool operator!=(const sef& it)
	{
		return _it != it._it;
	}

	bool operator==(const sef& it)
	{
		return _it == it._it;
	}

private:
	Iterator _it;
};