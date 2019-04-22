#include "Encoder.h"

void Hamming74Encode::Encode(std::vector<uint8_t> &input_data, std::vector<uint8_t> &output_data)
{
	CheckInputDataOnCorrect(input_data);
	CheckInputDataOnSize(input_data);

	int num_of_redundant_symbols = ((input_data.size() / 4) * 3);
	output_data.resize(input_data.size() + num_of_redundant_symbols);
	
	int j = 0; int i = 0;
	for (i; i < output_data.size(); i += kNumOfOutputElements)
	{
		for (j; j < input_data.size(); j++)
		{
			output_data.at(i) = input_data.at(j);
			output_data.at(i + 1) = input_data.at(j + 1);
			output_data.at(i + 2) = input_data.at(j + 2);
			output_data.at(i + 3) = input_data.at(j + 3);
			output_data.at(i + 4) = input_data.at(j) ^ input_data.at(j + 2) ^ input_data.at(j + 3);
			output_data.at(i + 5) = input_data.at(j) ^ input_data.at(j + 1) ^ input_data.at(j + 2);
			output_data.at(i + 6) = input_data.at(j + 1) ^ input_data.at(j + 2) ^ input_data.at(j + 3);
			j += kNumOfInputElements;
			break;
		}
	}
}

void Hamming74Encode::CheckInputDataOnCorrect(std::vector<uint8_t> &input_data)
{
	for (int i = 0; i < input_data.size(); i++)
	{
		if (input_data.at(i) == 0 || input_data.at(i) == 1)
			continue;
		else
			throw "Error: invalid input data.";
	}
}

void Hamming74Encode::CheckInputDataOnSize(std::vector<uint8_t> &input_data)
{
	std::uint8_t zero = 0;

	if (std::fmod(input_data.size(), kNumOfInputElements) != 0)
	{
		std::cout << "Warning: the number of entered symbols is not divisible by 4. Input data will be padded with zeros." << std::endl;

		for (int i = 0; i < std::fmod(input_data.size(), kNumOfInputElements); i++)
		{
			input_data.push_back(zero);
		}
	}
}