#include "Objects/button.h"


namespace Button
{
	bool IsMouseOnButton(Button button)
	{
		return GetMouseX() > button.shape.x &&
			GetMouseY() > button.shape.y &&
			GetMouseX() < (button.shape.x + button.shape.width) &&
			GetMouseY() < (button.shape.y + button.shape.height);
	}

	void CheckSceneChange(Button& button, SceneManager::Scene scene)
	{
		//Audio::ButtonSfx sfx{};

		if (IsMouseOnButton(button))
		{
			button.currentColor = button.highlightColor;

			//sfx = Audio::GetRandomSfx();

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				/*if (!Audio::IsPlaying(sfx))
					Audio::Play(sfx);*/
				
				SceneManager::SetCurrentScene(scene);
			}
		}
		else
			button.currentColor = button.defaultColor;
		
	}
	/*
	void CheckSceneChange(Button& button, SceneManager::Scene scene Audio::Song songToStop)
	{
		Audio::ButtonSfx sfx{};

		if (IsMouseOnButton(button))
		{
			button.currentColor = button.highlightColor;

			sfx = Audio::GetRandomSfx();

			if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
			{
				if (!Audio::IsPlaying(sfx))
					Audio::Play(sfx);
				Audio::Stop(songToStop);
				SceneManager::SetCurrentScene(scene);
			}
		}
		else
			button.currentColor = button.defaultColor;
	}
	*/
	

	static void DrawButtonText(Button button)
	{
		DrawText(button.textShown.content.c_str(), static_cast<int>(button.shape.x) + static_cast<int>(button.shape.width / 2) - MeasureText(button.textShown.content.c_str(), button.textShown.fontSize) / 2, static_cast<int>(button.shape.y) + static_cast<int>(button.shape.height / 2) - button.textShown.fontSize / 2, button.textShown.fontSize, button.textShown.currentColor);
	}

	static void DrawButtonRect(Button button)
	{
		DrawRectangle(static_cast<int>(button.shape.x), static_cast<int>(button.shape.y), static_cast<int>(button.shape.width), static_cast<int>(button.shape.height), button.currentColor);
		DrawRectangleLines(static_cast<int>(button.shape.x), static_cast<int>(button.shape.y), static_cast<int>(button.shape.width), static_cast<int>(button.shape.height), button.highlightColor);
	}

	void DrawButton(Button button)
	{
		DrawButtonRect(button);
		DrawButtonText(button);
	}

	Button GetButton(float x, float y, float width, float height, string content, Color mainColor, Color highlightColor, Color textColor/*, Text::Fonts font*/)
	{
		Button myButton;

		myButton.defaultColor = mainColor;
		myButton.currentColor = myButton.defaultColor;
		myButton.highlightColor = highlightColor;
		myButton.shape.width = width;
		myButton.shape.height = height;
		myButton.shape.x = x;
		myButton.shape.y = y;
		myButton.textShown.content = content;
		myButton.textShown.fontSize = static_cast<int>(height) / 2;
		myButton.textShown.currentColor = textColor;
		myButton.textShown.location.x = x + width / 2.0f - static_cast<float>(MeasureText(myButton.textShown.content.c_str(), myButton.textShown.fontSize), myButton.textShown.fontSize);
		//myButton.textShown.font = font;

		return myButton;
	}
};