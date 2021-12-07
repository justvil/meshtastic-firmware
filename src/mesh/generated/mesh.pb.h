/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.4 */

#ifndef PB_MESH_PB_H_INCLUDED
#define PB_MESH_PB_H_INCLUDED
#include <pb.h>
#include "portnums.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _HardwareModel {
    HardwareModel_UNSET = 0,
    HardwareModel_TLORA_V2 = 1,
    HardwareModel_TLORA_V1 = 2,
    HardwareModel_TLORA_V2_1_1p6 = 3,
    HardwareModel_TBEAM = 4,
    HardwareModel_HELTEC_V2_0 = 5,
    HardwareModel_TBEAM0p7 = 6,
    HardwareModel_T_ECHO = 7,
    HardwareModel_TLORA_V1_1p3 = 8,
    HardwareModel_RAK4631 = 9,
    HardwareModel_HELTEC_V2_1 = 10,
    HardwareModel_LORA_RELAY_V1 = 32,
    HardwareModel_NRF52840DK = 33,
    HardwareModel_PPR = 34,
    HardwareModel_GENIEBLOCKS = 35,
    HardwareModel_NRF52_UNKNOWN = 36,
    HardwareModel_PORTDUINO = 37,
    HardwareModel_ANDROID_SIM = 38,
    HardwareModel_DIY_V1 = 39
} HardwareModel;

typedef enum _Team {
    Team_CLEAR = 0,
    Team_CYAN = 1,
    Team_WHITE = 2,
    Team_YELLOW = 3,
    Team_ORANGE = 4,
    Team_MAGENTA = 5,
    Team_RED = 6,
    Team_MAROON = 7,
    Team_PURPLE = 8,
    Team_DARK_BLUE = 9,
    Team_BLUE = 10,
    Team_TEAL = 11,
    Team_GREEN = 12,
    Team_DARK_GREEN = 13,
    Team_BROWN = 14
} Team;

typedef enum _Constants {
    Constants_Unused = 0,
    Constants_DATA_PAYLOAD_LEN = 237
} Constants;

typedef enum _CriticalErrorCode {
    CriticalErrorCode_None = 0,
    CriticalErrorCode_TxWatchdog = 1,
    CriticalErrorCode_SleepEnterWait = 2,
    CriticalErrorCode_NoRadio = 3,
    CriticalErrorCode_Unspecified = 4,
    CriticalErrorCode_UBloxInitFailed = 5,
    CriticalErrorCode_NoAXP192 = 6,
    CriticalErrorCode_InvalidRadioSetting = 7,
    CriticalErrorCode_TransmitFailed = 8,
    CriticalErrorCode_Brownout = 9,
    CriticalErrorCode_SX1262Failure = 10,
    CriticalErrorCode_RadioSpiBug = 11
} CriticalErrorCode;

typedef enum _Position_LocSource {
    Position_LocSource_LOCSRC_UNSPECIFIED = 0,
    Position_LocSource_LOCSRC_MANUAL_ENTRY = 1,
    Position_LocSource_LOCSRC_GPS_INTERNAL = 2,
    Position_LocSource_LOCSRC_GPS_EXTERNAL = 3
} Position_LocSource;

typedef enum _Position_AltSource {
    Position_AltSource_ALTSRC_UNSPECIFIED = 0,
    Position_AltSource_ALTSRC_MANUAL_ENTRY = 1,
    Position_AltSource_ALTSRC_GPS_INTERNAL = 2,
    Position_AltSource_ALTSRC_GPS_EXTERNAL = 3,
    Position_AltSource_ALTSRC_BAROMETRIC = 4
} Position_AltSource;

typedef enum _Routing_Error {
    Routing_Error_NONE = 0,
    Routing_Error_NO_ROUTE = 1,
    Routing_Error_GOT_NAK = 2,
    Routing_Error_TIMEOUT = 3,
    Routing_Error_NO_INTERFACE = 4,
    Routing_Error_MAX_RETRANSMIT = 5,
    Routing_Error_NO_CHANNEL = 6,
    Routing_Error_TOO_LARGE = 7,
    Routing_Error_NO_RESPONSE = 8,
    Routing_Error_BAD_REQUEST = 32,
    Routing_Error_NOT_AUTHORIZED = 33
} Routing_Error;

