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
	int* appId = (int*)data;
	data = data + 4;
	std::string data1 = data;
	android::sp<android::IBinder> binder = android::defaultServiceManager()->checkService(android::String16("vold")); 
	auto vold = android::interface_cast<android::os::IVold>(binder);
	vold->setupAppDir(data1, *appId);
	return 0;
}
