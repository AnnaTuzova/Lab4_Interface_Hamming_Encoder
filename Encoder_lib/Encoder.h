#pragma once 

#include <iostream>
#include <vector>
#include <cstdint>

class IEncode 
{
public:
	~IEncode() {}

	virtual void Encode(std::vector<uint8_t> &input_data, std::vector<uint8_t> &output_data) = 0;
};

class Hamming74Encode : public IEncode
{
private:
	const int kNumOfInputElements = 4;
	const int kNumOfOutputElements = 7;

public:
	~Hamming74Encode() {}

	void Encode(std::vector<uint8_t> &input_data, std::vector<uint8_t> &output_data) override;
	void CheckInputDataOnCorrect(std::vector<uint8_t> &input_data);
	void CheckInputDataOnSize(std::vector<uint8_t> &input_data);
};