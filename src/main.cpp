#include <openvibe/ov_all.hpp>
#include "defines.hpp"

// Boxes Includes
#include "boxes/CHelloWorld.hpp"

OVP_Declare_Begin();
	// Register boxes
	OVP_Declare_New(OpenViBE::Plugins::Template::CHelloWorldDesc);
OVP_Declare_End();