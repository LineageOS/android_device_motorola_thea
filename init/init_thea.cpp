/*
   Copyright (c) 2013, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

void gsm_properties(bool msim);
void cdma_properties(const char *cdma_sub, const char *network);

void property_override(char const prop[], char const value[])
{
    prop_info *pi;

    pi = (prop_info*) __system_property_find(prop);
    if (pi)
        __system_property_update(pi, value, strlen(value));
    else
        __system_property_add(prop, strlen(prop), value, strlen(value));
}

void vendor_load_properties()
{
    int rc;

    std::string platform = property_get("ro.board.platform");
    if (platform != ANDROID_TARGET)
        return;

    std::string radio = property_get("ro.boot.radio");

    property_override("ro.product.model", "Moto G 2014 LTE");

    if (radio == "0x3") {
        /* XT1072 */
        gsm_properties(false);
        property_override("ro.build.description", "thea_retgb-user 6.0 MPB24.65-34 31 release-keys");
        property_override("ro.build.fingerprint", "motorola/thea_retgb/thea:6.0/MPB24.65-34/31:user/release-keys");
        property_override("ro.build.product", "thea");
        property_set("ro.mot.build.customerid", "retgball");
        property_override("ro.product.device", "thea");
   } else if (radio == "0xE") {
        /* XT1077 */
        cdma_properties("0", "10");
        property_override("ro.build.description", "thea_retcn_ds-user 6.0 MPB24.65-34 31 release-keys");
        property_override("ro.build.fingerprint", "motorola/thea_retcn_ds/thea_ds:6.0/MPB24.65-34/31:user/release-keys");
        property_override("ro.build.product", "thea_ds");
        property_set("ro.mot.build.customerid", "retcn");
        property_override("ro.product.device", "thea_ds");
   } else if (radio == "0xC") {
        /* XT1078 */
        gsm_properties(true);
        property_override("ro.build.description", "thea_retbr_ds-user 6.0 MPB24.65-34 31 release-keys");
        property_override("ro.build.fingerprint", "motorola/thea_retbr_ds/thea_umtsds:6.0/MPB24.65-34/31:user/release-keys");
        property_override("ro.build.product", "thea_umtsds");
        property_set("ro.mot.build.customerid", "retbr");
        property_override("ro.product.device", "thea_umtsds");
    } else if (radio == "0xD") {
        /* XT1079 */
        cdma_properties("0", "20");
        property_override("ro.build.description", "thea_retcn_ds-user 6.0 MPB24.65-34 31 release-keys");
        property_override("ro.build.fingerprint", "motorola/thea_retcn_ds/thea_ds:6.0/MPB24.65-34/31:user/release-keys");
        property_override("ro.build.product", "thea_ds");
        property_set("ro.mot.build.customerid", "retcn");
        property_override("ro.product.device", "thea_ds");
    }

    std::string device = property_get("ro.product.device");
    INFO("Found radio id %s setting build properties for %s device\n", radio.c_str(), device.c_str());
}

void gsm_properties(bool msim)
{
    property_set("persist.radio.multisim.config", "");
    property_set("ro.telephony.default_network", "9");
    property_set("telephony.lteOnGsmDevice", "1");

    if (msim) {
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("persist.radio.plmn_name_cmp", "1");
        property_set("ro.telephony.ril.config", "simactivation,sim2gsmonly");
    }
}

void cdma_properties(const char *cdma_sub, const char *network)
{
    property_set("DEVICE_PROVISIONED", "1");
    property_set("persist.radio.dont_use_dsd", "true");
    property_set("persist.radio.multisim.config", "dsds");
    property_set("persist.radio.plmn_name_cmp", "1");
    property_set("ril.subscription.types", "NV,RUIM");
    property_set("ro.com.google.clientidbase", "android-motorola");
    property_set("ro.com.google.clientidbase.am", "android-motorola");
    property_set("ro.com.google.clientidbase.gmm", "android-motorola");
    property_set("ro.com.google.clientidbase.ms", "android-motorola");
    property_set("ro.com.google.clientidbase.yt", "android-motorola");
    property_set("ro.telephony.default_cdma_sub", cdma_sub);
    property_set("ro.telephony.default_network", network);
    property_set("ro.telephony.ril.config", "simactivation");
    property_set("telephony.lteOnCdmaDevice", "1");
}
