#include <GLFW/glfw3.h>
#include "mupdf/fitz.h"

class PDFViewer
{
public:
	PDFViewer();
	~PDFViewer();

	void Init(const char *pdfPath);
	void Update();
private:
	void LoadPage(int pageNum);

	fz_context *ctx;
	fz_document *doc;
	fz_pixmap *pixmap;
	GLuint textureID;

	int currentPage;
	int pageCount;
	int width, height;
};