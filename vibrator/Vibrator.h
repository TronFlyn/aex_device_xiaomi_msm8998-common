#ifndef ANDROID_HARDWARE_VIBRATOR_V1_0_VIBRATOR_H
#define ANDROID_HARDWARE_VIBRATOR_V1_0_VIBRATOR_H

#include <android/hardware/vibrator/1.0/IVibrator.h>
#include <hidl/Status.h>

namespace android {
namespace hardware {
namespace vibrator {
namespace V1_0 {
namespace implementation {

class Vibrator : public IVibrator {
public:
  Vibrator();

  Return<Status> on(uint32_t timeoutMs) override;
  Return<Status> off() override;
  Return<bool> supportsAmplitudeControl() override;
  Return<Status> setAmplitude(uint8_t amplitude) override;
  Return<void> perform(Effect effect, EffectStrength strength, perform_cb _hidl_cb) override;

private:
  uint32_t minVoltage;
  uint32_t maxVoltage;
};

}  // namespace implementation
}  // namespace V1_0
}  // namespace vibrator
}  // namespace hardware
}  // namespace android

#endif  // ANDROID_HARDWARE_VIBRATOR_V1_0_VIBRATOR_H
