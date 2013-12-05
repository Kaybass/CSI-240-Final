#include "snake.h"

Snake::Snake(HANDLE handle)
{
	mHandle = handle;
	mpHead = NULL;
	mLength = 0;
}

Snake::Snake()
{
	mHandle = globalhandle;
	mpHead = NULL;
	mLength = 0;
}

Snake::~Snake()
{
	int i = 0;

	while(i != 1)
	{
		i = removeHead();
	}
}

void Snake::addHead(int x, int y,int direction)
{
	Body theBody = Body(mHandle,x,y,direction);

	ListNode * pNode = new ListNode(theBody);

	pNode->pNextNode = mpHead;

	mpHead = pNode;

	mLength++;
}

void Snake::addTail(int x, int y, int direction)
{
	if(mpHead != NULL)
	{

		Body body = Body(mHandle,x,y,direction);

		ListNode * pNode = new ListNode(body);

		if(mpHead->pNextNode != NULL)
		{
			ListNode * pCur = mpHead;

			while(pCur->pNextNode != NULL)
			{
				pCur = pCur->pNextNode;
			}

			pCur->pNextNode = pNode;
		}
		else
		{
			mpHead->pNextNode = pNode;
		}
	}
	mLength++;
}

int Snake::removeHead()
{
	if (mpHead != NULL)
	{
		ListNode * temp = mpHead->pNextNode;

		delete mpHead;

		mpHead = temp;

		delete mpHead;

		mpHead = NULL;

		return 0;
	}

	return 1;
}

int Snake::checkSelfCollision()
{
	if (mpHead != NULL)
	{
		if (mpHead->pNextNode != NULL)
		{
			ListNode * pCur = mpHead->pNextNode;

			while(pCur ->pNextNode != NULL)
			{
				if(pCur->item.getX() == mpHead->item.getX() && pCur->item.getY() == mpHead->item.getY())
				{
					return 1;
				}
				pCur = pCur->pNextNode;
			}
		}
		return 0;
	}

	return 0;
}

int Snake::checkCollision(int x, int y)
{
	if (mpHead != NULL)
	{
		if (mpHead->item.getX() == x && mpHead->item.getY() == y)
		{
			return 1;
		}
		return 0;
	}

	return 0;
}

int Snake::checkWalls()
{
	if(mpHead->item.getX() == X_MAX || 
		mpHead->item.getX() == X_MIN ||
		mpHead->item.getY() == Y_MAX ||
		mpHead->item.getY() == Y_MIN)
	{
		return 1;
	}

	return 0;
}

PlayerSnake::PlayerSnake()
:Snake()
{
}

PlayerSnake::PlayerSnake(HANDLE handle)
:Snake(handle)
{
}

void PlayerSnake::update(int direction)
{
	if(mpHead != NULL)
	{
		if(mpHead->pNextNode != NULL)
		{
			ListNode * pCur = mpHead;

			int lastDirection = direction, currentDirection = pCur->item.getDirection();

			while(pCur->pNextNode != NULL)
			{
				switch(lastDirection)
				{
				case WEST: //west
					pCur->item.setDirection(WEST);
					pCur->item.update(pCur->item.getX() - 1,pCur->item.getY());
					pCur->item.draw();
					pCur = pCur->pNextNode;
					lastDirection = currentDirection;
					currentDirection = pCur->item.getDirection();
					break;
				case EAST: //east
					pCur->item.setDirection(EAST);
					pCur->item.update(pCur->item.getX() + 1,pCur->item.getY());
					pCur->item.draw();
					pCur = pCur->pNextNode;
					lastDirection = currentDirection;
					currentDirection = pCur->item.getDirection();
					break;
				case SOUTH: //south
					pCur->item.setDirection(SOUTH);
					pCur->item.update(pCur->item.getX(),pCur->item.getY() + 1);
					pCur->item.draw();
					pCur = pCur->pNextNode;
					lastDirection = currentDirection;
					currentDirection = pCur->item.getDirection();
					break;
				case NORTH: //north
					pCur->item.setDirection(NORTH);
					pCur->item.update(pCur->item.getX(),pCur->item.getY() - 1);
					pCur->item.draw();
					pCur = pCur->pNextNode;
					lastDirection = currentDirection;
					currentDirection = pCur->item.getDirection();
					break;
				default:
					break;
				}
			}
			switch(lastDirection)
			{
			case WEST: //west
				pCur->item.setDirection(WEST);
				pCur->item.update(pCur->item.getX() - 1,pCur->item.getY());
				pCur->item.draw();
				break;
			case EAST: //east
				pCur->item.setDirection(EAST);
				pCur->item.update(pCur->item.getX() + 1,pCur->item.getY());
				pCur->item.draw();
				break;
			case SOUTH: //south
				pCur->item.setDirection(SOUTH);
				pCur->item.update(pCur->item.getX(),pCur->item.getY() + 1);
				pCur->item.draw();
				break;
			case NORTH: //north
				pCur->item.setDirection(NORTH);
				pCur->item.update(pCur->item.getX(),pCur->item.getY() - 1);
				pCur->item.draw();
				break;
			default:
				break;
			}
		}
		else
		{
			switch(direction)
			{
			case WEST:
				mpHead->item.setDirection(WEST);
				mpHead->item.update(mpHead->item.getX() - 1,mpHead->item.getY());
				mpHead->item.draw();
				break;
			case EAST:
				mpHead->item.setDirection(EAST);
				mpHead->item.update(mpHead->item.getX() + 1,mpHead->item.getY());
				mpHead->item.draw();
				break;
			case SOUTH:
				mpHead->item.setDirection(SOUTH);
				mpHead->item.update(mpHead->item.getX(),mpHead->item.getY() + 1);
				mpHead->item.draw();
				break;
			case NORTH:
				mpHead->item.setDirection(NORTH);
				mpHead->item.update(mpHead->item.getX(),mpHead->item.getY() - 1);
				mpHead->item.draw();
				break;
			default:
				break;
			}
		}
	}
}

void PlayerSnake::addFood(const Food* thefood)
{
	switch(mpHead->item.getDirection())
	{
	case NORTH:
		addHead(mpHead->item.getX(),mpHead->item.getY() - 1,mpHead->item.getDirection());
		break;
	case EAST:
		addHead(mpHead->item.getX() + 1,mpHead->item.getY(),mpHead->item.getDirection());
		break;
	case SOUTH:
		addHead(mpHead->item.getX(),mpHead->item.getY() + 1,mpHead->item.getDirection());
		break;
	case WEST:
		addHead(mpHead->item.getX() - 1,mpHead->item.getY(),mpHead->item.getDirection());
		break;
	default:
		break;
	}
	delete thefood;
}
