#include "oemtabletaccelerometeradaptorplugin.h"
#include "oemtabletaccelerometeradaptor.h"
#include "sensormanager.h"
#include "logging.h"

void OemtabletAccelerometerAdaptorPlugin::Register(class Loader&)
{
    sensordLogD() << "registering oemtabletaccelerometeradaptor";
    SensorManager& sm = SensorManager::instance();
    sm.registerDeviceAdaptor<OemtabletAccelAdaptor>("accelerometeradaptor");
}
