/**
 ******************************************************************************
 * @file    wifi_scan.c
 * @author  William Xu
 * @version V1.0.0
 * @date    21-May-2015
 * @brief   MiCO scan wifi hot spots demo
 ******************************************************************************
 *
 *  The MIT License
 *  Copyright (c) 2014 MXCHIP Inc.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is furnished
 *  to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR
 *  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 ******************************************************************************
 */

#include "mxos.h"

#define app_log(M, ...) MXOS_LOG(CONFIG_APP_DEBUG, "APP", M, ##__VA_ARGS__)

static void mxosNotify_ApListCallback( int num, mwifi_ap_info_t *ap_list)
{
    int i = 0;
    app_log("AP NUM:[%d]", num);
    for ( i = 0; i < num; i++ )
    {
        app_log("AP%d: name = %s  | rssi=%ddBm", i,ap_list[i].ssid, ap_list[i].rssi);

    }
}

int main( void )
{
    /* Start MiCO system functions according to mxos_config.h*/
    mxos_system_init( );

    /* Register user function when wlan scan is completed */
    mxos_system_notify_register( mxos_notify_WIFI_SCAN_COMPLETED, (void *) mxosNotify_ApListCallback, NULL );

    app_log("start scan mode, please wait...");

    mwifi_scan("MXCHIP");

    return kNoErr;
}

