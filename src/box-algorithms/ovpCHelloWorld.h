#pragma once

#include "../ovp_defines.h"
#include <toolkit/ovtk_all.h>
#include <cstdio>

namespace OpenViBE {
namespace Plugins {
namespace Template {

class CHelloWorld : public Toolkit::TBoxAlgorithm<IBoxAlgorithm>
{
public:

	virtual void release();
	virtual uint64_t getClockFrequency();
	virtual bool processClock(CMessage& /*msg*/);
	virtual bool process();

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithm, OVP_ClassId_HelloWorld)
};

class CHelloWorldListener : public Toolkit::TBoxListener<IBoxListener>
{
public:

	_IsDerivedFromClass_Final_(Toolkit::TBoxListener < OpenViBE::Plugins::IBoxListener >, OV_UndefinedIdentifier);
};

class CHelloWorldDesc : public IBoxAlgorithmDesc
{
public:

	virtual void release() { }
	virtual CString getName() const { return "Template HelloWorld"; }
	virtual CString getAuthorName() const { return ""; }
	virtual CString getAuthorCompanyName() const { return "INRIA"; }
	virtual CString getShortDescription() const { return "Prints \"Hello World!\" to the log with a user-specified frequency"; }
	virtual CString getDetailedDescription() const
	{
		return "Using several copies of this friendly box (with different names) can be used to e.g. examine box execution order";
	}
	virtual CString getCategory() const { return "Examples/Basic"; }
	virtual CString getVersion() const { return "1.0"; }
	virtual CString getStockItemName() const { return "gtk-copy"; }

	virtual CIdentifier getCreatedClass() const { return OVP_ClassId_HelloWorld; }
	virtual IPluginObject* create() { return new CHelloWorld(); }
	virtual IBoxListener* createBoxListener() const { return new CHelloWorldListener; }
	virtual void releaseBoxListener(IBoxListener* pBoxListener) const { delete pBoxListener; }

	virtual bool getBoxPrototype(
		Kernel::IBoxProto& rPrototype) const
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
