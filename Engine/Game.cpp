/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	board(gfx),
	goal(snake)
{
	snake.Init(Location(5, 3), 5);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	bool up = wnd.kbd.KeyIsPressed(VK_UP);
	bool down = wnd.kbd.KeyIsPressed(VK_DOWN);
	bool left = wnd.kbd.KeyIsPressed(VK_LEFT);
	bool right = wnd.kbd.KeyIsPressed(VK_RIGHT);
	Controls(up, down, left, right);

	timeCounter++;
	if (!gameOver && timeCounter > framesPerMove) {
		timeCounter = 0;

		if(goal.isEatenAndReposition(snake))
			snake.Grow();
		snake.Update(up, down, left, right);
		gameOver = snake.IsSelfColliding();
	}
}

void Game::Controls(bool& up, bool& down, bool& left, bool& right)
{
	const Location loc_up(0, -1);
	const Location loc_down(0, 1);
	const Location loc_left(-1, 0);
	const Location loc_right(1, 0);
	if (up && !(snake.GetMovementDirection() == loc_up)) {
		down = false, left = false, right = false;
	}
	else if (down && !(snake.GetMovementDirection() == loc_down)) {
		up = false, left = false, right = false;
	}
	else if (left && !(snake.GetMovementDirection() == loc_left)) {
		up = false, down = false, right = false;
	}
	else if (right && !(snake.GetMovementDirection() == loc_right)) {
		up = false, down = false, left = false;
	}
}

void Game::ComposeFrame()
{
	snake.Draw(board);
	goal.Draw(board);
	board.DrawBorder();
}
