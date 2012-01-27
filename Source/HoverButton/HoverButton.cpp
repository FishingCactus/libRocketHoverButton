#include <Rocket/HoverButton.h>
#include <Rocket/HoverButton/ElementHoverButton.h>
#include <Rocket/Core/ElementInstancerGeneric.h>
#include <Rocket/Core/Factory.h>
#include <Rocket/Core/StyleSheetSpecification.h>
#include <Rocket/Core/XMLParser.h>
#include <Rocket/Core/Plugin.h>
#include <Rocket/Core/Core.h>

namespace Rocket {
namespace HoverButton {

void RegisterElementInstancers()
{
	Core::ElementInstancer* instancer = new Core::ElementInstancerGeneric< ElementHoverButton >();
	Core::Factory::RegisterElementInstancer("button", instancer);
	instancer->RemoveReference();
}

static bool initialised = false;

class HoverButtonPlugin : public Rocket::Core::Plugin
{
public:
	void OnShutdown()
	{
		initialised = false;
		delete this;
	}

	int GetEventClasses()
	{
		return Rocket::Core::Plugin::EVT_BASIC;
	}
};

void Initialise()
{
	// Prevent double initialization
	if (!initialised)
	{
		RegisterElementInstancers();

		// Register the hover button plug in, so we'll be notified on Shutdown
		Rocket::Core::RegisterPlugin(new HoverButtonPlugin());

		initialised = true;
	}
}

}
}