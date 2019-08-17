#include "iostream"
#include "Queue.h"

int main(int argc, char const *argv[])
{
	Queue<int> list;
	list.push(4);
	list.push(5);
	list.push(6);
	std::cout << list.to_string() << "\n";
	std::cout << list.pull() << "\n" << list.size_of() << "\n";
	std::cout << list.to_string();

	return 0;
}