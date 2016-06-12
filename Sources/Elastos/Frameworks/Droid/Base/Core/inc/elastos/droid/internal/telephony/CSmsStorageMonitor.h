
#ifndef __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMSSTORAGEMONITOR_H__
#define __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMSSTORAGEMONITOR_H__

#include "_Elastos_Droid_Internal_Telephony_CSmsStorageMonitor.h"
#include "elastos/droid/internal/telephony/SmsStorageMonitor.h"

namespace Elastos {
namespace Droid {
namespace Internal {
namespace Telephony {

CarClass(CSmsStorageMonitor), public SmsStorageMonitor
{
public:
    CAR_OBJECT_DECL()
};

} // namespace Telephony
} // namespace Internal
} // namespace Droid
} // namespace Elastos

#endif // __ELASTOS_DROID_INTERNAL_TELEPHONY_CSMSSTORAGEMONITOR_H__