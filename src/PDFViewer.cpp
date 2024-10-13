#include "PDFViewer.h"
#include "imgui.h"
#include <iostream>

PDFViewer::PDFViewer() : ctx(nullptr), doc(nullptr), pixmap(nullptr), textureID(0), currentPage(0), pageCount(0), width(0), height(0)
{
	ctx = fz_new_context(nullptr, nullptr, FZ_STORE_UNLIMITED);
	if(!ctx)
	{
		std::cerr << "Cannot create MuPDF context." << std::endl;
		std::exit(1);
	}

	fz_try(ctx)
	{
		fz_register_document_handlers(ctx);
	}
	fz_catch(ctx)
	{
		fz_report_error(ctx);
		std::cerr << "Cannot register document handlers" << std::endl;
		fz_drop_context(ctx);
		std::exit(1);
	}
}

PDFViewer::~PDFViewer()
{
	if(pixmap)
	{
		fz_drop_pixmap(ctx, pixmap);
	}

	if(doc)
	{
		fz_drop_document(ctx, doc);
	}

	if(ctx)
	{
		fz_drop_context(ctx);
	}

	if(textureID)
	{
		glDeleteTextures(1, &textureID);
	}
}

void PDFViewer::Init(const char *pdfPath)
{
	fz_try(ctx)
	{
		doc = fz_open_document(ctx, pdfPath);
	}
	fz_catch(ctx)
	{
		fz_report_error(ctx);
		std::cerr << "Cannot open document." << std::endl;
		fz_drop_context(ctx);
		std::exit(1);
	}

	fz_try(ctx)
	{
		pageCount = fz_count_pages(ctx, doc);
	}
	fz_catch(ctx)
	{
		fz_report_error(ctx);
		std::cerr << "Cannot count number of pages." << std::endl;
		fz_drop_document(ctx, doc);
		fz_drop_context(ctx);
		std::exit(1);
	}

	LoadPage(currentPage);
}

void PDFViewer::Update()
{
	ImGui::Begin("PDF Viewer");

	if(ImGui::Button("Previous Page") && currentPage > 0)
	{
		currentPage--;
		LoadPage(currentPage);
	}
	ImGui::SameLine();
	if(ImGui::Button("Next Page") && currentPage < pageCount - 1)
	{
		currentPage++;
		LoadPage(currentPage);
	}
	ImGui::SameLine();
	ImGui::Text("%d/%d", currentPage + 1, pageCount);

	if(textureID != 0)
	{
		ImGui::Image((void *)(intptr_t)textureID, ImVec2(width, height));
	}

	ImGui::End();
}

void PDFViewer::LoadPage(int pageNum)
{
	fz_page *page = fz_load_page(ctx, doc, pageNum);
	fz_rect bound = fz_bound_page(ctx, page);

	pixmap = fz_new_pixmap_from_page_number(ctx, doc, pageNum, fz_scale(1.0, 1.0), fz_device_rgb(ctx), 0);

	width = fz_pixmap_width(ctx, pixmap);
	height = fz_pixmap_height(ctx, pixmap);

	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, fz_pixmap_samples(ctx, pixmap));

	fz_drop_pixmap(ctx, pixmap);
	fz_drop_page(ctx, page);
}