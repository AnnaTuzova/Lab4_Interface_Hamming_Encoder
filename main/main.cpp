#include "../Encoder_lib/Encoder.h"

void DisplayData(std::vector<uint8_t> input_data);

int main()
{
	std::vector<uint8_t> input_data{1,0,0,0,0};
	std::vector<uint8_t> output_data;

	try
	{
		Hamming74Encode hamming_encode;
		hamming_encode.Encode(input_data, output_data);
	}
	catch (char *exception)
	{
		std::cout << exception << std::endl;
		return -1;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
		return -1;
	}

	
	std::cout << "Input data: " << std::endl;
	DisplayData(input_data);

	std::cout << "Encoding data: " << std::endl;
	DisplayData(output_data);

    return 0;
}

void DisplayData(std::vector<uint8_t> input_data)
{
	for (int i = 0; i < input_data.size(); i++)
	{
		std::cout << unsigned(input_data.at(i)) << " ";
	}
	std::cout << std::endl;
}