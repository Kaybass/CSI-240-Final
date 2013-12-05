#include <iostream>
#include "Item.h"
#include <string>
#include <cstdlib>


using namespace std;

// Item class ///////////////////////////////////////////

Item::Item(HANDLE handle, int x, int y, char displayChar)
:mHandle(handle)
,mX(x)
,mY(y)
,mChar(displayChar)
{
}

Item::Item()
{
	mHandle = globalhandle;
	mX = 0;
	mY = 0;
	mChar = '@';
}

void Item::draw() const
{
	COORD temp = {mX,mY};
	SetConsoleCursorPosition( mHandle, temp );
	cout << mChar;
}

// ColorItem class ///////////////////////////////////////////

ColorItem::ColorItem(HANDLE handle, int x, int y, char displayChar, int color)
:Item( handle, x, y, displayChar )
,mColor(color)
{
}

ColorItem::ColorItem()
{
	mHandle = globalhandle;
	mX = 0;
	mY = 0;
	mChar = '@';
	mColor = FOREGROUND_RED;
}

void ColorItem::update()
{
}

void ColorItem::draw() const
{
	//get current screen info
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo( mHandle, &info );

	SetConsoleTextAttribute( mHandle, mColor );

	Item::draw();

	//set back to old attributes
	SetConsoleTextAttribute( mHandle, info.wAttributes );
}

Food::Food(HANDLE handle)
{
	mHandle = handle;
	mX = 2 + rand() % 76;
	mY = 2 + rand() % 20;
	mChar = '@';
	mColor = FOREGROUND_RED;
}

void Food::update()
{
}

Body::Body(HANDLE handle, int x, int y, int direction)
{
	mHandle = handle;
	mX = x;
	mY = y;
	mChar = '@';
	mDirection = direction;
	mColor = FOREGROUND_GREEN;
}

Body::Body()
{
	mHandle = globalhandle;
	mX = 1;
	mY = 1;
	mChar = '@';
	mDirection = -1;
	mColor = FOREGROUND_GREEN;
}

void Body::update(int x, int y)
{
	mX = x;
	mY = y;
}

void Body::operator=(const Body& body)
{
	this->mChar = body.mChar;
	this->mDirection = body.mDirection;
	this->mColor = body.mColor;
	this->mHandle = body.mHandle;
	this->mX = body.mX;
	this->mY = body.mY;
}