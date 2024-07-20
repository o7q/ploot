#pragma once

#include <iostream>
#include <random>

class Random
{
public:
	static std::random_device rd;
	static std::mt19937 gen;

	static void init();
	static void reseed();
	static int genInt(int, int);
	static float genFloat(float, float);
};