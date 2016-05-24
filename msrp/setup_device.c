#include "msrp.h" 

void setup_device(void) {
	UInt32 size = sizeof(AudioDeviceID);
	if (AudioHardwareGetProperty(kAudioHardwarePropertyDefaultOutputDevice,
			       &size, &audiodev)) {
    		perror("Error selecting default audio device");
	}
}

