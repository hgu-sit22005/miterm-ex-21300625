#include <iostream>
#include <random>
#include <ctime>

char* generate_3_digit()
{	
	srand(time(0));
	char* res = new char[10];
	for (int i=0;i<10;i++)
		res[i]=i+'0';

	for (int i=0;i<3;i++)
	{
		char buf;
		int index =rand()%(10-i);
		buf=res[index];
		res[0]=res[index];
		res[index]=buf;
	}

	return res;
}

int main()
{
	// Game initalization
	char guess[3];
	int trials = 0;

	char* answer = generate_3_digit();
		
	int strike = 0, ball = 0, out = 0;
	while(strike != 3)
	{
		trials++;

		strike = 0;
		ball = 0;
		out = 0;

		std::cout << "Guess three number: (ex. 1 2 3)" << std::endl;
		std::cin >> guess[0] >> guess[1] >> guess[2];
		for (int i=0;i<3;i++)
			for (int j=0;j<3;j++)
				if (answer[i]==guess[j])
					if (i==j)
						strike++;
					else 
						ball++;
				else
					out++;	
							
		std::cout << "S:" << strike << " B:" << ball << " O:"<< out << std::endl;
	}
	
	std::cout << "You have found the right number with " << trials << " trials" << std::endl;

	delete[] answer;
	return 0;
}