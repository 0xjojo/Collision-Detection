// CollisionDetection.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <iostream>;
#include <vector>;
using namespace std;


class Vector2
{
public:
	Vector2()
	{
		this->x = 0;
		this->y = 0;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	Vector2 operator+(Vector2 v)
	{
		return Vector2(x + v.x, y + v.y);
	}

	Vector2 operator+=(float f)
	{
		return Vector2(x + f, y + f);
	}

	Vector2 operator-(Vector2 v)
	{
		return Vector2(x - v.x, y - v.y);
	}

	Vector2 operator-=(float f)
	{
		return Vector2(x - f, y - f);
	}

	Vector2 operator*(float f)
	{
		return Vector2(x * f, y * f);
	}

	bool operator==(Vector2 v)
	{
		if (x == v.x && y == v.y)
			return true;
		else
			return false;
	}

	float Length()
	{
		return sqrt(x * x + y * y);
	}

	float x;
	float y;
};

class Object
{
public:
	Object()
	{
	}

	Object(Vector2 position, Vector2 velocity)
	{
		this->position = position;
		this->velocity = velocity;
	}

	Vector2 position;
	Vector2 velocity;
};

struct CollisionData
{
	float time;
	Vector2 position;
};

class CollisionDetection
{
public:
	CollisionDetection(Object a, Object b)
	{
		this->a = a;
		this->b = b;
	}

	bool CheckCollision(CollisionData* col)
	{
		Vector2 relativeVel = a.velocity - b.velocity;

		Vector2 distanceVector = b.position - a.position;

		float timeOfImpact = distanceVector.Length() / relativeVel.Length();

		Vector2 collisionPoint = a.position + (relativeVel * timeOfImpact);

		if (collisionPoint == b.position)
		{
			col->position = a.position + (a.velocity * timeOfImpact);
			col->time = timeOfImpact;
			return true;
		}
		else
			return false;
	}

private:
	Object a;
	Object b;

	Vector2 GetCollisionPoint(float time)
	{
		return a.position + (a.velocity * time);
	}
};



int main()
{
	float objA_pos_x, objA_pos_y;
	float objA_vel_x, objA_vel_y;

	float objB_pos_x, objB_pos_y;
	float objB_vel_x, objB_vel_y;

	cout << "Enter First Position and Velocity: " << endl;
	cin >> objA_pos_x >> objA_pos_y >> objA_vel_x >> objA_vel_y;

	cout << endl << endl;

	cout << "Enter Second Position and Velocity: " << endl;
	cin >> objB_pos_x >> objB_pos_y >> objB_vel_x >> objB_vel_y;

	cout << endl << endl;

	//Vector2 objA_Pos(-5, 0);
	//Vector2 objA_Vel(1, 0);
	Vector2 objA_Pos(objA_pos_x, objA_pos_y);
	Vector2 objA_Vel(objA_vel_x, objA_vel_y);

	Object objA(objA_Pos, objA_Vel);

	//Vector2 objB_Pos(5, 0);
	//Vector2 objB_Vel(-1, 0);
	Vector2 objB_Pos(objB_pos_x, objB_pos_y);
	Vector2 objB_Vel(objB_vel_x, objB_vel_y);

	Object objB(objB_Pos, objB_Vel);
		
	CollisionDetection collision(objA, objB);

	CollisionData result;

	if (collision.CheckCollision(&result))
	{
		cout << "The two object will collide after " << result.time << " seconds, ";
		cout << "at position ( " << result.position.x << " , " << result.position.y << " )" << endl;
	}
	else
	{
		cout << "The two object will never collide." << endl;
	}


    return 0;
}



