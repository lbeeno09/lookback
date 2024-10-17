#include "Storage.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>

Storage::Storage() : metadata_({})
{

}

Storage::~Storage()
{

}

void Storage::Init()
{
	LoadMetadata("metadata.json");
}

void Storage::LoadMetadata(const std::string &filename)
{
	std::ifstream file(filename);
	if(file.is_open())
	{
		file >> metadata_;
		file.close();
	}
	else
	{
		std::cerr << "Failed to open metadata file." << std::endl;
	}
}

void Storage::SaveMetadata(const std::string &filename)
{
	std::ofstream file(filename);
	if(file.is_open())
	{
		file << metadata_.dump(4);
		file.close();
	}
	else
	{
		std::cerr << "Failed to save metadata to file" << std::endl;
	}
}