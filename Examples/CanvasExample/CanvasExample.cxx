/*
 * Created on Sat May 11 2024
 *
 * Copyright (c) 2024 Zeta Electronics Corporation
 */

#include <CoreAnimation.hxx>
#include <CoreFoundation/CoreFoundation.hxx>
#include <CoreGraphics.hxx>
#include <MLString.hxx>
#include <stdio.h>
#include <string.h>
#include <thread>

int main(int argc, char const* argv[])
{
	constexpr auto cWidth  = 1000;
	constexpr auto cHeight = 666;

	MLCoreGraphicsContext* context = CGRequestContext(0, 0, cWidth, cHeight);

	if (!context)
	{
		printf("Out of memory!\n");
		return -1;
	}

	auto pdfRef	  = r("CanvasExample.pdf");
	auto imageRef = r("../Common/Background.png");

	context->PDF(pdfRef.asConstBytes())->Start()->Image(imageRef.asConstBytes(), cWidth, cHeight, 0, 0);

	context->PageLabel("Cairo")->ThumbnailSize(64, 64);

	context->Color(1.0, 1.0, 1.0, .4)->Move(0.0, 0.0)->Rectangle(1000, 666, 5);
	context->Color(1.0, 1.0, 1.0, 1.0)->Stroke(5.0);

	context->FontFamily("Inter-Black", true)->FontSize(20.0)->Move(50.0, 50.0)->Text(context->toString().asConstBytes(), false);

	context->Present()->Image(imageRef.asConstBytes(), 1000, 666, 0, 0);

	context->PageLabel("アジアの純真")->ThumbnailSize(64, 64);

	context->Color(1.0, 1.0, 1.0, .4)->Move(0.0, 0.0)->Rectangle(1000, 666, 5);
	context->Color(1.0, 1.0, 1.0, 1.0)->Stroke(5.0);

	context->FontFamily("Inter-Black", true)->FontSize(20.0)->Move(50.0, 50.0)->Text("Hello again.", false);

	context->End();

	MLLog("Object: %@ will be destroyed.\n", context);

	CGReleaseContext(context);

	pdfRef.dispose();
	imageRef.dispose();

	return 0;
}