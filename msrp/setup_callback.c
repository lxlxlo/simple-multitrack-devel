#include "msrp.h"

void setup_callback() {
  if (AudioDeviceAddIOProc(audiodev, callback, (void *) NULL))
    perror("AudioDeviceAddIOProc failed");
}


