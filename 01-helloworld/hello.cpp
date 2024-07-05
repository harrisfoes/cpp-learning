#include <iostream>
#include <vector>

class Student
{
	std::string m_first = "first";
	std::string m_last = "last";
	int m_id = 0;
	float m_avg = 0;

	public:

	Student() {}

	Student (std::string first, std::string last, int id, float avg)
		: m_first(first)
		, m_last (last)
		, m_id (id)
		, m_avg (avg)
	{

	}

	int getAvg() const 
	{
		return m_avg;
	}

	int getID() const 
	{
		return m_id;
	}

	std::string getFirst() const
	{
		return m_first;
	}

	std::string getLast() const
	{
		return m_last;
	}

	void print() const
	{
		std::cout << m_first << " " << m_last << " " << m_id << " " << m_avg << "\n"; 
	}
};

class Course
{
	std::string m_name = "Course";
	std::vector<Student> m_students;
public:

	Course() {}

	Course(const std::string& name)
		: m_name(name)
	{
	}

	void addStudent(const Student& s)
	{
		m_students.push_back(s);
	}

	const std::vector<Student> getStudents() const 
	{
		return m_students;
	}

	void print() const 
	{
		for (const auto& s : m_students)
		{
			s.print();
		}
	}
}; 


int main(int argc, char * argv[])
{
	Student s1;
	Student s2("Dave", "aa", 1, 3.3);
	Student s3("Jane", "bb", 3, 9.9);

	Course comp4300("COMP 4300");
	comp4300.addStudent(s1);
	comp4300.addStudent(s2);
	comp4300.addStudent(s3);
	comp4300.addStudent(Student("wee","wee", 2, 2.222));

	comp4300.print();


	return 0;
}
