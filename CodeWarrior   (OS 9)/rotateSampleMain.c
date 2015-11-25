/*	File:		rotateSampleMain.c	Contains:		Written by: RT and BS		Copyright:	Copyright � 1992-1999 by Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.	Change History (most recent first):				08/2000		JM				Carbonized, non-Carbon code is commented out											for demonstration purposes.				7/14/1999	KG				Updated for Metrowerks Codewarror Pro 2.1				*/#include "CarbonPrefix.h"#include <Fonts.h>#include <Events.h>#include <Windows.h>#include <Menus.h>#include <TextEdit.h>#include <Dialogs.h>#include "RotateString.h"#define	NIL_POINTER			0L#define REMOVE_ALL_EVENTS	0#define VISIBLE				true#define	MOVE_TO_FRONT		(Ptr)-1#define HAS_GOAWAY			truevoid	main(){	WindowPtr	window1,window2;	BitMap		destMap;	Rect		windowRect;	RgnHandle	rgnHandle = NewRgn();		/*InitGraf( &qd.thePort);	InitFonts();	InitWindows();	InitMenus();	TEInit();	InitDialogs( NIL_POINTER);*/	InitCursor();	FlushEvents( everyEvent, REMOVE_ALL_EVENTS);		SetRect( &windowRect, 100, 100, 200, 200);		window1 = NewWindow( NIL_POINTER, &windowRect, "\pCounter CW", VISIBLE,				noGrowDocProc,(WindowPtr)-1, HAS_GOAWAY, NIL_POINTER);	//SetPort(window1);	SetPortWindowPort(window1);	TextFont(4);	//TextFace(bold+italic);	TextSize(96);		RotateString( "\pRotatey", &destMap, counterClockWise);	SizeWindow(window1,destMap.bounds.right,destMap.bounds.bottom,false);	/*CopyBits( &destMap, &window1->portBits, &destMap.bounds,			 &destMap.bounds, srcCopy, NIL_POINTER);*/	CopyBits( &destMap, GetPortBitMapForCopyBits(GetWindowPort(window1)), &destMap.bounds,			 &destMap.bounds, srcCopy, NIL_POINTER);	QDFlushPortBuffer(GetWindowPort(window1), GetPortVisibleRegion(GetWindowPort(window1), rgnHandle));		OffsetRect(&windowRect,(windowRect.right - windowRect.left ) + 40,0);	window2 = NewWindow( NIL_POINTER, &windowRect, "\pClock Wise", VISIBLE,				noGrowDocProc,(WindowPtr) MOVE_TO_FRONT, HAS_GOAWAY, NIL_POINTER);	//SetPort(window2);	SetPortWindowPort(window2);	TextFont(4);	//TextFace(bold+italic);	TextSize(96);		RotateString( "\pRotate", &destMap, clockWise);	SizeWindow(window2,destMap.bounds.right,destMap.bounds.bottom,false);	/*CopyBits( &destMap, &window2->portBits, &destMap.bounds,			 &destMap.bounds, srcCopy, NIL_POINTER);*/	CopyBits( &destMap, GetPortBitMapForCopyBits(GetWindowPort(window2)), &destMap.bounds,			 &destMap.bounds, srcCopy, NIL_POINTER);	QDFlushPortBuffer(GetWindowPort(window2), GetPortVisibleRegion(GetWindowPort(window2), rgnHandle));	while( !Button());		DisposeRgn(rgnHandle);}