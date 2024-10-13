#include "AppBase.h"
#include "PDFViewer.h"

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
};