typedef enum _MeshPacket_Priority {
    MeshPacket_Priority_UNSET = 0,
    MeshPacket_Priority_MIN = 1,
    MeshPacket_Priority_BACKGROUND = 10,
    MeshPacket_Priority_DEFAULT = 64,
    MeshPacket_Priority_RELIABLE = 70,
    MeshPacket_Priority_ACK = 120,
    MeshPacket_Priority_MAX = 127
} MeshPacket_Priority;

typedef enum _LogRecord_Level {
    LogRecord_Level_UNSET = 0,
    LogRecord_Level_CRITICAL = 50,
    LogRecord_Level_ERROR = 40,
    LogRecord_Level_WARNING = 30,
    LogRecord_Level_INFO = 20,
    LogRecord_Level_DEBUG = 10,
    LogRecord_Level_TRACE = 5
} LogRecord_Level;

/* Struct definitions */
typedef PB_BYTES_ARRAY_T(237) Data_payload_t;
typedef struct _Data {
    PortNum portnum;
    Data_payload_t payload;
    bool want_response;
    uint32_t dest;
    uint32_t source;
    uint32_t request_id;
} Data;

typedef struct _LogRecord {
    char message[64];
    uint32_t time;
    char source[8];
    LogRecord_Level level;
} LogRecord;

typedef struct _MyNodeInfo {
    uint32_t my_node_num;
    bool has_gps;
    uint32_t num_bands;
    char region[12];
    char hw_model_deprecated[16];
    char firmware_version[18];
    CriticalErrorCode error_code;
    uint32_t error_address;
    uint32_t error_count;
    uint32_t reboot_count;
    float bitrate;
    uint32_t message_timeout_msec;
    uint32_t min_app_version;
    uint32_t max_channels;
    pb_callback_t air_period_tx;
    pb_callback_t air_period_rx;
    pb_callback_t air_period_tx_all;
} MyNodeInfo;

typedef struct _Position {
    int32_t latitude_i;
    int32_t longitude_i;
    int32_t altitude;
    int32_t battery_level;
    uint32_t time;
    Position_LocSource location_source;
    Position_AltSource altitude_source;
    uint32_t pos_timestamp;
    int32_t pos_time_millis;
    int32_t altitude_hae;
    int32_t alt_geoid_sep;
    uint32_t PDOP;
    uint32_t HDOP;
    uint32_t VDOP;
    uint32_t gps_accuracy;
    uint32_t ground_speed;
    uint32_t ground_track;
    uint32_t fix_quality;
    uint32_t fix_type;
    uint32_t sats_in_view;
    uint32_t sensor_id;
    uint32_t pos_next_update;
    uint32_t pos_seq_number;
} Position;

typedef struct _RouteDiscovery {
    pb_size_t route_count;
    uint32_t route[8];
} RouteDiscovery;

typedef struct _ToRadio_PeerInfo {
    uint32_t app_version;
    bool mqtt_gateway;
} ToRadio_PeerInfo;

typedef struct _User {
    char id[16];
    char long_name[40];
    char short_name[5];
    pb_byte_t macaddr[6];
    HardwareModel hw_model;
    bool is_licensed;
    Team team;
    uint32_t tx_power_dbm;
    uint32_t ant_gain_dbi;
    uint32_t ant_azimuth;
} User;

typedef PB_BYTES_ARRAY_T(256) MeshPacket_encrypted_t;
typedef struct _MeshPacket {
    uint32_t from;
    uint32_t to;
    uint8_t channel;
    pb_size_t which_payloadVariant;
    union {
        Data decoded;
        MeshPacket_encrypted_t encrypted;
    };
    uint32_t id;
    uint32_t rx_time;
    float rx_snr;
    uint8_t hop_limit;
    bool want_ack;
    MeshPacket_Priority priority;
    int32_t rx_rssi;
} MeshPacket;

typedef struct _NodeInfo {
    uint32_t num;
    bool has_user;
    User user;
    bool has_position;
    Position position;
    uint32_t last_heard;
    float snr;
} NodeInfo;

typedef struct _Routing {
    pb_size_t which_variant;
    union {
        RouteDiscovery route_request;
        RouteDiscovery route_reply;
        Routing_Error error_reason;
    };
} Routing;

