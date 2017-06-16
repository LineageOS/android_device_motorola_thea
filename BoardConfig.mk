#
# Copyright (C) 2015 The CyanogenMod Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

# inherit from common msm8226-common
-include device/motorola/msm8226-common/BoardConfigCommon.mk

DEVICE_PATH := device/motorola/thea

# Vendor Unification Init
TARGET_INIT_VENDOR_LIB := libinit_thea
TARGET_RECOVERY_DEVICE_MODULES := libinit_thea

# Assert
TARGET_OTA_ASSERT_DEVICE := thea,thea_umtsds,thea_ds,XT1072,XT1078,XT1079

# Kernel
TARGET_KERNEL_CONFIG := titan_defconfig

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 10444800
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 10526720
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 2097152000
BOARD_USERDATAIMAGE_PARTITION_SIZE := 5207080960
BOARD_CACHEIMAGE_FILE_SYSTEM_TYPE := ext4
BOARD_CACHEIMAGE_PARTITION_SIZE := 262144000

# Properties
TARGET_SYSTEM_PROP += $(DEVICE_PATH)/system.prop

# inherit from the proprietary version
-include vendor/motorola/thea/BoardConfigVendor.mk
