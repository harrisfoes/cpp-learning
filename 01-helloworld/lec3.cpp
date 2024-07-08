#include <iostream>

void pp(int &i)
{
	std::cout << &i << " " << i << "\n";
}

template<typename T>
class DynamicArray 
{
	size_t m_size;
	T * m_arr;

public:
	DynamicArray(size_t size)
		: m_size(size)
		, m_arr (new T[size])
	{
		std::cout << "Array Constructor\n";
	}

	~DynamicArray()
	{
		delete [] m_arr;
		std::cout << "Array Destructor\n";
	}

	T get(size_t index) const
	{
		return m_arr[index];
	}

	void set(size_t index, T val)
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

	T & operator [] (size_t index)
	{
		return m_arr[index];
	}
		
};

int main(int argc, char * argv[])
{
	DynamicArray<float> myArray(10);
	int a = 10;
	int b = 25;

	pp(a);
	pp(b);

	myArray.set(4,7);
	myArray.set(2,134);
	myArray[7] = 3.1323;
	myArray[6] = 121212;

	myArray.print();

	return 0;
}
