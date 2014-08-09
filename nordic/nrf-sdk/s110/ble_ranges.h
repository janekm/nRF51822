/*
  Copyright (c) 2012 Nordic Semiconductor. All Rights Reserved.

  The information contained herein is confidential property of Nordic Semiconductor. The use,
  copying, transfer or disclosure of such information is prohibited except by express written
  agreement with Nordic Semiconductor.
 */
/**
  @addtogroup BLE_COMMON
  @{
  @defgroup ble_ranges Module specific SVC and event number subranges
  @{

  @brief Definition of SVC and event number subranges for each API module.

  @note
  SVCs and event numbers are split into subranges for each API module.
  Each module receives its entire allocated range of SVC calls, whether implemented or not,
  but return BLE_ERROR_NOT_SUPPORTED for unimplemented or undefined calls in its range.

  Note that the symbols BLE_<module>_SVC_LAST is the end of the allocated SVC range,
  rather than the last SVC function call actually defined and implemented.

  Specific SVC and event values are defined in each module's ble_<module>.h file,
  which defines names of each individual SVC code based on the range start value.
*/

#ifndef BLE_RANGES_H__
#define BLE_RANGES_H__

#define BLE_SVC_BASE           0x60
    #define SD_BLE_ENABLE              0x60 /**< Enable and initialize the BLE stack */
    #define SD_BLE_EVT_GET             0x61 /**< Get an event from the pending events queue. */
    #define SD_BLE_TX_BUFFER_COUNT_GET 0x62 /**< Get the total number of available application transmission buffers from the stack. */
    #define SD_BLE_UUID_VS_ADD         0x63 /**< Add a Vendor Specific UUID. */
    #define SD_BLE_UUID_DECODE         0x64 /**< Decode UUID bytes. */
    #define SD_BLE_UUID_ENCODE         0x65 /**< Encode UUID bytes. */
    #define SD_BLE_VERSION_GET         0x66 /**< Get the local version information (company id, Link Layer Version, Link Layer Subversion). */
    #define SD_BLE_USER_MEM_REPLY      0x67 /**< User Memory Reply. */
    #define SD_BLE_OPT_SET             0x68 /**< Set a BLE option. */
    #define SD_BLE_OPT_GET             0x69 /**< Get a BLE option. */
#define BLE_SVC_LAST           0x6B       /* Total: 12. */

#define BLE_RESERVED_SVC_BASE  0x6C
#define BLE_RESERVED_SVC_LAST  0x6F       /* Total: 4. */

#define BLE_GAP_SVC_BASE              0x70
    #define SD_BLE_GAP_ADDRESS_SET        0x70   /**< Set own Bluetooth Address. */
    #define SD_BLE_GAP_ADDRESS_GET        0x71   /**< Get own Bluetooth Address. */
    #define SD_BLE_GAP_ADV_DATA_SET       0x72   /**< Set Advertisement Data. */
    #define SD_BLE_GAP_ADV_START          0x73   /**< Start Advertising. */
    #define SD_BLE_GAP_ADV_STOP           0x74   /**< Stop Advertising. */
    #define SD_BLE_GAP_CONN_PARAM_UPDATE  0x75   /**< Connection Parameter Update. */
    #define SD_BLE_GAP_DISCONNECT         0x76   /**< Disconnect. */
    #define SD_BLE_GAP_TX_POWER_SET       0x77   /**< Set TX Power. */
    #define SD_BLE_GAP_APPEARANCE_SET     0x78   /**< Set Appearance. */
    #define SD_BLE_GAP_APPEARANCE_GET     0x79   /**< Get Appearance. */
    #define SD_BLE_GAP_PPCP_SET           0x7A   /**< Set PPCP. */
    #define SD_BLE_GAP_PPCP_GET           0x7B   /**< Get PPCP. */
    #define SD_BLE_GAP_DEVICE_NAME_SET    0x7C   /**< Set Device Name. */
    #define SD_BLE_GAP_DEVICE_NAME_GET    0x7D   /**< Get Device Name. */
    #define SD_BLE_GAP_AUTHENTICATE       0x7E   /**< Initiate Pairing/Bonding. */
    #define SD_BLE_GAP_SEC_PARAMS_REPLY   0x7F   /**< Reply with Security Parameters. */
    #define SD_BLE_GAP_AUTH_KEY_REPLY     0x80   /**< Reply with an authentication key. */
    #define SD_BLE_GAP_SEC_INFO_REPLY     0x81   /**< Reply with Security Information. */
    #define SD_BLE_GAP_CONN_SEC_GET       0x82   /**< Obtain connection security level. */
    #define SD_BLE_GAP_RSSI_START         0x83   /**< Start reporting of changes in RSSI. */
    #define SD_BLE_GAP_RSSI_STOP          0x84   /**< Stop reporting of changes in RSSI. */
