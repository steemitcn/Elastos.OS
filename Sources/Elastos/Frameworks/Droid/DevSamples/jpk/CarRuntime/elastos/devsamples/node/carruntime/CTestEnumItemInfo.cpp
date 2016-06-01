
#include "CTestEnumItemInfo.h"

namespace Elastos {
namespace DevSamples {
namespace Node {
namespace CarRuntime {

CAR_INTERFACE_IMPL_2(CTestEnumItemInfo, Object, ITestDataTypeInfo, ITestEnumItemInfo)

CAR_OBJECT_IMPL(CTestEnumItemInfo)

ECode CTestEnumItemInfo::GetName(
    /* [out] */ String * pName)
{
    return mEnumItemInfo->GetName(pName);
}

ECode CTestEnumItemInfo::GetEnumInfo(
    /* [out] */ ITestEnumInfo ** ppEnumInfo)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestEnumItemInfo::GetValue(
    /* [out] */ Int32 * pValue)
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestEnumItemInfo::constructor()
{
    // TODO: Add your code here
    return E_NOT_IMPLEMENTED;
}

ECode CTestEnumItemInfo::constructor(
    /* [in] */ IEnumItemInfo * pEnumItemInfo)
{
    mEnumItemInfo = pEnumItemInfo;
    return NOERROR;
}

}
}
}
}

