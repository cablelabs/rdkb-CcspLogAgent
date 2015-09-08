/*********************************************************************************

    description:

        This is the template file of ssp_internal.h for XxxxSsp.
        Please replace "XXXX" with your own ssp name with the same up/lower cases.

    ------------------------------------------------------------------------------

    revision:

        09/08/2011    initial revision.

**********************************************************************************/

#ifndef  _SSP_INTERNAL_H_
#define  _SSP_INTERNAL_H_

#define  CCSP_COMMON_COMPONENT_HEALTH_Red                   1
#define  CCSP_COMMON_COMPONENT_HEALTH_Yellow                2
#define  CCSP_COMMON_COMPONENT_HEALTH_Green                 3

#define  CCSP_COMMON_COMPONENT_STATE_Initializing           1
#define  CCSP_COMMON_COMPONENT_STATE_Running                2
#define  CCSP_COMMON_COMPONENT_STATE_Blocked                3
#define  CCSP_COMMON_COMPONENT_STATE_Paused                 3

#define  CCSP_COMMON_COMPONENT_FREERESOURCES_PRIORITY_High  1
#define  CCSP_COMMON_COMPONENT_FREERESOURCES_PRIORITY_Low   2

#define  CCSP_COMPONENT_ID_LOGAGENT                             "com.cisco.spvtg.ccsp.logagent"
#define  CCSP_COMPONENT_NAME_LOGAGENT                           "com.cisco.spvtg.ccsp.logagent"
#define  CCSP_COMPONENT_VERSION_LOGAGENT                        1
#define  CCSP_COMPONENT_PATH_LOGAGENT                           "/com/cisco/spvtg/ccsp/logagent"

#define  MESSAGE_BUS_CONFIG_FILE                            "msg_daemon.cfg"

typedef  struct
_COMPONENT_COMMON_LOGAGENT
{
    char*                           Name;
    ULONG                           Version;
    char*                           Author;
    ULONG                           Health;
    ULONG                           State;

    BOOL                            LogEnable;
    ULONG                           LogLevel;

    ULONG                           MemMaxUsage;
    ULONG                           MemMinUsage;
    ULONG                           MemConsumed;
}
COMPONENT_COMMON_LOGAGENT,  *PCOMPONENT_COMMON_LOGAGENT;

#define ComponentCommonDmInit(component_com_logagent)                                          \
        {                                                                                  \
            AnscZeroMemory(component_com_logagent, sizeof(COMPONENT_COMMON_LOGAGENT));             \
            component_com_logagent->Name        = NULL;                                        \
            component_com_logagent->Version     = 1;                                           \
            component_com_logagent->Author      = NULL;                                        \
            component_com_logagent->Health      = CCSP_COMMON_COMPONENT_HEALTH_Red;            \
            component_com_logagent->State       = CCSP_COMMON_COMPONENT_STATE_Running;         \
            if(g_iTraceLevel >= CCSP_TRACE_LEVEL_EMERGENCY)                                \
                component_com_logagent->LogLevel = (ULONG) g_iTraceLevel;                      \
            component_com_logagent->LogEnable   = TRUE;                                        \
            component_com_logagent->MemMaxUsage = 0;                                           \
            component_com_logagent->MemMinUsage = 0;                                           \
            component_com_logagent->MemConsumed = 0;                                           \
        }


#define  ComponentCommonDmClean(component_com_logagent)                                        \
         {                                                                                  \
            if ( component_com_logagent->Name )                                                \
            {                                                                               \
                AnscFreeMemory(component_com_logagent->Name);                                  \
            }                                                                               \
                                                                                            \
            if ( component_com_logagent->Author )                                              \
            {                                                                               \
                AnscFreeMemory(component_com_logagent->Author);                                \
            }                                                                               \
         }


#define  ComponentCommonDmFree(component_com_logagent)                                         \
         {                                                                                  \
            ComponentCommonDmClean(component_com_logagent);                                    \
            AnscFreeMemory(component_com_logagent);                                            \
         }

int  cmd_dispatch(int  command);


ANSC_STATUS
ssp_create
(
);

ANSC_STATUS
ssp_engage
(
);

ANSC_STATUS
ssp_cancel
(
);



char*
ssp_CcdIfGetComponentName
    (
        ANSC_HANDLE                     hThisObject
    );

ULONG
ssp_CcdIfGetComponentVersion
    (
        ANSC_HANDLE                     hThisObject
    );

char*
ssp_CcdIfGetComponentAuthor
    (
        ANSC_HANDLE                     hThisObject
    );

ULONG
ssp_CcdIfGetComponentHealth
    (
        ANSC_HANDLE                     hThisObject
    );

ULONG
ssp_CcdIfGetComponentState
    (
        ANSC_HANDLE                     hThisObject
    );

BOOL
ssp_CcdIfGetLoggingEnabled
    (
        ANSC_HANDLE                     hThisObject
    );

ANSC_STATUS
ssp_CcdIfSetLoggingEnabled
    (
        ANSC_HANDLE                     hThisObject,
        BOOL                            bEnabled
    );

ULONG
ssp_CcdIfGetLoggingLevel
    (
        ANSC_HANDLE                     hThisObject
    );

ANSC_STATUS
ssp_CcdIfSetLoggingLevel
    (
        ANSC_HANDLE                     hThisObject,
        ULONG                           LogLevel
    );

ULONG
ssp_CcdIfGetMemMaxUsage
    (
        ANSC_HANDLE                     hThisObject
    );

ULONG
ssp_CcdIfGetMemMinUsage
    (
        ANSC_HANDLE                     hThisObject
    );

ULONG
ssp_CcdIfGetMemConsumed
    (
        ANSC_HANDLE                     hThisObject
    );

ANSC_STATUS
ssp_CcdIfApplyChanges
    (
        ANSC_HANDLE                     hThisObject
    );


#endif