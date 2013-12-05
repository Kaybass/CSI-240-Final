#include "item.h"
#include "walls.h"

class Snake
{
public:
	struct ListNode
	{
	public:
		ListNode( const Body& theitem, ListNode* pNext = NULL )
		{
			item = theitem;
			pNextNode = pNext;
		}

		Body item;
		ListNode* pNextNode;
	};
public:
	Snake(HANDLE handle);
	Snake();
	~Snake();
	
	virtual void update(int direction) = 0;

	virtual void addFood(const Food* thefood) = 0;

	void addHead(int x, int y,int direction);
	void addTail(int x, int y, int direction);

	int checkSelfCollision();

	int checkCollision(int x, int y);

	int checkWalls();

	int getLength(){return mLength;};
protected:
	int mLength;
	ListNode *mpHead;
	int removeHead();
	HANDLE mHandle;
};

class PlayerSnake:public Snake
{
public:
	PlayerSnake(HANDLE handle);
	PlayerSnake();
	~PlayerSnake();

	virtual void update(int direction);

	virtual void addFood(const Food* thefood);
};