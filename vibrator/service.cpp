#define LOG_TAG "android.hardware.vibrator@1.0-service.msm8998"

#include <hidl/HidlTransportSupport.h>

#include "Vibrator.h"

using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;

using android::hardware::vibrator::V1_0::IVibrator;
using android::hardware::vibrator::V1_0::implementation::Vibrator;

using android::OK;
using android::sp;
using android::status_t;

int main() {
    android::sp<IVibrator> vibrator = new Vibrator();

    configureRpcThreadpool(1, true);

    status_t status = vibrator->registerAsService();
    if (status != OK) {
        ALOGE("Cannot register Vibrator HAL service.");
        return 1;
    }

    ALOGI("Vibrator HAL service ready.");

    joinRpcThreadpool();

    ALOGI("Vibrator HAL service failed to join thread pool.");
    return 1;
}
