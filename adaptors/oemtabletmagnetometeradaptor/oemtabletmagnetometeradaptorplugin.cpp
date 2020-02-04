#include "oemtabletmagnetometeradaptorplugin.h"
#include "oemtabletmagnetometeradaptor.h"
#include "sensormanager.h"

void OemtabletMagnetometerAdaptorPlugin::Register(class Loader&)
{
    sensordLogD() << "registering OemtabletMagnetometerAdaptor";
    SensorManager& sm = SensorManager::instance();
    sm.registerDeviceAdaptor<OemtabletMagnetometerAdaptor>("magnetometeradaptor");
}
