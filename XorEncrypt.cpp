#include <Windows.h>
#include <iostream>

VOID XorByiKeys(IN PBYTE payload, IN SIZE_T sShellcodeSize, IN BYTE bKey) {

	for (size_t i = 0; i < sShellcodeSize; i++) {

		payload[i] = payload[i] ^ (bKey + i);

		std::cout << payload[i];
	}

}

// مثال

/*int main() {
* 
*	
*	shellcode = نص البايلود
*	sizeof(shellcode) = حجم البايلود
*	(unsigned char)'P' = مفتاح التشفير ... غير P و حط مفتاح
* 
*	المفتاح يكون واحد بايت فقط !!!!! 'P', 'K', 'F', 'S', 0x90, 0x80, 0x50 
* 
	unsigned char shellcode[] = {"Hello World"};
	XorByiKeys(shellcode, sizeof(shellcode), (unsigned char)'P');
}*/