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

//�����ť����������ѡ����ļ�·��
FString UGetFilePathBPLibrary::OnSelectFile()
{
    IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get();
    if (DesktopPlatform)
    {
        TArray<FString> OutFiles;
        const void* ParentWindowHandle = FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr);
        FString Title = TEXT("ѡ���ļ�");
        FString DefaultPath = FPaths::ProjectDir();
        FString FileTypes = TEXT("�����ļ� (*.*)|*.*");

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
            //����·��
            return SelectedFile;
        }
    }

    //����Ҫ��Ĭ�ϵķ�������
    return FString();
}
