#include <Rocket/HoverButton/ElementHoverButton.h>
#include <Rocket/Core/GeometryUtilities.h>
#include <Rocket/Core/ElementDocument.h>
#include <Rocket/Core.h>

namespace Rocket {
namespace HoverButton {

// Constructs a new ElementHoverButton. This should not be called directly; use the Factory instead.
ElementHoverButton::ElementHoverButton(const Rocket::Core::String& tag) : Core::Element(tag), hover_time(0.0f), click_time(1.5f), cursor_over(false)
{
}

ElementHoverButton::~ElementHoverButton()
{
}

// Returns the time required with the cursor over the element to trigger a click.
float ElementHoverButton::GetClickTime() const
{
	return click_time;
}

// Return The time since the cursor is over the element.
float ElementHoverButton::GetHoverTime() const
{
	return hover_time;
}

// Sets the time required to trigger a click on the element.
void ElementHoverButton::SetClickTime(const float value)
{
	click_time=value;
}

// Called for every event sent to this element or one of its descendants.
void ElementHoverButton::ProcessEvent(Rocket::Core::Event& event)
{
	Element::ProcessEvent( event );

	if (event.GetTargetElement() == this)
	{
		if (event == "mouseover")
		{
			cursor_over=true;
		}
		else if (event == "mouseout")
		{
			cursor_over=false;
		}
	}
}

// Called during the update loop after children are rendered.
void ElementHoverButton::OnUpdate()
{
	if (cursor_over)
	{
		hover_time+=Core::GetSystemInterface()->GetElapsedTime();
	}
	else
	{
		hover_time=0.0f;
	}

	if (hover_time >= click_time)
	{
		Click();
		hover_time=0.0f;
	}
}

// Called when attributes on the element are changed.
void ElementHoverButton::OnAttributeChange(const Core::AttributeNameList& changed_attributes)
{
	Element::OnAttributeChange(changed_attributes);
}

// Called when properties on the element are changed.
void ElementHoverButton::OnPropertyChange(const Core::PropertyNameList& changed_properties)
{
	Element::OnPropertyChange(changed_properties);

	if (changed_properties.find("click-time") != changed_properties.end())
	{
		SetClickTime(GetProperty< float >("click-time"));
	}
}

}
}
