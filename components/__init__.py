import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.components import sensor

AUTO_DALLAS_SENSOR = cg.constant("sensor.autodallas_sensor")

# Define the component configuration
def setup_autodallas_sensor(config):
    var = cg.new_Pvariable(config[CONF_PIN])
    cg.add(var.set_pin(config[CONF_PIN]))
    return var

# The sensor class must inherit from the proper base
class AutodallasSensor(sensor.Sensor):
    def __init__(self, pin):
        self.pin = pin

# Define the configuration
AUTODALLAS_SENSOR_SCHEMA = cv.Schema({
    cv.Required(CONF_PIN): cv.pin,
    cv.Optional(CONF_NAME, default="Water Temperature"): cv.string,
})

# Register the component with ESPHome
async def setup_autodallas_sensor_config(config):
    return setup_autodallas_sensor(config)
