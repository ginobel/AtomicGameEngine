// Copyright (c) 2014-2015, THUNDERBEAST GAMES LLC All rights reserved
// Please see LICENSE.md in repository root for license information
// https://github.com/AtomicGameEngine/AtomicGameEngine

#pragma once

#include <Atomic/Core/Object.h>
#include "BuildSettings.h"
#include "BuildBase.h"

#include "../Platform/Platform.h"

using namespace Atomic;

namespace ToolCore
{

class BuildSystem : public Object
{
    OBJECT(BuildSystem);

public:
    /// Construct.
    BuildSystem(Context* context);
    /// Destruct.
    virtual ~BuildSystem();

    BuildSettings* GetBuildSettings() { return buildSettings_; }

    void LoadBuildSettings(rapidjson::Value::Member* jobject);
    void SaveBuildSettings(rapidjson::PrettyWriter<rapidjson::FileStream>& writer);

    void ClearBuildCompleteUI();
    void BuildComplete(PlatformID platform, const String& buildFolder, bool success = true, bool fail3D = false);

private:

    void DoBuildWeb(const String& buildPath);

    SharedPtr<BuildSettings> buildSettings_;
    SharedPtr<BuildBase> currentBuild_;

    void HandleEditorBuild(StringHash eventType, VariantMap& eventData);
    void HandleEditorShutdown(StringHash eventType, VariantMap& eventData);
};


}
