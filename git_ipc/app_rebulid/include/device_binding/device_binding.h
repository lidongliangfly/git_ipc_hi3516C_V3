#ifndef GIT_IPC_DEVICE_BINDING_H
#define GIT_IPC_DEVICE_BINDING_H


/**
 * 用于设备绑定时受到数据后的回调函数
 *
 * @param ssid      wifi名称
 * @param ssid      wifi密码
 * @param ssid      wifi安全模式
 * @param ssid      access toekn
 *
 * @return 0, OK; -1 fail
 */
typedef int (*DEV_BIND_CB_on_recved_data)(char *ssid,
                                          char *pass,
                                          char *wifi_mode,
                                          char *token);

typedef struct devNearAP {

    /// 鐑偣鍚嶇О銆�
    char ssid[64];

    /// -100 - 0
    int rssi;

    /// bssid
    char bssid[20];

    /// 鍔犲瘑鏂瑰紡
    char encrytype[48];

} stDEV_NEAR_AP, *lpDEV_NEAR_AP;

typedef void (*DEV_BIND_get_near_ap)(lpDEV_NEAR_AP lpAPs, unsigned int *nAPs);

/**
 * 开启设备绑定功能。 on_recved_data 回调函数必须要按接口实现。
 *
 * @return 0, OK; -1 fail
 */
int DEV_BIND_start(DEV_BIND_CB_on_recved_data on_recved_data, DEV_BIND_get_near_ap get_near_ap);

/**
 * 在需要的时候，提前中断绑定过程
 *
 * @return 0, OK; -1 fail
 */
int DEV_BIND_interrupt();


#endif //GIT_IPC_DEVICE_BINDING_H
