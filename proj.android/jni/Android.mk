LOCAL_PATH := $(call my-dir)

-APP_STL := gnustl_static
+APP_STL := c++_static
+NDK_TOOLCHAIN_VERSION=clang

include $(CLEAR_VARS)

$(call import-add-path,$(LOCAL_PATH)/../../cocos2d)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/external)
$(call import-add-path,$(LOCAL_PATH)/../../cocos2d/cocos)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

FILE_LIST := $(wildcard $(LOCAL_PATH)/../../Classes/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Character/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Edit/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Layer/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/StageMap/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/StageMap/ColorChange/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Edit/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain/Sequence/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Result/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/Scene/Title/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Game/UI/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Action/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Action/Follow/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Animation/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Camera/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/CocosAssistant/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/FileIO/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Math/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Modal/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Particle/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/SceneSupport/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Template/*.cpp)
FILE_LIST += $(wildcard $(LOCAL_PATH)/../../Classes/Utility/Timer/*.cpp)


LOCAL_SRC_FILES := hellocpp/main.cpp
LOCAL_SRC_FILES += $(FILE_LIST:$(LOCAL_PATH)/%=%)

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Character
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Edit
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Layer
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/StageMap
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Object/StageObject/StageMap/ColorChange
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Edit
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/GameMain/Sequence
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Result
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/Title
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Game/Scene/UI
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Action
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Action/Follow
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Animation
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Camera
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/CocosAssistant
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/FileIO
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Math
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Modal
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Particle
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/SceneSupport
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Template
LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/Utility/Timer

LOCAL_WHOLE_STATIC_LIBRARIES := cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static

# LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocosbuilder_static
# LOCAL_WHOLE_STATIC_LIBRARIES += spine_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocostudio_static
# LOCAL_WHOLE_STATIC_LIBRARIES += cocos_network_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,.)
$(call import-module,audio/android)

# $(call import-module,Box2D)
# $(call import-module,editor-support/cocosbuilder)
# $(call import-module,editor-support/spine)
# $(call import-module,editor-support/cocostudio)
# $(call import-module,network)
$(call import-module,extensions)
