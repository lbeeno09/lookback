#include <nlohmann/json.hpp>
#include <string>

class Storage
{
public:
	Storage();
	~Storage();

	void Init();

	void LoadMetadata(const std::string &filename);
	void SaveMetadata(const std::string &filename);
private:
	nlohmann::json metadata_;
};