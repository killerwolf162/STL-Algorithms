#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <math.h>

bool afterPurple(std::string i) {return (i > "purple"); }

bool isNegative(int i) { return (i < 0) == 1; }

bool IsOdd(int i) { return (i % 2) == 1; }

int main()
{

	std::cout.precision(6);

	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
		// 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
		std::sort(colours.begin(), colours.end());

		auto bound = std::partition(colours.begin(), colours.end(), afterPurple);

		std::cout << "Before purple: ";
		for (auto it = bound; it != colours.end(); ++it)
			std::cout << " " << *it;
		std::cout << std::endl;

		std::cout << "After purple: ";
		for (auto it = colours.begin(); it != bound; ++it)
			std::cout << " " << *it;
		std::cout << std::endl;
		

	}

	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 2) alle elementen UPPERCASE te maken.

		for (auto& colour : colours)
		{
			for (auto& c : colour)
			{
				c = std::toupper(c);
			}
		}

		std::cout << "colours contains:";
		for (std::vector<std::string>::iterator it = colours.begin(); it != colours.end(); ++it)
		{
			auto toupper(it);
			std::cout << ' ' << *it;
		}

		std::cout << '\n';

	}

	{
		std::vector<std::string> colours{ "red", "green", "white", "blue", "orange", "green", "orange", "black", "purple" };
		// 3) alle dubbele te verwijderen

		std::sort(colours.begin(), colours.end());
		auto it = unique(colours.begin(), colours.end());
		colours.erase(it, colours.end());

		std::cout << "colours contains: ";
		for (auto& colour : colours)
		{
			std::cout << colour << " ";
		}
		std::cout << std::endl;

	}

	// gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 1) alle negatieve elementen te verwijderen
		
		std::sort(numbers.begin(), numbers.end());
		auto it = std::remove_if(numbers.begin(), numbers.end(), isNegative);
		numbers.erase(it, numbers.end());

		std::cout << "numbers contains: ";
		for (auto& number : numbers)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;

	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 2) voor alle elementen te bepalen of ze even of oneven zijn
		std::vector<double> oddVector;
		std::vector<double> evenVector;

		std::sort(numbers.begin(), numbers.end());

		for (auto& number : numbers)
		{
			if (fmod(number, 2) == 0)
			{
				evenVector.push_back(number);
			}
			else 
			{
				oddVector.push_back(number);
			}
		}

		std::cout << "Even numbers are: ";
		for (auto& number : evenVector)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;

		std::cout << "odd numbers are: ";
		for (auto& number : oddVector)
		{
			std::cout << number << " ";
		}
		std::cout << std::endl;	
	}

	{
		std::vector<double> numbers{ 10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635 };
		// 3) de som, het gemiddelde, en het product van alle getallen te berekenen

		auto sum = std::accumulate(numbers.begin(), numbers.end(), 0);
		std::cout << "sum of all numbers: " << sum << std::endl;

		auto average = (std::accumulate(numbers.begin(), numbers.end(), 0) / numbers.size());
		std::cout << "average of all numbers: " << average << std::endl;

		auto product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<double>());
		std::cout << "product of all numbers: " << product << std::endl;
	}

	return 0;
}



