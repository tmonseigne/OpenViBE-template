///-------------------------------------------------------------------------------------------------
/// 
/// \file CHelloWorld.hpp
/// \brief Hello World box for template.
/// \author Thibaut Monseigne (Inria).
/// \version 1.0.
/// \date 16/07/2020.
/// \copyright <a href="https://choosealicense.com/licenses/agpl-3.0/">GNU Affero General Public License v3.0</a>.
/// 
///-------------------------------------------------------------------------------------------------
#pragma once

#include "defines.hpp"
#include <toolkit/ovtk_all.h>

namespace OpenViBE {
namespace Plugins {
namespace Template {

class CHelloWorld final : public Toolkit::TBoxAlgorithm<IBoxAlgorithm>
{
public:

	void release() override { delete this; }
	uint64_t getClockFrequency() override;
	bool processClock(CMessage& /*msg*/) override;
	bool process() override { return true; }

	_IsDerivedFromClass_Final_(IBoxAlgorithm, Box_TemplateHelloWorld)
};

class CHelloWorldListener final : public Toolkit::TBoxListener<IBoxListener>
{
public:

	_IsDerivedFromClass_Final_(Toolkit::TBoxListener<IBoxListener>, CIdentifier::undefined());
};

class CHelloWorldDesc final : public IBoxAlgorithmDesc
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
	void releaseBoxListener(IBoxListener* boxListener) const override { delete boxListener; }

	bool getBoxPrototype(Kernel::IBoxProto& prototype) const override
	{
		prototype.addSetting("Frequency (Hz)", OV_TypeId_Float, "1.0");
		prototype.addSetting("My greeting", OV_TypeId_String, "Hello World!");

		return true;
	}

	_IsDerivedFromClass_Final_(OpenViBE::Plugins::IBoxAlgorithmDesc, Box_TemplateHelloWorldDesc)
};

}  // namespace Template
}  // namespace Plugins
}  // namespace OpenViBE