typedef struct _FromRadio {
    uint32_t num;
    pb_size_t which_payloadVariant;
    union {
        MyNodeInfo my_info;
        NodeInfo node_info;
        LogRecord log_record;
        uint32_t config_complete_id;
        bool rebooted;
        MeshPacket packet;
    };
} FromRadio;

typedef struct _ToRadio {
    pb_size_t which_payloadVariant;
    union {
        MeshPacket packet;
        ToRadio_PeerInfo peer_info;
        uint32_t want_config_id;
        bool disconnect;
    };
} ToRadio;


/* Helper constants for enums */
#define _HardwareModel_MIN HardwareModel_UNSET
#define _HardwareModel_MAX HardwareModel_DIY_V1
#define _HardwareModel_ARRAYSIZE ((HardwareModel)(HardwareModel_DIY_V1+1))

#define _Team_MIN Team_CLEAR
#define _Team_MAX Team_BROWN
#define _Team_ARRAYSIZE ((Team)(Team_BROWN+1))

#define _Constants_MIN Constants_Unused
#define _Constants_MAX Constants_DATA_PAYLOAD_LEN
#define _Constants_ARRAYSIZE ((Constants)(Constants_DATA_PAYLOAD_LEN+1))

#define _CriticalErrorCode_MIN CriticalErrorCode_None
#define _CriticalErrorCode_MAX CriticalErrorCode_RadioSpiBug
#define _CriticalErrorCode_ARRAYSIZE ((CriticalErrorCode)(CriticalErrorCode_RadioSpiBug+1))

#define _Position_LocSource_MIN Position_LocSource_LOCSRC_UNSPECIFIED
#define _Position_LocSource_MAX Position_LocSource_LOCSRC_GPS_EXTERNAL
#define _Position_LocSource_ARRAYSIZE ((Position_LocSource)(Position_LocSource_LOCSRC_GPS_EXTERNAL+1))

#define _Position_AltSource_MIN Position_AltSource_ALTSRC_UNSPECIFIED
#define _Position_AltSource_MAX Position_AltSource_ALTSRC_BAROMETRIC
#define _Position_AltSource_ARRAYSIZE ((Position_AltSource)(Position_AltSource_ALTSRC_BAROMETRIC+1))

#define _Routing_Error_MIN Routing_Error_NONE
#define _Routing_Error_MAX Routing_Error_NOT_AUTHORIZED
#define _Routing_Error_ARRAYSIZE ((Routing_Error)(Routing_Error_NOT_AUTHORIZED+1))

#define _MeshPacket_Priority_MIN MeshPacket_Priority_UNSET
#define _MeshPacket_Priority_MAX MeshPacket_Priority_MAX
#define _MeshPacket_Priority_ARRAYSIZE ((MeshPacket_Priority)(MeshPacket_Priority_MAX+1))

