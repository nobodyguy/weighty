#ifndef WEIGHT_SERVICE_H__
#define WEIGHT_SERVICE_H__

#include <stdint.h>
#include "ble.h"
#include "ble_srv_common.h"

// Defining 16-bit service and 128-bit base UUIDs
#define BLE_UUID_OUR_BASE_UUID              {{ 0x23, 0xD1, 0x13, 0xEF, 0x5F, 0x78, 0x23, 0x15, 0xDE, 0xEF, 0x12, 0x12, 0x00, 0x00, 0x00, 0x00 }} // 128-bit base UUID
#define BLE_UUID_OUR_SERVICE_UUID           0xF00D // Just a random, but recognizable value

// Defining 16-bit characteristic UUID
#define BLE_UUID_OUR_CHARACTERISTC_UUID     0xBEEF // Just a random, but recognizable value

// This structure contains various status information for our service. 
typedef struct
{
    uint16_t                    conn_handle;    /**< Handle of the current connection (as provided by the BLE stack, is BLE_CONN_HANDLE_INVALID if not in a connection).*/
    uint16_t                    service_handle; /**< Handle of Our Service (as provided by the BLE stack). */
    ble_gatts_char_handles_t char_handles; /** handles for the characteristic attributes to our struct */
} ble_os_t;

/**@brief Function for handling BLE Stack events related to our service and characteristic.
 *
 * @details Handles all events from the BLE stack of interest to Our Service.
 *
 * @param[in]   p_weight_service       Weight Service structure.
 * @param[in]   p_ble_evt              Event received from the BLE stack.
 */
void ble_weight_service_on_ble_evt(ble_evt_t const * p_ble_evt, void * p_context);

/**@brief Function for initializing our new service.
 *
 * @param[in]   p_weight_service       Pointer to Weight Service structure.
 */
void weight_service_init(ble_os_t * p_weight_service);

/**@brief Function for updating and sending new characteristic values
 *
 * @details The application calls this function whenever our timer_timeout_handler triggers
 *
 * @param[in]   p_weight_service       Weight Service structure.
 * @param[in]   characteristic_value   New characteristic value.
 */
void weight_characteristic_update(ble_os_t *p_weight_service, int32_t *weight_value);

#endif  /* _ WEIGHT_SERVICE_H__ */
