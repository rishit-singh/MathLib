#ifndef TOOLS_H

#include <iostream>

namespace MathLib
{
	class Tools
	{
	public:
		template<typename T>
		static void PrintArray(T* array, int size)	//	Prints the provided array.
		{
			for (int x = 0; x < size; x++)
				std::cout << array[x] << " "; 
			
			std::cout << '\n';
		}	

		template<typename T>
		static void CopyArray(T* destination, T* source, int size)	//	Copies the contents of the provided source array to the destination array.
		{
			for (int x = 0; x < size; x++)
				destination[x] = source[x];
		}
		
		template<typename T>
		static void Swap(T* location, T* location1)
		{
			T temp = *location;
			
			*location = *location1;
			*location1 = temp;	
		}
	};
}

#endif