#define _LogRecord_Level_MIN LogRecord_Level_UNSET
#define _LogRecord_Level_MAX LogRecord_Level_CRITICAL
#define _LogRecord_Level_ARRAYSIZE ((LogRecord_Level)(LogRecord_Level_CRITICAL+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define Position_init_default                    {0, 0, 0, 0, 0, _Position_LocSource_MIN, _Position_AltSource_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define User_init_default                        {"", "", "", {0}, _HardwareModel_MIN, 0, _Team_MIN, 0, 0, 0}
#define RouteDiscovery_init_default              {0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define Routing_init_default                     {0, {RouteDiscovery_init_default}}
#define Data_init_default                        {_PortNum_MIN, {0, {0}}, 0, 0, 0, 0}
#define MeshPacket_init_default                  {0, 0, 0, 0, {Data_init_default}, 0, 0, 0, 0, 0, _MeshPacket_Priority_MIN, 0}
#define NodeInfo_init_default                    {0, false, User_init_default, false, Position_init_default, 0, 0}
#define MyNodeInfo_init_default                  {0, 0, 0, "", "", "", _CriticalErrorCode_MIN, 0, 0, 0, 0, 0, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define LogRecord_init_default                   {"", 0, "", _LogRecord_Level_MIN}
#define FromRadio_init_default                   {0, 0, {MyNodeInfo_init_default}}
#define ToRadio_init_default                     {0, {MeshPacket_init_default}}
#define ToRadio_PeerInfo_init_default            {0, 0}
#define Position_init_zero                       {0, 0, 0, 0, 0, _Position_LocSource_MIN, _Position_AltSource_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define User_init_zero                           {"", "", "", {0}, _HardwareModel_MIN, 0, _Team_MIN, 0, 0, 0}
#define RouteDiscovery_init_zero                 {0, {0, 0, 0, 0, 0, 0, 0, 0}}
#define Routing_init_zero                        {0, {RouteDiscovery_init_zero}}
#define Data_init_zero                           {_PortNum_MIN, {0, {0}}, 0, 0, 0, 0}
#define MeshPacket_init_zero                     {0, 0, 0, 0, {Data_init_zero}, 0, 0, 0, 0, 0, _MeshPacket_Priority_MIN, 0}
#define NodeInfo_init_zero                       {0, false, User_init_zero, false, Position_init_zero, 0, 0}
#define MyNodeInfo_init_zero                     {0, 0, 0, "", "", "", _CriticalErrorCode_MIN, 0, 0, 0, 0, 0, 0, 0, {{NULL}, NULL}, {{NULL}, NULL}, {{NULL}, NULL}}
#define LogRecord_init_zero                      {"", 0, "", _LogRecord_Level_MIN}
#define FromRadio_init_zero                      {0, 0, {MyNodeInfo_init_zero}}
#define ToRadio_init_zero                        {0, {MeshPacket_init_zero}}
#define ToRadio_PeerInfo_init_zero               {0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define Data_portnum_tag                         1
#define Data_payload_tag                         2
#define Data_want_response_tag                   3
#define Data_dest_tag                            4
#define Data_source_tag                          5
#define Data_request_id_tag                      6
#define LogRecord_message_tag                    1
#define LogRecord_time_tag                       2
#define LogRecord_source_tag                     3
#define LogRecord_level_tag                      4
#define MyNodeInfo_my_node_num_tag               1
#define MyNodeInfo_has_gps_tag                   2
#define MyNodeInfo_num_bands_tag                 3
#define MyNodeInfo_region_tag                    4
#define MyNodeInfo_hw_model_deprecated_tag       5
#define MyNodeInfo_firmware_version_tag          6
#define MyNodeInfo_error_code_tag                7
#define MyNodeInfo_error_address_tag             8
#define MyNodeInfo_error_count_tag               9
#define MyNodeInfo_reboot_count_tag              10
#define MyNodeInfo_bitrate_tag                   11
#define MyNodeInfo_message_timeout_msec_tag      13
#define MyNodeInfo_min_app_version_tag           14
#define MyNodeInfo_max_channels_tag              15
#define MyNodeInfo_air_period_tx_tag             16
#define MyNodeInfo_air_period_rx_tag             17
#define MyNodeInfo_air_period_tx_all_tag         18
#define Position_latitude_i_tag                  1
#define Position_longitude_i_tag                 2
#define Position_altitude_tag                    3
#define Position_battery_level_tag               4
#define Position_time_tag                        9
#define Position_location_source_tag             10
#define Position_altitude_source_tag             11
#define Position_pos_timestamp_tag               12
#define Position_pos_time_millis_tag             13
#define Position_altitude_hae_tag                14
#define Position_alt_geoid_sep_tag               15
#define Position_PDOP_tag                        16
#define Position_HDOP_tag                        17
#define Position_VDOP_tag                        18
#define Position_gps_accuracy_tag                19
#define Position_ground_speed_tag                20
#define Position_ground_track_tag                21
#define Position_fix_quality_tag                 22
#define Position_fix_type_tag                    23
#define Position_sats_in_view_tag                24
#define Position_sensor_id_tag                   25
#define Position_pos_next_update_tag             40
#define Position_pos_seq_number_tag              41
#define RouteDiscovery_route_tag                 2
#define ToRadio_PeerInfo_app_version_tag         1
#define ToRadio_PeerInfo_mqtt_gateway_tag        2
#define User_id_tag                              1
#define User_long_name_tag                       2
#define User_short_name_tag                      3
#define User_macaddr_tag                         4
#define User_hw_model_tag                        6
#define User_is_licensed_tag                     7
#define User_team_tag                            8
#define User_tx_power_dbm_tag                    10
#define User_ant_gain_dbi_tag                    11
#define User_ant_azimuth_tag                     12
#define MeshPacket_from_tag                      1
#define MeshPacket_to_tag                        2
#define MeshPacket_channel_tag                   3
#define MeshPacket_decoded_tag                   4
#define MeshPacket_encrypted_tag                 5
#define MeshPacket_id_tag                        6
#define MeshPacket_rx_time_tag                   7
#define MeshPacket_rx_snr_tag                    8
#define MeshPacket_hop_limit_tag                 10
#define MeshPacket_want_ack_tag                  11
#define MeshPacket_priority_tag                  12
#define MeshPacket_rx_rssi_tag                   13
#define NodeInfo_num_tag                         1
#define NodeInfo_user_tag                        2
#define NodeInfo_position_tag                    3
#define NodeInfo_last_heard_tag                  4
#define NodeInfo_snr_tag                         7
#define Routing_route_request_tag                1
#define Routing_route_reply_tag                  2
#define Routing_error_reason_tag                 3
#define FromRadio_num_tag                        1
#define FromRadio_my_info_tag                    3
#define FromRadio_node_info_tag                  4
#define FromRadio_log_record_tag                 7
#define FromRadio_config_complete_id_tag         8
#define FromRadio_rebooted_tag                   9
#define FromRadio_packet_tag                     11
#define ToRadio_packet_tag                       2
#define ToRadio_peer_info_tag                    3
#define ToRadio_want_config_id_tag               100
#define ToRadio_disconnect_tag                   104

