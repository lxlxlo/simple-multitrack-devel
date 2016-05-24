#include "msrp.h"

void start_device(void) {
  if (AudioDeviceStart(audiodev, callback))
    perror("srp: AudioDeviceStart");

}

