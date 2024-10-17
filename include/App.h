#include "AppBase.h"
#include "PDFViewer.h"
#include "Storage.h"

class App : public AppBase
{
public:
	App();
	~App() override;

	void Init() override;
	void Update() override;
private:
	void ShowMenubar();

	bool showDemoWindow_;
	PDFViewer PDFViewer_;
	Storage Storage_;
};