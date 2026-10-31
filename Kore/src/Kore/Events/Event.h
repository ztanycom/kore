#pragma once

#include "Kore/Core.h"



namespace Kore
{


	enum class EventType                               //事件类型
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved

	};

	enum EventCategory {								//事件类别
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput		 = BIT(1),
		EventCategoryKeyboard	 = BIT(2),
		EventCategoryMouse		 = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) \
	static EventType GetStaticType() {return EventType::type;}\
	virtual EventType GetEventType() const override{return GetStaticType();}\
	virtual const char* GetName() const override {return #type;}

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class KORE_API Event		//所有事件类的基类
	{
		friend class EventDispatcher;		//允许EventDispatcher类访问Event的私有和受保护成员
	public:
		virtual EventType GetEventType() const = 0;				//等待子类#define EVENT_CLASS_TYPE(type)定义重写
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }		//函数定义在类内部 → 隐式 inline

		inline bool IsInCategory(EventCategory category)		//判断这个事件是否属于某个类别
		{
			return GetCategoryFlags() & category;
		}
	protected:
		bool m_Handled = false;		//事件是否已被处理，阻断的核心
	};

	class EventDispatcher		//事件分发器，作用是根据事件的实际类型，调用对应的处理函数
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;		//EventFn<T>作为一个接收 T&、返回 bool 的可调用对象函数
	public:
		EventDispatcher(Event& event):m_Event(event)
		{

		}
		template<typename T>
		bool Dispatch(EventFn<T> func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())	//判断运行时的真实类型与编译期T的类型常量是否匹配
			{													//T::GetStaticType()中T代表其中一个事件类，由这个类来获得枚举类型type
																//type由宏来定义
				m_Event.m_Handled = func(*(T*)&m_Event);				//&m_Event是Event*，(T*)把Event*向下转型成 T*(具体子类的指针)
				return true;											//最前面的*用于解引用&T
																		//返回值为true = 类型匹配并处理了；false = 类型不匹配没处理
			}
			return false;
		}

	private:
		Event& m_Event;
	};


	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.ToString();
	}
}