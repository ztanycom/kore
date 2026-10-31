#pragma once

#include "Event.h"



namespace Kore
{
	class KORE_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		int m_KeyCode;

		KeyEvent(int keycode):m_KeyCode(keycode)
		{ }

	};

	class KORE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount):KeyEvent(keycode)
		{
			m_RepeatCount = repeatCount;
		}

		inline int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override		//拼成以个可读的字符串，用于日志和调试
		{
			std::stringstream ss;
			ss << "KeyPressedEvent:" << m_KeyCode << "(" << m_RepeatCount << "repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int m_RepeatCount;
	};

	class KORE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode):KeyEvent(keycode)
		{ }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent:" << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)

	};
}