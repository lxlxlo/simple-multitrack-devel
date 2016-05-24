#include "msrp.h"

void cleanup(void) {
  if (AudioDeviceStop(audiodev, callback))
    perror("failed to stop audio device");
}


