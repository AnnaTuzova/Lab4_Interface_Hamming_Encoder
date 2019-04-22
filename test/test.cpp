#include "../Encoder_lib/Encoder.h"
#include <windows.h>
#include <gtest/gtest.h>

void Ñomparison(std::vector<uint8_t> &input_data, std::vector<uint8_t> &expected_data, std::vector<uint8_t> &actual_data);

TEST(TestHamming74Encode, ExceptionTest)
{
	std::vector<uint8_t> input_data{ 0,1,5,0,0 };
	std::vector<uint8_t> expected_output_result;
	Hamming74Encode hamming_encode;

	ASSERT_THROW(hamming_encode.Encode(input_data, expected_output_result), const char*);
}

TEST(TestHamming74Encode, InputDataSizeTest)
{
	std::vector<uint8_t> input_data{ 1,1,0,0,1 };
	std::vector<uint8_t> expected_output_result;
	
	std::vector<uint8_t> actual_input_result{ 1,1,0,0,1,0,0,0 };

	Hamming74Encode hamming_encode;
	hamming_encode.Encode(input_data, expected_output_result);
	ASSERT_EQ(input_data, actual_input_result);
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

	std::vector<uint8_t> expected_output_result;

	std::vector<uint8_t> actual_output_result{ 0,0,0,0,0,0,0,
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

	Ñomparison(input_data, expected_output_result, actual_output_result);
}


int main(int argc, char *argv[])
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

void Ñomparison(std::vector<uint8_t> &input_data, std::vector<uint8_t> &expected_data, std::vector<uint8_t> &actual_data)
{
	Hamming74Encode hamming_encode;
	hamming_encode.Encode(input_data, expected_data);
	ASSERT_EQ(expected_data, actual_data);
}
