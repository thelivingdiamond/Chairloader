V_XML_DEF = "Scripts/Entities/Vehicles/def_vehicle.xml"
V_SCRIPT_DIR = "Scripts/Entities/Vehicles/Implementations/"
V_XML_DIR = V_SCRIPT_DIR .. "Xml/"
HELPER_WORLD = 0
HELPER_LOCAL = 1
VehicleSystem = {}
if not VehicleSystem.VehicleImpls then
  VehicleSystem.VehicleImpls = Vehicle.GetVehicleImplementations(V_XML_DIR)
end
function ExposeVehicleToNetwork(A0_9433)
  Net.Expose({
    Class = A0_9433,
    ClientMethods = {},
    ServerMethods = {}
  })
end
function VehicleSystem.ReloadVehicleSystem()
  Log("Reloading VehicleSystem")
  Vehicle.ReloadSystem()
  Script.ReloadScript("Scripts/Entities/Vehicles/VehicleSystem.lua")
end
