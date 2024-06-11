#pragma once

#include<vector>

template<size_t N>
class bitset
{
public:
	bitset()
	{
		bs.resize((N / 32) + 1, 0);
	}

	void set(size_t x)
	{
		size_t i = x / 32;
		size_t j = x % 32;

		bs[i] |= (1 << j);

	}

	void reset(size_t x)
	{
		size_t i = x / 32;
		size_t j = x % 32;

		bs[i] &= ~(1 << j);
	}

	bool which(size_t x)
	{
		size_t i = x / 32;
		size_t j = x % 32;

		/*if (bs[i] &= (1 << j))
		{
			return true;
		}*/

		return bs[i] & (1 << j);
	}


private:
	vector<int> bs;
};

template<size_t N>
class twobitset
{
public:
	void set(size_t x)
	{
		if (bs1.which(x) == false && bs2.which(x) == false)
		{
			bs2.set(x);
		}
		else if(bs1.which(x) == false && bs2.which(x) == true)
		{
			bs1.set(x);
			bs2.reset(x);
		}
	}

	void Print()
	{
		for (size_t i = 0; i < N; i++)
		{
			if (bs1.which(i) == false && bs2.which(i) == true)
			{
				cout << "1->" << i << endl;
			}
			else if (bs1.which(i) == true && bs2.which(i) == false)
			{
				cout << "2->" << i << endl;
			}
		}
		cout << endl;
	}
private:
	bitset<N> bs1;
	bitset<N> bs2;
};
