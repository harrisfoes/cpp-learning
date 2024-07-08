#include <iostream>

void pp(int &i)
{
	std::cout << &i << " " << i << "\n";
}

class IntArray
{
	size_t m_size;
	int * m_arr;

public:
	IntArray(size_t size)
		: m_size(size)
		, m_arr (new int[size])
	{
		std::cout << "Array Constructor\n";
	}

	~IntArray()
	{
		delete [] m_arr;
		std::cout << "Array Destructor\n";
	}

	int get(size_t index) const
	{
		return m_arr[index];
	}

	void set(size_t index, int val)
	{
		m_arr[index] = val;
	}

	void print() const 
	{
		for(size_t i=0; i<m_size; i++)
		{
			std::cout << i << " " << m_arr[i] << "\n";
		}
	}
		
};

int main(int argc, char * argv[])
{
	IntArray myArray(10);
	int a = 10;
	int b = 25;

	pp(a);
	pp(b);

	myArray.set(4,7);
	myArray.set(2,134);

	myArray.print();

	return 0;
}
