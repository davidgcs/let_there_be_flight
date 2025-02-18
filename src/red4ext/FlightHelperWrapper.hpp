#pragma once

#include "FlightHelper.hpp"
#include <RED4ext/Addresses.hpp>
#include <RED4ext/DynArray.hpp>
#include <RED4ext/ISerializable.hpp>
#include <RED4ext/RED4ext.hpp>
#include <RED4ext/RTTITypes.hpp>
#include <RED4ext/Relocation.hpp>
#include <RED4ext/Scripting/Natives/vehiclePhysicsData.hpp>
#include <RED4ext/Scripting/Natives/Generated/vehicle/BaseObject.hpp>
#include "FlightModule.hpp"

namespace vehicle {
namespace flight {

struct Helper;

struct HelperWrapper : RED4ext::IScriptable {
  virtual RED4ext::CClass *GetNativeType();

  Helper *helper;
  RED4ext::Vector4 force;
  RED4ext::Vector4 torque;
};
RED4EXT_ASSERT_SIZE(HelperWrapper, 0x68);
RED4EXT_ASSERT_OFFSET(HelperWrapper, force, 0x48);
RED4EXT_ASSERT_OFFSET(HelperWrapper, torque, 0x58);

struct HelperWrapperModule : FlightModule {
  void RegisterTypes();
  void PostRegisterTypes();
};
//char (*__kaboom)[sizeof(HelperWrapper)] = 1;

} // namespace flight
} // namespace vehicle