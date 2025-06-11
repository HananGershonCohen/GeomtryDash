#pragma once

class ObjectInformation 
{
public:
	void setNextLevel(bool nextLevel) { m_nextLevel = nextLevel; }
	void setPlayerDead(bool playerDead) { m_PlayerDead = playerDead; }

	bool isNextLevel() const { return m_nextLevel; }
	bool isPlayerDead() const { return m_PlayerDead; }

private:
	bool m_nextLevel = false; 
	bool m_PlayerDead = false; // if the player need to dead
};
