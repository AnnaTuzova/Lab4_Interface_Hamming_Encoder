#include "../Encoder_lib/Encoder.h"
#include <windows.h>
#include <gtest/gtest.h>

void Comparison(std::vector<uint8_t> &input_data, std::vector<uint8_t> &actual_data);

TEST(TestHamming74Encode, ExceptionTest)
{
	std::vector<uint8_t> input_data{ 0,1,5,0,0 };
	Hamming74Encode hamming_encode;

	ASSERT_THROW(hamming_encode.Encode(input_data), const char*);
}

TEST(TestHamming74Encode, InputDataSizeTest) //Checking the work of the function of adding zeros 
		//in input data, if you input a vector of size that is not divisible by 4
{
	std::vector<uint8_t> actual_input_data{ 1,1,0,0,1 };
	std::vector<uint8_t> expected_input_result{ 1,1,0,0,1,0,0,0 };

	Hamming74Encode hamming_encode;
	hamming_encode.Encode(actual_input_data);
	ASSERT_EQ(actual_input_data, expected_input_result);
}

TEST(TestHamming74Encode, EncodingTest)
{
	std::vector<uint8_t> input_data{ 0,0,0,0,
									 0,0,0,1,
									 0,0,1,0,
									 0,0,1,1,
									 0,1,0,0,
									 0,1,0,1,
									 0,1,1,0,
									 0,1,1,1,
									 1,0,0,0,
									 1,0,0,1,
									 1,0,1,0,
									 1,0,1,1,
									 1,1,0,0,
									 1,1,0,1,
									 1,1,1,0,
									 1,1,1,1 };

	std::vector<uint8_t> expected_output_result{ 0,0,0,0,0,0,0,
											   0,0,0,1,1,0,1,
											   0,0,1,0,1,1,1,
											   0,0,1,1,0,1,0,
											   0,1,0,0,0,1,1,
											   0,1,0,1,1,1,0,
											   0,1,1,0,1,0,0,
											   0,1,1,1,0,0,1,
											   1,0,0,0,1,1,0,
											   1,0,0,1,0,1,1,
 											   1,0,1,0,0,0,1,
											   1,0,1,1,1,0,0,
											   1,1,0,0,1,0,1,
 											   1,1,0,1,0,0,0,
											   1,1,1,0,0,1,0,
											   1,1,1,1,1,1,1 };

	Comparison(input_data, expected_output_result);
}

TEST(TestHamming74Encode, EmptyInputTest)
{
	std::vector<uint8_t> input_data;

	Hamming74Encode hamming_encode;
	std::vector<uint8_t> actual_data = hamming_encode.Encode(input_data);

	ASSERT_TRUE(actual_data.size() == 0);
}

TEST(TestHamming74Encode, SomeInputTest)
{
	std::vector<uint8_t> input_data{0, 1, 1, 1,	0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1};
	std::vector<uint8_t> expected_output_result{0, 1, 1, 1, 0, 0, 1,
												0, 1, 0, 1, 1, 1, 0, 
												0, 0, 0, 0, 0, 0, 0, 
												1, 1, 1, 0, 0, 1, 0, 
												1, 0, 1, 0, 0, 0, 1 };


	Comparison(input_data, expected_output_result);
}

int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

void Comparison(std::vector<uint8_t> &input_data, std::vector<uint8_t> &expected_data)
{
	Hamming74Encode hamming_encode;
	std::vector<uint8_t> actual_data = hamming_encode.Encode(input_data);
	ASSERT_EQ(actual_data, expected_data);
}