/* Struct field encoding specification for nanopb */
#define Position_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, SFIXED32, latitude_i,        1) \
X(a, STATIC,   SINGULAR, SFIXED32, longitude_i,       2) \
X(a, STATIC,   SINGULAR, INT32,    altitude,          3) \
X(a, STATIC,   SINGULAR, INT32,    battery_level,     4) \
X(a, STATIC,   SINGULAR, FIXED32,  time,              9) \
X(a, STATIC,   SINGULAR, UENUM,    location_source,  10) \
X(a, STATIC,   SINGULAR, UENUM,    altitude_source,  11) \
X(a, STATIC,   SINGULAR, FIXED32,  pos_timestamp,    12) \
X(a, STATIC,   SINGULAR, INT32,    pos_time_millis,  13) \
X(a, STATIC,   SINGULAR, SINT32,   altitude_hae,     14) \
X(a, STATIC,   SINGULAR, SINT32,   alt_geoid_sep,    15) \
X(a, STATIC,   SINGULAR, UINT32,   PDOP,             16) \
X(a, STATIC,   SINGULAR, UINT32,   HDOP,             17) \
X(a, STATIC,   SINGULAR, UINT32,   VDOP,             18) \
X(a, STATIC,   SINGULAR, UINT32,   gps_accuracy,     19) \
X(a, STATIC,   SINGULAR, UINT32,   ground_speed,     20) \
X(a, STATIC,   SINGULAR, UINT32,   ground_track,     21) \
X(a, STATIC,   SINGULAR, UINT32,   fix_quality,      22) \
X(a, STATIC,   SINGULAR, UINT32,   fix_type,         23) \
X(a, STATIC,   SINGULAR, UINT32,   sats_in_view,     24) \
X(a, STATIC,   SINGULAR, UINT32,   sensor_id,        25) \
X(a, STATIC,   SINGULAR, UINT32,   pos_next_update,  40) \
X(a, STATIC,   SINGULAR, UINT32,   pos_seq_number,   41)
#define Position_CALLBACK NULL
#define Position_DEFAULT NULL

#define User_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   id,                1) \
X(a, STATIC,   SINGULAR, STRING,   long_name,         2) \
X(a, STATIC,   SINGULAR, STRING,   short_name,        3) \
X(a, STATIC,   SINGULAR, FIXED_LENGTH_BYTES, macaddr,           4) \
X(a, STATIC,   SINGULAR, UENUM,    hw_model,          6) \
X(a, STATIC,   SINGULAR, BOOL,     is_licensed,       7) \
X(a, STATIC,   SINGULAR, UENUM,    team,              8) \
X(a, STATIC,   SINGULAR, UINT32,   tx_power_dbm,     10) \
X(a, STATIC,   SINGULAR, UINT32,   ant_gain_dbi,     11) \
X(a, STATIC,   SINGULAR, UINT32,   ant_azimuth,      12)
#define User_CALLBACK NULL
#define User_DEFAULT NULL

