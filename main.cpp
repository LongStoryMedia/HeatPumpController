#include "pigpio.h"
#include "../lib/therm.h"
#include "../lib/HttpRequest.h"

int i2cHandle;
therm_s therm;
volatile bool waterHeaterSwitch;
volatile bool heatPumpSwitch;

int main(void)
{
    // make http request to api and deserialize config into struct
    gpioInitialise();

    i2cHandle = i2cOpen(1, 0x08, 0);
    while (1)
    {
        if (i2cReadDevice(i2cHandle, (char *)&therm, sizeof(therm)) == sizeof(therm))
        {
        }
    }

    i2cClose(i2cHandle);
    gpioTerminate();
    return 0;
}