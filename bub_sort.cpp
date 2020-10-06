#include <iostream>
#include <cstdlib>
#include <graphics.h>

using namespace std;




void print_list(int *list, int size)
{

	//std::cout << size << " size " << std::endl;
	for (int i=0; i<size; i++)
	{
		std::cout << list[i] << ", ";
	}

	std::cout << "\n";

}


void bub_sort(int *list, int size)
{

	bool sorted_flag = true;


	while (sorted_flag == true)
	{
		sorted_flag = false;
		for (int i=0; i<size-1; i++)//loop trough array
		{
			
			if (list[i] > list[i+1])
			{
				auto temp_u = list[i+1];
				auto temp_v = list[i];
				list[i] = temp_u;
				list[i+1] = temp_v;
				sorted_flag = true;

			}


		}
		//print_list(list, size);

		if (sorted_flag == false)
		{
			break;
		}
	}
	
		
}





int main()
{

	//int sz = 10;
	int sz;
	std::cout << "give the array size: ";
	std::cin >> sz;


	int size_rand;
	std::cout << "give the max value of the random numbers: ";
	std::cin >> size_rand;
	
	int random_list[sz];	
	for (int i=0; i<sz; i++)
	{
		random_list[i] = (rand() % size_rand);
		std::cout << random_list[i] << std::endl;
	}
	
	print_list(random_list, sz);
	

	bub_sort(random_list, sz);


	std::cout << "Done: " << std::endl;
	print_list(random_list,sz);
	

}
