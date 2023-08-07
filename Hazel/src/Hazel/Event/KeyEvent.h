#include "Event.h"

namespace Hazel
{
	class KeyEvent : public Event
	{
	public: 
		int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const int KeyCode) : m_KeyCode(KeyCode)
		{

		}
		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int KeyCode, bool isRepeated = false) : KeyEvent(KeyCode), m_isRepeated(isRepeated)
		{

		}
		bool isRepeated() const { return m_isRepeated; }
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent :" << m_KeyCode << "(repeated = " << m_isRepeated << ")";
			return ss.str();
		}
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		bool m_isRepeated;
	};
}