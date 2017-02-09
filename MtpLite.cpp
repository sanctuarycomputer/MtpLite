// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.
//
// Defines the entry point for the console application.
//

#include "stdafx.h"

void ChooseDevice(_Outptr_result_maybenull_ IPortableDevice** device);

// Content enumeration
void EnumerateAllContent(_In_ IPortableDevice* device);
v8::Local<v8::Object> EnumerateAllContentV8(_In_ IPortableDevice* device);

void ReadHintLocations(_In_ IPortableDevice* device);

// Content transfer
void TransferContentFromDevice(_In_ IPortableDevice* device);

// Hughboys
void ListDevices(_Outptr_result_maybenull_ IPortableDevice** device);
v8::Local<v8::Array> ListDevicesV8(_Outptr_result_maybenull_ IPortableDevice** device);


void ChooseFirstLightPhone(_Outptr_result_maybenull_ IPortableDevice** device);

void TransferFileToDevice(
	_In_ IPortableDevice* device,
	_In_ REFGUID          contentType,
	_In_ wchar_t*         parentID,
	_In_ wchar_t*         localFilePath);

v8::Local<v8::Object> TransferFileToDeviceV8(
	_In_ IPortableDevice* device,
	_In_ REFGUID          contentType,
	_In_ wchar_t*         parentID,
	_In_ wchar_t*         localFilePath);

void GetFileFromDevice(
	_In_ IPortableDevice* device,
	_In_ wchar_t*         fileID);

v8::Local<v8::Object> GetFileFromDeviceV8(
	_In_ IPortableDevice*       device,
	_In_ wchar_t*               fileID,
  _Out_ v8::Local<v8::Object> results);

void DeleteFileFromDevice(
	_In_ IPortableDevice* device,
	_In_ wchar_t*         fileID);

v8::Local<v8::Object> DeleteFileFromDeviceV8(
	_In_ IPortableDevice*       device,
	_In_ wchar_t*               fileID,
  _Out_ v8::Local<v8::Object> results);

//End Hughboys

void TransferContentToDevice(
    _In_ IPortableDevice* device,
    _In_ REFGUID          contentType,
    _In_ PCWSTR           fileTypeFilter,
    _In_ PCWSTR           defaultFileExtension);
void TransferContactToDevice(_In_ IPortableDevice* device);
void CreateFolderOnDevice(_In_ IPortableDevice* device);
void CreateContactPhotoResourceOnDevice(_In_ IPortableDevice* device);

// Content deletion
void DeleteContentFromDevice(_In_ IPortableDevice* device);

// Content moving
void MoveContentAlreadyOnDevice(_In_ IPortableDevice* device);

// Content update (properties and data simultaneously)
void UpdateContentOnDevice(
    _In_ IPortableDevice* device,
    _In_ REFGUID          contentType,
    _In_ PCWSTR           fileTypeFilter,
    _In_ PCWSTR           defaultFileExtension);

// Content properties
void ReadContentProperties(_In_ IPortableDevice* device);
void WriteContentProperties(_In_ IPortableDevice* device);
void ReadContentPropertiesBulk(_In_ IPortableDevice* device);
void WriteContentPropertiesBulk(_In_ IPortableDevice* device);
void ReadContentPropertiesBulkFilteringByFormat(_In_ IPortableDevice* device);

// Functional objects
void ListFunctionalObjects(_In_ IPortableDevice* device);
void ListFunctionalCategories(_In_ IPortableDevice* device);
void ListSupportedContentTypes(_In_ IPortableDevice* device);
void ListRenderingCapabilityInformation(_In_ IPortableDevice* device);

// Device events
void ListSupportedEvents(_In_ IPortableDevice* device);
void RegisterForEventNotifications(_In_ IPortableDevice* device, _Inout_ PWSTR* eventCookie);
void UnregisterForEventNotifications(_In_opt_ IPortableDevice* device, _In_opt_ PCWSTR eventCookie);

// Misc.
void GetObjectIdentifierFromPersistentUniqueIdentifier(_In_ IPortableDevice* device);


// Methods
void DoDeviceList()
{
	ComPtr<IPortableDevice> device;
	return ListDevices(&device);
}

// Methods
v8::Local<v8::Array> DoDeviceListV8()
{
	ComPtr<IPortableDevice> device;
	//return Nan::New<v8::Array>();
	return ListDevicesV8(&device);
}

