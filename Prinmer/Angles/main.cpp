#include <iostream>
int main()
{
	int Angle{};
	int sum = 0;
	while(std::cin>>Angle) // this reads up to \n and if u pass in char then it actually does detect that;
	{ // ^^ reads until error;
		std::cout<<"Supplementary"<<180-Angle<<std::endl;
        std::cout<<"Complementary"<<90-Angle<<std::endl;
	}

} // what if i wanted to make my own "parser" well id need to add an operator overloader
// and i defenitely need to use chars first check for command - > then check for param;