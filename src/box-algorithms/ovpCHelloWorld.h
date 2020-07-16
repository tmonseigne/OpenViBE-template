#pragma once

#include "../ovp_defines.h"
#include <toolkit/ovtk_all.h>

namespace OpenViBE {
namespace Plugins {
namespace Template {

class CHelloWorld : public Toolkit::TBoxAlgorithm<IBoxAlgorithm>
{
public:

	void release() override;
	uint64_t getClockFrequency() override;
	bool processClock(CMessage& /*msg*/) override;
	bool process() override;

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithm, Box_TemplateHelloWorld)
};

class CHelloWorldListener : public Toolkit::TBoxListener<IBoxListener>
{
public:

	_IsDerivedFromClass_Final_(Toolkit::TBoxListener < OpenViBE::Plugins::IBoxListener >, CIdentifier::undefined());
};

class CHelloWorldDesc : public IBoxAlgorithmDesc
{
public:

	void release() override { }
	CString getName() const override { return "Template HelloWorld"; }
	CString getAuthorName() const override { return ""; }
	CString getAuthorCompanyName() const override { return "INRIA"; }
	CString getShortDescription() const override { return "Prints \"Hello World!\" to the log with a user-specified frequency"; }
	CString getDetailedDescription() const override
	{
		return "Using several copies of this friendly box (with different names) can be used to e.g. examine box execution order";
	}
	CString getCategory() const override { return "Examples/Basic"; }
	CString getVersion() const override { return "1.0"; }
	CString getStockItemName() const override { return "gtk-copy"; }

	CIdentifier getCreatedClass() const override { return Box_TemplateHelloWorld; }
	IPluginObject* create() override { return new CHelloWorld(); }
	IBoxListener* createBoxListener() const override { return new CHelloWorldListener; }
	void releaseBoxListener(IBoxListener* pBoxListener) const override { delete pBoxListener; }

	bool getBoxPrototype(Kernel::IBoxProto& prototype) const override
	{
		prototype.addSetting("Frequency (Hz)", OV_TypeId_Float, "1.0");
		prototype.addSetting("My greeting", OV_TypeId_String, "Hello World!");

		return true;
	}

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithmDesc, Box_TemplateHelloWorldDesc)
};

}
}
}
