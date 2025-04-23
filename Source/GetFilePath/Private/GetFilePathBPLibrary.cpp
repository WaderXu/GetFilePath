// Copyright WaderXu. All Rights Reserved.

#include "GetFilePathBPLibrary.h"
#include "GetFilePath.h"
#include "DesktopPlatformModule.h"
#include "Framework/Application/SlateApplication.h"
#include "IDesktopPlatform.h"

UGetFilePathBPLibrary::UGetFilePathBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

float UGetFilePathBPLibrary::GetFilePathSampleFunction(float Param)
{
	return -1;
}

//点击按钮弹窗，返回选择的文件路径
FString UGetFilePathBPLibrary::OnSelectFile()
{
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (DesktopPlatform)
    {
        TArray<FString> OutFiles;
        const void* ParentWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
        FString Title = TEXT("选择文件");
        FString DefaultPath = FPaths::ProjectDir();
        FString FileTypes = TEXT("所有文件 (*.*)|*.*");

        bool bOpened = DesktopPlatform->OpenFileDialog(
            ParentWindowHandle,
            Title,
            DefaultPath,
            TEXT(""),
            FileTypes,
            EFileDialogFlags::None,
            OutFiles
        );

        if (bOpened && OutFiles.Num() > 0)
        {
            FString SelectedFile = OutFiles[0];
            //返回路径
            return SelectedFile;
        }
    }

    //必须要有默认的返回类型
    return FString();
}
