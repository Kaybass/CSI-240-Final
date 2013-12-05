#include <windows.h>
#include "handle.h"
#include <vector>
#pragma once


class Item
{
public:
	Item( HANDLE handle, int x, int y, char displayChar );
	Item();
	~Item(){};

	virtual void update()=0;
	virtual void draw() const;

protected:
	HANDLE mHandle;
	int mX;
	int mY;
	char mChar;
	
};

class ColorItem:public Item
{
public:
	ColorItem( HANDLE handle, int x, int y, char displayChar, int color );
	ColorItem();
	~ColorItem(){};

	virtual void update();
	virtual void draw() const;

protected:
	int mColor;
};

class Food:public ColorItem
{
public:
	Food(HANDLE handle);
	~Food(){};

	int getX()const {return mX;};
	int getY()const {return mY;};

	virtual void update();
};

class Body:public ColorItem
{
public:
	Body(HANDLE handle, int x, int y, int direction);
	Body();
	~Body(){};

	virtual void update( int x, int y);

	int getX(){return mX;};
	int getY(){return mY;};
	int getDirection(){return mDirection;};

	void setDirection(int direction){mDirection = direction;};

	void operator=(const Body& body);

private:
	int mDirection;
};