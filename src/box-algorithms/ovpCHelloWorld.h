#pragma once

#include "../ovp_defines.h"
#include <toolkit/ovtk_all.h>
#include <cstdio>

namespace OpenViBE {
namespace Plugins {
namespace Template {

class CHelloWorld : public Toolkit::TBoxAlgorithm<OpenViBE::Plugins::IBoxAlgorithm>
{
public:

	virtual void release();
	virtual uint64_t getClockFrequency();
	virtual bool processClock(CMessage& /*msg*/);
	virtual bool process();

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithm, OVP_ClassId_HelloWorld)
};

class CHelloWorldListener : public Toolkit::TBoxListener<OpenViBE::Plugins::IBoxListener>
{
public:

	_IsDerivedFromClass_Final_(OpenViBEToolkit::TBoxListener < OpenViBE::Plugins::IBoxListener >, OV_UndefinedIdentifier);
};

class CHelloWorldDesc : public OpenViBE::Plugins::IBoxAlgorithmDesc
{
public:

	virtual void release() { }
	virtual OpenViBE::CString getName() const { return OpenViBE::CString("HelloWorld"); }
	virtual OpenViBE::CString getAuthorName() const { return OpenViBE::CString(""); }
	virtual OpenViBE::CString getAuthorCompanyName() const { return OpenViBE::CString("INRIA"); }
	virtual OpenViBE::CString getShortDescription() const { return OpenViBE::CString("Prints \"Hello World!\" to the log with a user-specified frequency"); }
	virtual OpenViBE::CString getDetailedDescription() const
	{
		return OpenViBE::CString("Using several copies of this friendly box (with different names) can be used to e.g. examine box execution order");
	}
	virtual OpenViBE::CString getCategory() const { return OpenViBE::CString("Examples/Basic"); }
	virtual OpenViBE::CString getVersion() const { return OpenViBE::CString("1.0"); }
	virtual OpenViBE::CString getStockItemName() const { return OpenViBE::CString("gtk-copy"); }

	virtual OpenViBE::CIdentifier getCreatedClass() const { return OVP_ClassId_HelloWorld; }
	virtual OpenViBE::Plugins::IPluginObject* create() { return new OpenViBE::Plugins::Examples::CHelloWorld(); }
	virtual OpenViBE::Plugins::IBoxListener* createBoxListener() const { return new CHelloWorldListener; }
	virtual void releaseBoxListener(OpenViBE::Plugins::IBoxListener* pBoxListener) const { delete pBoxListener; }

	virtual bool getBoxPrototype(
		OpenViBE::Kernel::IBoxProto& rPrototype) const
	{
		rPrototype.addSetting("Frequency (Hz)", OV_TypeId_Float, "1.0");
		rPrototype.addSetting("My greeting", OV_TypeId_String, "Hello World!");

		return true;
	}

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithmDesc, OVP_ClassId_HelloWorldDesc)
};

}
}
}
