// Copyright WaderXu. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FGetFilePathModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
