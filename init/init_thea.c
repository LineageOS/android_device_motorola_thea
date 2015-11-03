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

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void gsm_properties(bool msim);
void cdma_properties(char cdma_sub[], char network[]);

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);

    property_set("ro.product.model", "Moto G 2014 LTE");

    if (ISMATCH(radio, "0x3")) {
        /* XT1072 */
        gsm_properties(false);
        property_set("ro.build.description", "thea_retgb-user 5.0.2 LXB22.99-24.7 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/thea_retgb/thea:5.0.2/LXB22.99-24.7/5:user/release-keys");
        property_set("ro.build.product", "thea");
        property_set("ro.mot.build.customerid", "retgball");
        property_set("ro.product.device", "thea");
   } else if (ISMATCH(radio, "0xE")) {
        /* XT1077 */
        cdma_properties("0", "10");
        property_set("ro.build.description", "thea_retcn_ds-user 5.0.2 LXB22.99-24.7 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/thea_retcn_ds/thea_ds:5.0.2/LXB22.99-24.7/5:user/release-keys");
        property_set("ro.build.product", "thea_ds");
        property_set("ro.mot.build.customerid", "retcn");
        property_set("ro.product.device", "thea_ds");
   } else if (ISMATCH(radio, "0xC")) {
        /* XT1078 */
        gsm_properties(true);
        property_set("ro.build.description", "thea_retbr_ds-user 5.0.2 LXB22.99-24.7 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/thea_retbr_ds/thea_umtsds:5.0.2/LXB22.99-24.7/5:user/release-keys");
        property_set("ro.build.product", "thea_umtsds");
        property_set("ro.mot.build.customerid", "netbr");
        property_set("ro.product.device", "thea_umtsds");
    } else if (ISMATCH(radio, "0xD")) {
        /* XT1079 */
        cdma_properties("0", "20");
        property_set("ro.build.description", "thea_retcn_ds-user 5.0.2 LXB22.99-24.7 15 release-keys");
        property_set("ro.build.fingerprint", "motorola/thea_retcn_ds/thea_ds:5.0.2/LXB22.99-24.7/5:user/release-keys");
        property_set("ro.build.product", "thea_ds");
        property_set("ro.com.android.dataroaming", "false");
        property_set("ro.mot.build.customerid", "retcn");
        property_set("ro.product.device", "thea_ds");
    }

    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found radio id %s setting build properties for %s device\n", radio, devicename);
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
    }
}

void cdma_properties(char cdma_sub[], char network[])
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
    property_set("telephony.lteOnCdmaDevice", "1");
}
