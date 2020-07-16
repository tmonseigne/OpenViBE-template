#include "ovpCHelloWorld.h"

namespace OpenViBE {
namespace Plugins {
namespace Template {

uint64_t CHelloWorld::getClockFrequency()
{
	const double seconds = FSettingValueAutoCast(*this->getBoxAlgorithmContext(), 0);
	// We need the freq in 32:32 fixed point time
	return CTime::fromSeconds(seconds);
}

bool CHelloWorld::processClock(CMessage& /*msg*/)
{
	const CString myGreeting = FSettingValueAutoCast(*this->getBoxAlgorithmContext(), 1);
	getLogManager() << Kernel::LogLevel_Info << ": " << myGreeting << "\n";
	return true;
}

}
}
}