void DoContentList()
{
	ComPtr<IPortableDevice> device;
	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return;
	}
	std::cout << "\nListing Content on The Light Phone:\n";
	EnumerateAllContent(device.Get());
}

v8::Local<v8::Object> DoContentListV8()
{
	ComPtr<IPortableDevice> device;
	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return Nan::New<v8::Object>();
	}
	return EnumerateAllContentV8(device.Get());
}

void DoSendFile(
	_In_ wchar_t* deviceParentID,
	_In_ wchar_t* localFilePath)
{
	ComPtr<IPortableDevice> device;
	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return;
	}
	TransferFileToDevice(device.Get(),
		WPD_CONTENT_TYPE_UNSPECIFIED,
		deviceParentID,
		localFilePath);
}

v8::Local<v8::Object> DoSendFileV8(
	_In_ wchar_t* deviceParentID,
	_In_ wchar_t* localFilePath)
{
	ComPtr<IPortableDevice> device;
	v8::Local<v8::Object>   results = Nan::New<v8::Object>();
  results->Set(Nan::New("didSucceed").ToLocalChecked(), Nan::False());

	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return results;
	}
	return TransferFileToDeviceV8(device.Get(),
		WPD_CONTENT_TYPE_UNSPECIFIED,
		deviceParentID,
		localFilePath,
	  results);
}


void DoGetFile(
	_In_ wchar_t* fileID)
{
	ComPtr<IPortableDevice> device;
	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return;
	}
	GetFileFromDevice(device.Get(), fileID);
}

v8::Local<v8::Object> DoGetFileV8(
	_In_ wchar_t* fileID)
{
	ComPtr<IPortableDevice> device;
	v8::Local<v8::Object>   results = Nan::New<v8::Object>();
  results->Set(Nan::New("didSucceed").ToLocalChecked(), Nan::False());

	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return results;
	}
	return GetFileFromDeviceV8(device.Get(), fileID, results);
}

void DoDeleteFile(
	_In_ wchar_t* fileID)
{
	ComPtr<IPortableDevice> device;
	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return;
	}
	DeleteFileFromDevice(device.Get(), fileID);
}

v8::Local<v8::Object> DoDeleteFileV8(
	_In_ wchar_t* fileID)
{
	ComPtr<IPortableDevice> device;
	v8::Local<v8::Object>   results = Nan::New<v8::Object>();
  results->Set(Nan::New("didSucceed").ToLocalChecked(), Nan::False());

	ChooseFirstLightPhone(&device);
	if (device == nullptr)
	{
		// No MTP device was found, so exit immediately.
		return results;
	}
	return DeleteFileFromDeviceV8(device.Get(), fileID, results);
}

int _cdecl wmain(int argc, _In_ wchar_t* argv[])
{
    // Enable the heap manager to terminate the process on heap error.
    HeapSetInformation(nullptr, HeapEnableTerminationOnCorruption, nullptr, 0);

    // Initialize COM for COINIT_MULTITHREADED
    HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    if (SUCCEEDED(hr))
    {
		if (argc > 1) {
			if (std::wcscmp(argv[1], L"detect") == 0)
			{
				DoDeviceList();
			}
			else if (wcscmp(argv[1], L"list") == 0) {
				DoContentList();
			}
			else if (wcscmp(argv[1], L"sendfile") == 0) {
				// mtplite sendfile oA C : \Users\SanctuVirtu\Desktop\Dev\happy - gilmore_400x400.jpg
				DoSendFile(argv[2], argv[3]);
			}
			else if (wcscmp(argv[1], L"getfile") == 0) {
				DoGetFile(argv[2]);
			}
			else if (wcscmp(argv[1], L"delfile") == 0) {
				DoDeleteFile(argv[2]);
			}
			else {
				wprintf(L"This command is unknown.");
			}
		}
		else {
			//DoMenu();
			wprintf(L"MtpLite for Windows: Please pass a command to this CLI:\n");
			wprintf(L"\n");
			wprintf(L"  detect\n");
			wprintf(L"  list\n");
			wprintf(L"  sendfile parentID local_file_path.txt\n");
			wprintf(L"  getfile fileID\n");
			wprintf(L"  delfile fileID\n");
		}
        // Uninitialize COM
        CoUninitialize();
    }
    return 0;
}
