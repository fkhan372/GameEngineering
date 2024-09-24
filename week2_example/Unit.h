#pragma once
#include <sstream>

class Unit
{
public:
	Unit() 
	{ 
		m_x = 0; 
		m_y = 0; 
		m_lastX = 0; 
		m_lastY = 0; 
		m_dirty = false;
		m_cachedData << "";
	}

	int GetX() { return m_x; }
	int GetY() { return m_y; }
	int GetLastX() { return m_lastX; }
	int GetLastY() { return m_lastY; }
	std::stringstream& GetCachedData() { return m_cachedData; }

	void MoveTo(int _x, int _y);
	void Update();

private:
	int m_x;
	int m_y;
	int m_lastX;
	int m_lastY;
	bool m_dirty;
	std::stringstream m_cachedData;
};

