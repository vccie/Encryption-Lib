#include <Windows.h>
#include <iostream>
#include <winternl.h>

typedef struct
{
	DWORD	Length;
	DWORD	MaximumLength;
	PVOID	Buffer;

} _USTRING;

typedef NTSTATUS(NTAPI* fnSystemFunction032)(
	struct USTRING* Data,
	struct USTRING* Key
	);

fnSystemFunction032 SystemFunction032 = (fnSystemFunction032)GetProcAddress(LoadLibraryA("Advapi32"), "SystemFunction032");

BOOL Rc4EncryptionViaSystemFunc032(IN PBYTE pRc4Key, IN PBYTE pPayloadData, IN DWORD dwRc4KeySize, IN DWORD sPayloadSize) {

	NTSTATUS STATUS	= NULL;

	_USTRING data, key;

	data.Buffer = pPayloadData;
	data.Length = sPayloadSize;
	data.MaximumLength = sPayloadSize;

	key.Buffer = pRc4Key;
	key.Length = dwRc4KeySize;
	key.MaximumLength = dwRc4KeySize;

	SystemFunction032(&reinterpret_cast<USTRING>(data), &reinterpret_cast<USTRING>(data));

	return TRUE;
}

// مثال

/*int main() {
*	unsigned char key[] = {0x6D, 0x61, 0x6C, 0x64, 0x65, 0x76, 0x31, 0x32, 0x33};
*	unsigned char data[] = {"hello world"}
*	SystemFunction032(key, data, sizeof(key), sizeof(data))
}*/