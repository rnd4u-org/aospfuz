#include <errno.h>
#include <fcntl.h>
#include <poll.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/un.h>

#include "android/os/IVold.h"

#include <android-base/logging.h>
#include <android-base/parseint.h>
#include <android-base/strings.h>
#include <android-base/stringprintf.h>
#include <binder/IServiceManager.h>
#include <binder/Status.h>

#include <private/android_filesystem_config.h>


extern "C" int LLVMFuzzerTestOneInput(const char* data, size_t size)
{
	int* data1 = (int*)data;
	data = data + 4;
	int* data2 = (int*)data;
	data = data + 4;
	std::string data3 = data;
	std::string data4 = data3.substr(data3.length()/2);
	data1 = data3.substr(0, data3.length()/2);
	android::sp<android::IBinder> binder = android::defaultServiceManager()->checkService(android::String16("vold")); 
	auto vold = android::interface_cast<android::os::IVold>(binder);
	vold->prepareSandboxForApp(data3, *data1, data4, *data2);
	return 0;
}

