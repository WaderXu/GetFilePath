// Copyright WaderXu. All Rights Reserved.

#include "GetFilePath.h"

#define LOCTEXT_NAMESPACE "FGetFilePathModule"

void FGetFilePathModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
}

void FGetFilePathModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FGetFilePathModule, GetFilePath)