#define RouteDiscovery_FIELDLIST(X, a) \
X(a, STATIC,   REPEATED, FIXED32,  route,             2)
#define RouteDiscovery_CALLBACK NULL
#define RouteDiscovery_DEFAULT NULL

#define Routing_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,route_request,route_request),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (variant,route_reply,route_reply),   2) \
X(a, STATIC,   ONEOF,    UENUM,    (variant,error_reason,error_reason),   3)
#define Routing_CALLBACK NULL
#define Routing_DEFAULT NULL
#define Routing_variant_route_request_MSGTYPE RouteDiscovery
#define Routing_variant_route_reply_MSGTYPE RouteDiscovery

#define Data_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    portnum,           1) \
X(a, STATIC,   SINGULAR, BYTES,    payload,           2) \
X(a, STATIC,   SINGULAR, BOOL,     want_response,     3) \
X(a, STATIC,   SINGULAR, FIXED32,  dest,              4) \
X(a, STATIC,   SINGULAR, FIXED32,  source,            5) \
X(a, STATIC,   SINGULAR, FIXED32,  request_id,        6)
#define Data_CALLBACK NULL
#define Data_DEFAULT NULL

#define MeshPacket_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FIXED32,  from,              1) \
X(a, STATIC,   SINGULAR, FIXED32,  to,                2) \
X(a, STATIC,   SINGULAR, UINT32,   channel,           3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,decoded,decoded),   4) \
X(a, STATIC,   ONEOF,    BYTES,    (payloadVariant,encrypted,encrypted),   5) \
X(a, STATIC,   SINGULAR, FIXED32,  id,                6) \
X(a, STATIC,   SINGULAR, FIXED32,  rx_time,           7) \
X(a, STATIC,   SINGULAR, FLOAT,    rx_snr,            8) \
X(a, STATIC,   SINGULAR, UINT32,   hop_limit,        10) \
X(a, STATIC,   SINGULAR, BOOL,     want_ack,         11) \
X(a, STATIC,   SINGULAR, UENUM,    priority,         12) \
X(a, STATIC,   SINGULAR, INT32,    rx_rssi,          13)
#define MeshPacket_CALLBACK NULL
#define MeshPacket_DEFAULT NULL
#define MeshPacket_payloadVariant_decoded_MSGTYPE Data

#define NodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   OPTIONAL, MESSAGE,  user,              2) \
X(a, STATIC,   OPTIONAL, MESSAGE,  position,          3) \
X(a, STATIC,   SINGULAR, FIXED32,  last_heard,        4) \
X(a, STATIC,   SINGULAR, FLOAT,    snr,               7)
#define NodeInfo_CALLBACK NULL
#define NodeInfo_DEFAULT NULL
#define NodeInfo_user_MSGTYPE User
#define NodeInfo_position_MSGTYPE Position

#define MyNodeInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   my_node_num,       1) \
X(a, STATIC,   SINGULAR, BOOL,     has_gps,           2) \
X(a, STATIC,   SINGULAR, UINT32,   num_bands,         3) \
X(a, STATIC,   SINGULAR, STRING,   region,            4) \
X(a, STATIC,   SINGULAR, STRING,   hw_model_deprecated,   5) \
X(a, STATIC,   SINGULAR, STRING,   firmware_version,   6) \
X(a, STATIC,   SINGULAR, UENUM,    error_code,        7) \
X(a, STATIC,   SINGULAR, UINT32,   error_address,     8) \
X(a, STATIC,   SINGULAR, UINT32,   error_count,       9) \
X(a, STATIC,   SINGULAR, UINT32,   reboot_count,     10) \
X(a, STATIC,   SINGULAR, FLOAT,    bitrate,          11) \
X(a, STATIC,   SINGULAR, UINT32,   message_timeout_msec,  13) \
X(a, STATIC,   SINGULAR, UINT32,   min_app_version,  14) \
X(a, STATIC,   SINGULAR, UINT32,   max_channels,     15) \
X(a, CALLBACK, REPEATED, UINT32,   air_period_tx,    16) \
X(a, CALLBACK, REPEATED, UINT32,   air_period_rx,    17) \
X(a, CALLBACK, REPEATED, UINT32,   air_period_tx_all,  18)
#define MyNodeInfo_CALLBACK pb_default_field_callback
#define MyNodeInfo_DEFAULT NULL

