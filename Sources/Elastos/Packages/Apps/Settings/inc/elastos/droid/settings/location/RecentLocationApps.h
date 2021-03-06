//=========================================================================
// Copyright (C) 2012 The Elastos Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//=========================================================================

#ifndef __ELASTOS_DROID_SETTINGS_LOCATION_RECENTLOCATIONAPPS_H__
#define __ELASTOS_DROID_SETTINGS_LOCATION_RECENTLOCATIONAPPS_H__

#include "elastos/droid/settings/location/DimmableIconPreference.h"
#include "elastos/droid/settings/CSettingsActivity.h"

using Elastos::Droid::Settings::CSettingsActivity;

using Elastos::Droid::App::IAppOpsManagerPackageOps;
using Elastos::Droid::Content::IContext;
using Elastos::Droid::Content::Pm::IPackageManager;
using Elastos::Droid::Graphics::Drawable::IDrawable;
using Elastos::Droid::Os::IUserManager;
using Elastos::Droid::Preference::IPreference;
using Elastos::Droid::Preference::IPreferenceOnPreferenceClickListener;
using Elastos::Droid::View::IView;
using Elastos::Utility::IList;

namespace Elastos {
namespace Droid {
namespace Settings {
namespace Location {

/**
 * Retrieves the information of applications which accessed location recently.
 */
class RecentLocationApps
    : public Object
{
public:
    /**
     * Subclass of {@link Preference} to intercept views and allow content description to be set on
     * them for accessibility purposes.
     */
    class AccessiblePreference
        : public DimmableIconPreference
    {
    public:
        TO_STRING_IMPL("RecentLocationApps::AccessiblePreference")

        AccessiblePreference();

        CARAPI constructor(
            /* [in] */ IContext* context,
            /* [in] */ ICharSequence* contentDescription);

        //@Override
        CARAPI OnBindView(
            /* [in] */ IView* view);

    public:
        AutoPtr<ICharSequence> mContentDescription;
    };

private:
    class PackageEntryClickedListener
        : public Object
        , public IPreferenceOnPreferenceClickListener
    {
    public:
        TO_STRING_IMPL("RecentLocationApps::PackageEntryClickedListener")

        CAR_INTERFACE_DECL()

        PackageEntryClickedListener(
            /* [in] */ CSettingsActivity* activity,
            /* [in] */ const String& packageName);

        //@Override
        CARAPI OnPreferenceClick(
            /* [in] */ IPreference* preference,
            /* [out] */ Boolean* result);

    private:
        AutoPtr<CSettingsActivity> mActivity;
        String mPackage;
    };

public:
    TO_STRING_IMPL("RecentLocationApps");

    RecentLocationApps(
        /* [in] */ CSettingsActivity* activity);

    ~RecentLocationApps();

    /**
     * Fills a list of applications which queried location recently within specified time.
     */
    virtual CARAPI_(AutoPtr<IList>) /*List<Preference>*/ GetAppList();

private:
    CARAPI_(AutoPtr<IPreference>) CreateRecentLocationEntry(
        /* [in] */ IDrawable* icon,
        /* [in] */ ICharSequence* label,
        /* [in] */ Boolean isHighBattery,
        /* [in] */ ICharSequence* contentDescription,
        /* [in] */ IPreferenceOnPreferenceClickListener* listener);

    /**
     * Creates a Preference entry for the given PackageOps.
     *
     * This method examines the time interval of the PackageOps first. If the PackageOps is older
     * than the designated interval, this method ignores the PackageOps object and returns NULL.
     * When the PackageOps is fresh enough, this method returns a Preference pointing to the App
     * Info page for that package.
     */
    CARAPI_(AutoPtr<IPreference>) GetPreferenceFromOps(
        /* [in] */ IUserManager* um,
        /* [in] */ Int64 now,
        /* [in] */ IAppOpsManagerPackageOps* ops);

private:
    static const String TAG;
    static const String ANDROID_SYSTEM_PACKAGE_NAME;

    static const Int32 RECENT_TIME_INTERVAL_MILLIS;

    AutoPtr<CSettingsActivity> mActivity;
    AutoPtr<IPackageManager> mPackageManager;
};

} // namespace Location
} // namespace Settings
} // namespace Droid
} // namespace Elastos

#endif //__ELASTOS_DROID_SETTINGS_LOCATION_RECENTLOCATIONAPPS_H__