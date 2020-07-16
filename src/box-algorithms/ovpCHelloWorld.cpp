/*
 * Prints user-specified greeting to the log with given frequency 
 */
#include "ovpCHelloWorld.h"

#include <cstdlib>		// atof
#include <openvibe/ovITimeArithmetics.h>

namespace OpenViBE {
namespace Plugins {
namespace Template {

uint64_t CHelloWorld::getClockFrequency()
{
	const double l_f64Frequency = FSettingValueAutoCast(*this->getBoxAlgorithmContext(), 0);

	// We need the freq in 32:32 fixed point time
	return ITimeArithmetics::secondsToTime(l_f64Frequency);
}

void CHelloWorld::release() { delete this; }

bool CHelloWorld::processClock(OpenViBE::Kernel::IMessageClock& /* rMessageClock */)
{
	const CString l_sMyGreeting = FSettingValueAutoCast(*this->getBoxAlgorithmContext(), 1);

	getLogManager() << OpenViBE::Kernel::LogLevel_Info << ": " << l_sMyGreeting << "\n";

	return true;
}

bool CHelloWorld::process() { return true; }

}
}
}