#define LogRecord_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, STRING,   message,           1) \
X(a, STATIC,   SINGULAR, FIXED32,  time,              2) \
X(a, STATIC,   SINGULAR, STRING,   source,            3) \
X(a, STATIC,   SINGULAR, UENUM,    level,             4)
#define LogRecord_CALLBACK NULL
#define LogRecord_DEFAULT NULL

#define FromRadio_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   num,               1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,my_info,my_info),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,node_info,node_info),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,log_record,log_record),   7) \
X(a, STATIC,   ONEOF,    UINT32,   (payloadVariant,config_complete_id,config_complete_id),   8) \
X(a, STATIC,   ONEOF,    BOOL,     (payloadVariant,rebooted,rebooted),   9) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,packet,packet),  11)
#define FromRadio_CALLBACK NULL
#define FromRadio_DEFAULT NULL
#define FromRadio_payloadVariant_my_info_MSGTYPE MyNodeInfo
#define FromRadio_payloadVariant_node_info_MSGTYPE NodeInfo
#define FromRadio_payloadVariant_log_record_MSGTYPE LogRecord
#define FromRadio_payloadVariant_packet_MSGTYPE MeshPacket

#define ToRadio_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,packet,packet),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payloadVariant,peer_info,peer_info),   3) \
X(a, STATIC,   ONEOF,    UINT32,   (payloadVariant,want_config_id,want_config_id), 100) \
X(a, STATIC,   ONEOF,    BOOL,     (payloadVariant,disconnect,disconnect), 104)
#define ToRadio_CALLBACK NULL
#define ToRadio_DEFAULT NULL
#define ToRadio_payloadVariant_packet_MSGTYPE MeshPacket
#define ToRadio_payloadVariant_peer_info_MSGTYPE ToRadio_PeerInfo

#define ToRadio_PeerInfo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   app_version,       1) \
X(a, STATIC,   SINGULAR, BOOL,     mqtt_gateway,      2)
#define ToRadio_PeerInfo_CALLBACK NULL
#define ToRadio_PeerInfo_DEFAULT NULL

extern const pb_msgdesc_t Position_msg;
extern const pb_msgdesc_t User_msg;
extern const pb_msgdesc_t RouteDiscovery_msg;
extern const pb_msgdesc_t Routing_msg;
extern const pb_msgdesc_t Data_msg;
extern const pb_msgdesc_t MeshPacket_msg;
extern const pb_msgdesc_t NodeInfo_msg;
extern const pb_msgdesc_t MyNodeInfo_msg;
extern const pb_msgdesc_t LogRecord_msg;
extern const pb_msgdesc_t FromRadio_msg;
extern const pb_msgdesc_t ToRadio_msg;
extern const pb_msgdesc_t ToRadio_PeerInfo_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define Position_fields &Position_msg
#define User_fields &User_msg
#define RouteDiscovery_fields &RouteDiscovery_msg
#define Routing_fields &Routing_msg
#define Data_fields &Data_msg
#define MeshPacket_fields &MeshPacket_msg
#define NodeInfo_fields &NodeInfo_msg
#define MyNodeInfo_fields &MyNodeInfo_msg
#define LogRecord_fields &LogRecord_msg
#define FromRadio_fields &FromRadio_msg
#define ToRadio_fields &ToRadio_msg
#define ToRadio_PeerInfo_fields &ToRadio_PeerInfo_msg

/* Maximum encoded size of messages (where known) */
#define Position_size                            153
#define User_size                                96
#define RouteDiscovery_size                      40
#define Routing_size                             42
#define Data_size                                260
#define MeshPacket_size                          309
#define NodeInfo_size                            270
/* MyNodeInfo_size depends on runtime parameters */
#define LogRecord_size                           81
/* FromRadio_size depends on runtime parameters */
#define ToRadio_size                             312
#define ToRadio_PeerInfo_size                    8

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
