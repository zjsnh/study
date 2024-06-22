#pragma once
#include<functional>



namespace smart_ptr
{
	template<class T>
	class shared_ptr
	{
	public:
	shared_ptr(T* ptr = nullptr)
		:_ptr(ptr)
		,_pcount(new int(1))
	{}

	shared_ptr(const shared_ptr<T>& sp)
		:_ptr(sp._ptr)
		,_pcount(sp._pcount)
	{
		++(*_pcount);
	}

	template<class D>
	shared_ptr(T* ptr, D del)
		:_ptr(ptr)
		, _pcount(new int(1))
		, _del(del)
	{}

	void release()
	{
		if (--(*_pcount) == 0)
		{
			_del(_ptr);
			delete _pcount;
		}
	}

	~shared_ptr()
	{
		release();
	}

	shared_ptr<T>& operator=(const shared_ptr<T>& sp)
	{
		if (_ptr != sp._ptr)
		{
			release();

			_ptr = sp._ptr;
			_pcount = sp._pcount;

			++(*_pcount);
		}

		return *this;
	}


	T& operator*()
	{
		return *(_ptr);
	}

	T* operator->()
	{
		return _ptr;
	}

	int use_count() const
	{
		return *_pcount;
	}

	T* get() const
	{
		return _ptr;
	}

	private:
	T* _ptr;
	int* _pcount;
	

	//返回类型和形参
	function<void(T*)> _del = [](T* ptr) {delete ptr; };

	};


	template<class T>
	class weak_ptr
	{
	public:

		weak_ptr()
			:_ptr(nullptr)
		{}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{}

		weak_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			_ptr = sp.get();
			return *this;
		}

		T& operator*()
		{
			return *(_ptr);
		}

		T* operator->()
		{
			return _ptr;
		}


	private:
		T* _ptr;
	};
}