#include "Random.h"

std::mt19937 Random::mt;

const void Random::DefaultRand(){
	std::random_device rd;
	mt.seed(rd());
}

const void Random::SetDefaultRand(int value){
	mt.seed(value);
}

const void Random::DefaultRand(int value){
	Random::SetDefaultRand(value);
}

const int Random::Rand(int value){
	return std::uniform_int_distribution<int>(0, value - 1)(mt);
}

const int Random::Rand(int min, int max){
	return std::uniform_int_distribution<int>(min, max)(mt);
}

const double Random::DRand(double min, double max){
	return std::uniform_real_distribution<double>(min, max)(mt);
}

std::mt19937 Random::GetMt(){
	return mt;
}
