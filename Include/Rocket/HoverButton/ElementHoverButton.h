#ifndef ROCKETHOVERBUTTONELEMENTHOVERBUTTON_H
#define ROCKETHOVERBUTTONELEMENTHOVERBUTTON_H

#include <Rocket/HoverButton/Header.h>
#include <Rocket/Core/Element.h>
#include <Rocket/Core/Geometry.h>
#include <Rocket/Core/Texture.h>

namespace Rocket {
namespace HoverButton {

/**
	A button using natural input such as kinect to trigger a click.

	@author Jeanneteau Silouane
*/

class ROCKETHOVERBUTTON_API ElementHoverButton : public Core::Element
{
public:
	/// Constructs a new ElementHoverButton. This should not be called directly; use the Factory instead.
	/// @param[in] tag The tag the element was declared as in RML.
	ElementHoverButton(const Rocket::Core::String& tag);
	virtual ~ElementHoverButton();

	/// Returns float value.
	/// @return The time required with the cursor over the element to trigger a click.
	float GetClickTime() const;
	/// Sets the time required to trigger a click on the element.
	/// @param[in] value The new time for the hover button.
	void SetClickTime(const float value);

    /// Returns float value.
    /// @return The time since the cursor is over the element.
    float GetHoverTime() const;

	/// Called for every event sent to this element or one of its descendants.
	/// @param[in] event The event to process.
	virtual void ProcessEvent(Rocket::Core::Event& event);

protected:
	/// Called during the update loop after children are updated.
	virtual void OnUpdate();

	/// Called when attributes on the element are changed.
	/// @param[in] changed_attributes The attributes changed on the element.
	virtual void OnAttributeChange(const Core::AttributeNameList& changed_attributes);
	/// Called when properties on the element are changed.
	/// @param[in] changed_properties The properties changed on the element.
	virtual void OnPropertyChange(const Core::PropertyNameList& changed_properties);

private:

	// The time since the cursor hover the element.
	float hover_time;

	// The time required to trigger the click on the element.
	float click_time;

	// True if cursor is over
	bool cursor_over;
};

}
}

#endif