#define BLE_GAP_SVC_LAST              0x8F   /* Total: 32. */

#define BLE_GATTC_SVC_BASE     0x90
#define BLE_GATTC_SVC_LAST     0x9F       /* Total: 16. */

#define BLE_GATTS_SVC_BASE     0xA0
    #define SD_BLE_GATTS_SERVICE_ADD        0xA0 /**< Add a service. */
    #define SD_BLE_GATTS_INCLUDE_ADD        0xA1 /**< Add an included service. */
    #define SD_BLE_GATTS_CHARACTERISTIC_ADD 0xA2 /**< Add a characteristic. */
    #define SD_BLE_GATTS_DESCRIPTOR_ADD     0xA3 /**< Add a generic attribute. */
    #define SD_BLE_GATTS_VALUE_SET          0xA4 /**< Set an attribute value. */
    #define SD_BLE_GATTS_VALUE_GET          0xA5 /**< Get an attribute value. */
    #define SD_BLE_GATTS_HVX                0xA6 /**< Handle Value Notification or Indication. */
    #define SD_BLE_GATTS_SERVICE_CHANGED    0xA7 /**< Perform a Service Changed Indication to one or more peers. */
    #define SD_BLE_GATTS_RW_AUTHORIZE_REPLY 0xA8 /**< Reply to an authorization request for a read or write operation on one or
                                                  *   more attributes.*/
    #define SD_BLE_GATTS_SYS_ATTR_SET       0xA9 /**< Set the persistent system attributes for a connection. */
    #define SD_BLE_GATTS_SYS_ATTR_GET       0xAA /**< Get updated persistent system attributes after terminating a connection. */
#define BLE_GATTS_SVC_LAST     0xAF       /* Total: 16. */

#define BLE_L2CAP_SVC_BASE     0xB0
    #define SD_BLE_L2CAP_CID_REGISTER   BLE_L2CAP_SVC_BASE  /**< Register a CID. */
    #define SD_BLE_L2CAP_CID_UNREGISTER 0xB1                /**< Unregister a CID. */
    #define SD_BLE_L2CAP_TX             0xB2                /**< Transmit a packet. */
#define BLE_L2CAP_SVC_LAST     0xBF       /* Total: 16. */


#define BLE_EVT_INVALID        0x00

#define BLE_EVT_BASE           0x01
#define BLE_EVT_LAST           0x0F       /* Total: 15. */

#define BLE_GAP_EVT_BASE       0x10
#define BLE_GAP_EVT_LAST       0x2F       /* Total: 32. */

#define BLE_GATTC_EVT_BASE     0x30
#define BLE_GATTC_EVT_LAST     0x4F       /* Total: 32. */

#define BLE_GATTS_EVT_BASE     0x50
#define BLE_GATTS_EVT_LAST     0x6F       /* Total: 32. */

#define BLE_L2CAP_EVT_BASE     0x70
#define BLE_L2CAP_EVT_LAST     0x8F       /* Total: 32.  */

#define BLE_OPT_INVALID        0x00       /**< Invalid BLE Option. */

#define BLE_OPT_BASE           0x01       /**< Common BLE Option base. */
#define BLE_OPT_LAST           0x1F       /**< Total: 31. */

#define BLE_GAP_OPT_BASE       0x20       /**< GAP BLE Option base. */
#define BLE_GAP_OPT_LAST       0x3F       /**< Total: 32. */

#define BLE_GATTC_OPT_BASE     0x40       /**< GATTC BLE Option base. */
#define BLE_GATTC_OPT_LAST     0x5F       /**< Total: 32. */

#define BLE_GATTS_OPT_BASE     0x60       /**< GATTS BLE Option base. */
#define BLE_GATTS_OPT_LAST     0x7F       /**< Total: 32. */

#define BLE_L2CAP_OPT_BASE     0x80       /**< L2CAP BLE Option base. */
#define BLE_L2CAP_OPT_LAST     0x9F       /**< Total: 32.  */

#endif /* BLE_RANGES_H__ */

/**
  @}
  @}
*/
